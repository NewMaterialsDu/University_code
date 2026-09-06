# 简单网页视频下载器（可打包为 exe）

说明：该脚本会提示输入网页或视频 URL，把视频下载到 exe（或脚本）所在的文件夹。

快速开始：

1. 进入 `demo` 目录：

```powershell
cd e:\\University_code\\University_py\\demo
```

2. 安装运行时依赖：

```powershell
pip install -r requirements.txt
```

3. 安装打包工具并生成 exe（可选，生成在 `dist` 目录）：

```powershell
pip install pyinstaller
pyinstaller --onefile demo01.py
```

4. 打包完成后：

- 可执行文件位于 `dist\demo01.exe`。将 exe 拷贝到目标文件夹并运行。
- 运行时会提示输入要下载的视频页面或视频 URL，文件会保存在 exe 所在文件夹。

示例用法：

```powershell
.\dist\demo01.exe
# 然后在提示中粘贴 URL 并回车
```

注意：

- 对于复杂或受保护的视频站（如 YouTube、Bilibili），本脚本可能无效，建议使用 `yt-dlp`。
- 请确保遵守版权和网站服务条款。

按关键词批量搜索并下载（新增）:

- 脚本支持按关键词搜索并从搜索结果页抓取页面，再在这些页面中查找视频链接并下载。
- 推荐使用 `--keyword`/`-k` 指定关键词，`--pages`/`-p` 指定搜索页数，`--max`/`-m` 指定最多下载的视频数量。

示例（在 `demo` 目录运行）：

```powershell
# 按关键词搜索 1 页结果并下载最多 3 个视频
e:/University_code/University_py/.venv/Scripts/python.exe demo01.py --keyword "Big Buck Bunny" --pages 1 --max 3

# 或者对打包后的 exe：
.\dist\demo01.exe --keyword "Big Buck Bunny" --pages 1 --max 3
```

本地测试：

- 我已添加一个本地测试目录 `demo/test_site`，包含 `test.html`（含 `<video>` 标签）和 `sample.mp4`，用于开发与离线验证。

