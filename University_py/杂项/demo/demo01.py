import os
import re
import sys
import time
import random
import argparse
from urllib.parse import urljoin, urlparse, quote_plus

import requests
from bs4 import BeautifulSoup


HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36"
}


def get_html(url: str, timeout: int = 15) -> str:
    response = requests.get(url, headers=HEADERS, timeout=timeout)
    response.raise_for_status()
    return response.text


def normalize_url(page_url: str, src: str) -> str:
    if not src:
        return ""
    src = src.strip()
    if src.startswith("//"):
        return "https:" + src
    if src.startswith("/"):
        return urljoin(page_url, src)
    if src.startswith("http://") or src.startswith("https://"):
        return src
    return urljoin(page_url, src)


def find_video_urls(page_url: str, html: str) -> list:
    """从页面 HTML 中提取所有可能的视频 URL（归一化为绝对 URL）。"""
    urls = set()
    soup = BeautifulSoup(html, "html.parser")

    # video 标签及其 source
    for video_tag in soup.find_all("video"):
        if video_tag.get("src"):
            urls.add(normalize_url(page_url, video_tag["src"]))
        for source_tag in video_tag.find_all("source"):
            s = source_tag.get("src") or source_tag.get("data-src")
            if s:
                urls.add(normalize_url(page_url, s))

    # 单独的 source 标签
    for source_tag in soup.find_all("source"):
        s = source_tag.get("src") or source_tag.get("data-src")
        if s:
            urls.add(normalize_url(page_url, s))

    # 常见带视频的自定义属性
    for tag in soup.find_all(attrs={"data-src": True}):
        urls.add(normalize_url(page_url, tag.get("data-src")))
    for tag in soup.find_all(attrs={"data-video": True}):
        urls.add(normalize_url(page_url, tag.get("data-video")))

    # a 标签中直接指向视频文件的链接
    for a in soup.find_all("a", href=True):
        href = a["href"]
        if re.search(r"\.(mp4|webm|m3u8|flv|ts|mov|mkv)(?:\?|$)", href, re.I):
            urls.add(normalize_url(page_url, href))

    # 全文正则查找常见视频链接
    for m in re.findall(r"https?://[^\s\"']+\.(?:mp4|webm|m3u8|flv|ts|mov|mkv)", html, re.I):
        urls.add(m)

    # 过滤并返回
    filtered = []
    for u in urls:
        if not u:
            continue
        if u.startswith("blob:") or u.startswith("javascript:"):
            continue
        if not (u.startswith("http://") or u.startswith("https://")):
            u = normalize_url(page_url, u)
        filtered.append(u)
    return filtered


def download_video(video_url: str, output_path: str) -> None:
    try:
        response = requests.get(video_url, headers=HEADERS, stream=True, timeout=20)
        response.raise_for_status()
    except Exception as e:
        print(f"下载请求失败: {video_url} -> {e}")
        return

    total = response.headers.get("Content-Length")
    total = int(total) if total and total.isdigit() else None

    try:
        with open(output_path, "wb") as f:
            downloaded = 0
            for chunk in response.iter_content(chunk_size=8192):
                if not chunk:
                    continue
                f.write(chunk)
                downloaded += len(chunk)
                if total:
                    percent = downloaded * 100 / total
                    print(f"下载进度: {percent:.1f}% ({downloaded}/{total} bytes)", end="\r")
        print(f"\n下载完成: {output_path}")
    except Exception as e:
        print(f"写入文件失败: {output_path} -> {e}")


def guess_filename(video_url: str) -> str:
    path = urlparse(video_url).path
    name = os.path.basename(path)
    if not name:
        return "downloaded_video.mp4"
    return name


def is_video_url(url: str) -> bool:
    return bool(re.search(r"\.(mp4|webm|mov|mkv|flv|ts)(?:\?|$)", url, re.I))


def make_unique_path(base_dir: str, filename: str) -> str:
    path = os.path.join(base_dir, filename)
    if not os.path.exists(path):
        return path
    name, ext = os.path.splitext(filename)
    i = 1
    while True:
        newname = f"{name}({i}){ext}"
        newpath = os.path.join(base_dir, newname)
        if not os.path.exists(newpath):
            return newpath
        i += 1


def main() -> None:
    parser = argparse.ArgumentParser(description="按关键词爬取网页视频并下载到 exe 所在目录")
    parser.add_argument("--keyword", "-k", help="搜索关键词（如果提供则按关键词搜索）")
    parser.add_argument("--url", "-u", help="直接下载指定网页或视频 URL")
    parser.add_argument("--pages", "-p", type=int, default=1, help="搜索页数（每页约 10 条结果）")
    parser.add_argument("--max", "-m", type=int, default=0, help="最多下载视频数，0 表示无限制")
    args = parser.parse_args()

    if getattr(sys, "frozen", False):
        base_dir = os.path.dirname(sys.executable)
    else:
        base_dir = os.path.dirname(os.path.abspath(__file__))

    targets = []
    if args.url:
        targets = [args.url.strip()]
    elif args.keyword:
        keyword = args.keyword.strip()
        if not keyword:
            print("关键词为空，退出。")
            return
        print(f"按关键词搜索: {keyword}，页数: {args.pages}")
        # 从搜索结果页收集候选页面（和可能的直接视频链接）
        candidates = []
        seen = set()
        for p in range(1, max(1, args.pages) + 1):
            first = 1 + (p - 1) * 10
            search_url = f"https://www.bing.com/search?q={quote_plus(keyword)}&first={first}"
            try:
                search_html = get_html(search_url)
            except Exception as e:
                print(f"无法获取搜索页 {search_url} -> {e}")
                continue

            # 如果搜索页本身包含视频链接，先收集
            for v in find_video_urls(search_url, search_html):
                if v not in seen:
                    candidates.append(v)
                    seen.add(v)

            soup = BeautifulSoup(search_html, "html.parser")
            for li in soup.find_all("li", {"class": "b_algo"}):
                a = li.find("a")
                if a and a.get("href"):
                    href = a.get("href")
                    if href not in seen:
                        candidates.append(href)
                        seen.add(href)

            time.sleep(random.uniform(1.0, 1.5))

        targets = candidates
    else:
        # 交互模式：选择关键词或 URL
        mode = input("选择模式：1 搜索关键词 2 指定 URL（默认1）: ").strip() or "1"
        if mode == "2":
            u = input("请输入网页或视频 URL: ").strip()
            if not u:
                print("没有输入 URL，退出。")
                return
            targets = [u]
        else:
            kw = input("请输入搜索关键词: ").strip()
            pages = input("要搜索多少页 (默认1): ").strip()
            pages = int(pages) if pages.isdigit() and int(pages) > 0 else 1
            print(f"按关键词搜索: {kw}，页数: {pages}")
            candidates = []
            seen = set()
            for p in range(1, pages + 1):
                first = 1 + (p - 1) * 10
                search_url = f"https://www.bing.com/search?q={quote_plus(kw)}&first={first}"
                try:
                    search_html = get_html(search_url)
                except Exception as e:
                    print(f"无法获取搜索页 {search_url} -> {e}")
                    continue
                for v in find_video_urls(search_url, search_html):
                    if v not in seen:
                        candidates.append(v)
                        seen.add(v)
                soup = BeautifulSoup(search_html, "html.parser")
                for li in soup.find_all("li", {"class": "b_algo"}):
                    a = li.find("a")
                    if a and a.get("href") and a.get("href") not in seen:
                        candidates.append(a.get("href"))
                        seen.add(a.get("href"))
                time.sleep(random.uniform(1.0, 1.5))
            targets = candidates

    if not targets:
        print("未找到任何候选页面或链接。")
        return

    max_downloads = args.max
    downloaded_count = 0

    for target in targets:
        if max_downloads and downloaded_count >= max_downloads:
            break

        # 如果 target 看起来像直接的视频链接，则直接下载
        if is_video_url(target):
            video_urls = [target]
        else:
            try:
                html = get_html(target)
            except Exception as e:
                print(f"无法下载页面 {target} -> {e}")
                continue
            video_urls = find_video_urls(target, html)

        if not video_urls:
            print(f"未在页面中找到视频: {target}")
            continue

        for v in video_urls:
            if max_downloads and downloaded_count >= max_downloads:
                break
            if v.lower().endswith(".m3u8"):
                print(f"发现 m3u8 播放列表（暂不支持自动合并）：{v}，建议使用 ffmpeg 或 yt-dlp 下载")
                continue

            print(f"准备下载: {v}")
            filename = guess_filename(v)
            outpath = make_unique_path(base_dir, filename)
            download_video(v, outpath)
            downloaded_count += 1
            time.sleep(random.uniform(0.5, 1.2))

    print(f"任务完成，共下载 {downloaded_count} 个视频，保存在: {base_dir}")


if __name__ == "__main__":
    main()





