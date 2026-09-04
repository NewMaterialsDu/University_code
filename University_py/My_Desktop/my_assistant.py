import json
import webbrowser
import os
import subprocess
import platform
import difflib
import string
import requests
import re
import time
from openai import OpenAI
from urllib.parse import quote

# ========== 配置区 ==========
API_KEY = "sk-8300e58cd16b4f678b82bb944c3640c9"  # 替换成你的
BASE_URL = "https://api.deepseek.com"

client = OpenAI(
    api_key=API_KEY,
    base_url=BASE_URL
)

# ========== 系统提示词 ==========
SYSTEM_PROMPT = """你是一个高效的电脑助手。请遵守以下规则：
1. 回答要极度简洁，一句话以内，不要说废话
2. 执行命令后直接说"好的"或"已完成"，不要解释过程
3. 如果用户只是问问题，直接给答案，不要加废话
4. 退出时只说"再见"
"""

# ========== 软件别名映射 ==========
ALIAS_MAP = {
    "酷狗": "酷狗音乐",
    "任务管理器": "taskmgr.exe",
    "控制面板": "control.exe",
    "注册表": "regedit.exe",
    "设备管理器": "devmgmt.msc",
    "磁盘管理": "diskmgmt.msc",
    "命令提示符": "cmd.exe",
    "记事本": "notepad.exe",
    "画图": "mspaint.exe",
    "计算器": "calc.exe"
}

# ========== 常用软件映射 ==========
COMMON_SOFTWARE = {
    "微信": ["WeChat.exe", "wechat.exe"],
    "QQ": ["QQ.exe", "QQScLauncher.exe"],
    "酷狗": ["KuGou.exe", "kugou.exe"],
    "酷狗音乐": ["KuGou.exe", "kugou.exe"],
    "网易云": ["cloudmusic.exe", "NeteaseCloudMusic.exe"],
    "Chrome": ["chrome.exe"],
    "Edge": ["msedge.exe"],
    "Photoshop": ["Photoshop.exe"],
    "任务管理器": ["taskmgr.exe"],
    "控制面板": ["control.exe"],
    "计算器": ["calc.exe"],
    "记事本": ["notepad.exe"],
    "画图": ["mspaint.exe"],
    "命令提示符": ["cmd.exe"],
    "PowerShell": ["powershell.exe"],
    "资源管理器": ["explorer.exe"],
    "设置": ["ms-settings:"]
}

# ========== 音量控制（使用模拟按键，稳定可靠） ==========

def send_volume_key(key_code):
    """发送音量按键"""
    try:
        subprocess.run(['powershell', '-Command', 
                       f'(New-Object -ComObject WScript.Shell).SendKeys([char]{key_code})'], 
                       capture_output=True, timeout=1)
        return True
    except:
        return False

def set_volume(level):
    """设置系统音量（0-100）"""
    try:
        level = max(0, min(100, level))
        
        # 先降到最低（发送50次音量-）
        for _ in range(50):
            send_volume_key(174)  # 音量-键代码
            time.sleep(0.01)
        
        # 再升到目标（每按一次大约增加2%音量）
        for _ in range(level // 2):
            send_volume_key(175)  # 音量+键代码
            time.sleep(0.01)
        
        return True
    except:
        return False

def volume_up(delta=10):
    """增加音量"""
    try:
        for _ in range(delta // 2):
            send_volume_key(175)
            time.sleep(0.01)
        return f"音量已增加 {delta}%"
    except:
        return "音量增加失败"

def volume_down(delta=10):
    """降低音量"""
    try:
        for _ in range(delta // 2):
            send_volume_key(174)
            time.sleep(0.01)
        return f"音量已降低 {delta}%"
    except:
        return "音量降低失败"

def volume_mute():
    """静音/取消静音"""
    try:
        send_volume_key(173)  # 静音键代码
        return "已切换静音"
    except:
        return "静音切换失败"

def get_volume():
    """获取当前音量（估算）"""
    # 由于模拟按键无法精确获取音量，返回默认值
    # 实际使用时，音量调节是相对的
    return 50

# ========== 辅助函数 ==========

def get_all_drives():
    """获取所有可用盘符"""
    drives = []
    for letter in string.ascii_uppercase:
        drive = f"{letter}:\\"
        if os.path.exists(drive):
            drives.append(drive)
    return drives

def find_executable_path(app_name):
    """智能搜索可执行文件路径"""
    # 1. 检查 PATH
    try:
        result = subprocess.run(['where', app_name], capture_output=True, text=True, timeout=2)
        if result.returncode == 0:
            return result.stdout.strip().split('\n')[0]
    except:
        pass

    # 2. 获取所有盘符
    drives = get_all_drives()

    # 3. 常见安装目录
    common_dirs = [
        "Program Files", "Program Files (x86)",
        "Programs", "Program Files\\WindowsApps",
        "Users\\%USERNAME%\\AppData\\Local\\Programs",
        "Users\\%USERNAME%\\AppData\\Local\\Microsoft\\WindowsApps"
    ]
    common_dirs = [os.path.expandvars(d) for d in common_dirs]
    
    # 系统目录
    system_dirs = ["C:\\Windows\\System32", "C:\\Windows"]
    search_dirs = system_dirs.copy()
    
    for drive in drives:
        for common_dir in common_dirs:
            full_dir = os.path.join(drive, common_dir)
            if os.path.exists(full_dir):
                search_dirs.append(full_dir)
        user_custom = ["Software", "Tools", "Apps", "Programs"]
        for custom in user_custom:
            custom_dir = os.path.join(drive, custom)
            if os.path.exists(custom_dir):
                search_dirs.append(custom_dir)

    # 4. 遍历搜索
    candidates = []
    for search_dir in search_dirs:
        try:
            for root, dirs, files in os.walk(search_dir):
                if root.count(os.sep) - search_dir.count(os.sep) > 3:
                    continue
                for file in files:
                    if file.endswith('.exe') or file.endswith('.lnk'):
                        name_lower = os.path.splitext(file)[0].lower()
                        candidates.append((name_lower, os.path.join(root, file)))
                if len(candidates) > 500:
                    break
        except:
            continue

    # 5. 匹配
    app_name_lower = app_name.lower()
    
    # 精确匹配
    exact_matches = [path for name, path in candidates if name == app_name_lower]
    if exact_matches:
        return exact_matches[0]
    
    # 包含匹配
    contains_matches = [path for name, path in candidates if app_name_lower in name]
    if contains_matches:
        return contains_matches[0]
    
    # 模糊匹配
    candidate_names = [name for name, _ in candidates]
    matches = difflib.get_close_matches(app_name_lower, candidate_names, n=1, cutoff=0.5)
    if matches:
        for name, path in candidates:
            if name == matches[0]:
                return path
    
    return None

def search_online_for_program(program_name):
    """通过网络搜索获取程序的可执行文件名"""
    try:
        all_hints = []
        
        # 检查常用软件映射
        for key, values in COMMON_SOFTWARE.items():
            if program_name in key or key in program_name:
                all_hints.extend(values)
        
        # 百度搜索
        search_queries = [
            f"{program_name} 可执行文件",
            f"{program_name} exe 文件名"
        ]
        
        for query in search_queries:
            url = f"https://www.baidu.com/s?wd={quote(query)}"
            headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'}
            try:
                response = requests.get(url, headers=headers, timeout=5)
                if response.status_code == 200:
                    # 提取 .exe 文件名
                    exe_pattern = r'([a-zA-Z0-9_\u4e00-\u9fa5]+\.exe)'
                    matches = re.findall(exe_pattern, response.text)
                    all_hints.extend(matches)
            except:
                pass
        
        if all_hints:
            all_hints = list(set(all_hints))
            all_hints.sort(key=len)
            return all_hints[:5]
            
    except Exception as e:
        pass
    
    return None

def open_app_windows(app_name):
    """打开应用（增强版）"""
    original_name = app_name
    
    # 1. 别名映射
    app_name = ALIAS_MAP.get(app_name, app_name)
    
    # 2. 检查常用软件映射
    for key, values in COMMON_SOFTWARE.items():
        if original_name in key or key in original_name:
            for value in values:
                exe_path = find_executable_path(value)
                if exe_path:
                    try:
                        os.startfile(exe_path)
                        return "✅"
                    except:
                        pass
    
    # 3. 优先搜索桌面快捷方式
    desktop = os.path.join(os.path.expanduser("~"), "Desktop")
    if os.path.exists(desktop):
        try:
            for file in os.listdir(desktop):
                if file.endswith('.lnk'):
                    shortcut_name = os.path.splitext(file)[0]
                    if shortcut_name.lower() == app_name.lower() or original_name.lower() in shortcut_name.lower():
                        shortcut_path = os.path.join(desktop, file)
                        os.startfile(shortcut_path)
                        return "✅"
        except:
            pass
    
    # 4. 开始菜单快捷方式
    start_menu = os.path.join(os.path.expanduser("~"), "AppData", "Roaming", "Microsoft", "Windows", "Start Menu", "Programs")
    if os.path.exists(start_menu):
        try:
            for root, dirs, files in os.walk(start_menu):
                for file in files:
                    if file.endswith('.lnk'):
                        shortcut_name = os.path.splitext(file)[0]
                        if shortcut_name.lower() == app_name.lower() or original_name.lower() in shortcut_name.lower():
                            shortcut_path = os.path.join(root, file)
                            os.startfile(shortcut_path)
                            return "✅"
        except:
            pass
    
    # 5. 本地智能搜索
    exe_path = find_executable_path(app_name)
    if exe_path:
        try:
            os.startfile(exe_path)
            return "✅"
        except Exception as e:
            pass
    
    # 6. 网络搜索辅助
    online_hints = search_online_for_program(original_name)
    if online_hints:
        for hint in online_hints:
            exe_path = find_executable_path(hint)
            if exe_path:
                try:
                    os.startfile(exe_path)
                    return "✅"
                except:
                    pass
    
    return f"❌ 未找到程序：{original_name}"

# ========== 工具函数 ==========

def open_website(url):
    webbrowser.open(url)
    return "✅"

def calculate(expression):
    try:
        result = eval(expression)
        return str(result)
    except:
        return "❌"

def open_app(app_name):
    return open_app_windows(app_name)

def create_file(filename, content="", location="桌面"):
    if location == "桌面":
        base = os.path.join(os.path.expanduser("~"), "Desktop")
    elif location == "当前目录":
        base = os.getcwd()
    else:
        base = location
    filepath = os.path.join(base, filename)
    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        return "✅"
    except Exception as e:
        return f"❌ {e}"

def create_folder(folder_name, location="桌面"):
    if location == "桌面":
        base = os.path.join(os.path.expanduser("~"), "Desktop")
    elif location == "当前目录":
        base = os.getcwd()
    else:
        base = location
    folder_path = os.path.join(base, folder_name)
    try:
        os.makedirs(folder_path, exist_ok=True)
        return "✅"
    except Exception as e:
        return f"❌ {e}"

def open_folder(folder_path):
    if not os.path.exists(folder_path):
        desktop = os.path.join(os.path.expanduser("~"), "Desktop")
        test_path = os.path.join(desktop, folder_path)
        if os.path.exists(test_path):
            folder_path = test_path
        else:
            test_path = os.path.join(os.getcwd(), folder_path)
            if os.path.exists(test_path):
                folder_path = test_path
            else:
                return "❌ 路径不存在"
    try:
        os.startfile(folder_path)
        return "✅"
    except Exception as e:
        return f"❌ {e}"

def search_files(keyword, location="桌面"):
    if location == "桌面":
        base = os.path.join(os.path.expanduser("~"), "Desktop")
    elif location == "当前目录":
        base = os.getcwd()
    else:
        base = location
    
    results = []
    for root, dirs, files in os.walk(base):
        depth = root.replace(base, '').count(os.sep)
        if depth > 3:
            continue
        for item in files + dirs:
            if keyword.lower() in item.lower():
                results.append(os.path.join(root, item))
                if len(results) >= 10:
                    break
        if len(results) >= 10:
            break
    
    if results:
        return "\n".join(results)
    else:
        return "未找到"

def system_command(command):
    """执行系统命令"""
    # 处理音量相关命令
    if command == "volume_up":
        return volume_up()
    elif command == "volume_down":
        return volume_down()
    elif command == "volume_mute":
        return volume_mute()
    elif command == "volume_unmute":
        return volume_mute()  # 静音键是切换功能
    elif command.startswith("volume_set_"):
        try:
            level = int(command.split('_')[-1])
            set_volume(level)
            return f"音量已设为 {level}%"
        except:
            return "音量设置失败"
    else:
        # 其他系统命令
        commands = {
            "lock": "rundll32.exe user32.dll,LockWorkStation"
        }
        if command in commands:
            try:
                os.system(commands[command])
                return "✅"
            except:
                return "❌"
        else:
            return "不支持的命令"

def exit_conversation(reason):
    return "再见"

# ========== 工具定义 ==========
tools = [
    {
        "type": "function",
        "function": {
            "name": "open_website",
            "description": "打开指定的网站",
            "parameters": {"type": "object", "properties": {"url": {"type": "string"}}, "required": ["url"]}
        }
    },
    {
        "type": "function",
        "function": {
            "name": "calculate",
            "description": "执行数学计算",
            "parameters": {"type": "object", "properties": {"expression": {"type": "string"}}, "required": ["expression"]}
        }
    },
    {
        "type": "function",
        "function": {
            "name": "open_app",
            "description": "打开电脑上的应用程序（支持别名、系统工具、网络辅助）",
            "parameters": {"type": "object", "properties": {"app_name": {"type": "string"}}, "required": ["app_name"]}
        }
    },
    {
        "type": "function",
        "function": {
            "name": "create_file",
            "description": "创建文件",
            "parameters": {
                "type": "object",
                "properties": {
                    "filename": {"type": "string"},
                    "content": {"type": "string"},
                    "location": {"type": "string", "enum": ["桌面", "当前目录"], "default": "桌面"}
                },
                "required": ["filename"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "create_folder",
            "description": "创建文件夹",
            "parameters": {
                "type": "object",
                "properties": {
                    "folder_name": {"type": "string"},
                    "location": {"type": "string", "enum": ["桌面", "当前目录"], "default": "桌面"}
                },
                "required": ["folder_name"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "open_folder",
            "description": "用资源管理器打开文件夹",
            "parameters": {"type": "object", "properties": {"folder_path": {"type": "string"}}, "required": ["folder_path"]}
        }
    },
    {
        "type": "function",
        "function": {
            "name": "search_files",
            "description": "搜索文件或文件夹",
            "parameters": {
                "type": "object",
                "properties": {
                    "keyword": {"type": "string"},
                    "location": {"type": "string", "enum": ["桌面", "当前目录"], "default": "桌面"}
                },
                "required": ["keyword"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "system_command",
            "description": "执行系统命令，包括音量控制（volume_up, volume_down, volume_mute, volume_set_数字）和锁屏（lock）",
            "parameters": {"type": "object", "properties": {"command": {"type": "string"}}, "required": ["command"]}
        }
    },
    {
        "type": "function",
        "function": {
            "name": "exit_conversation",
            "description": "退出对话",
            "parameters": {"type": "object", "properties": {"reason": {"type": "string"}}, "required": ["reason"]}
        }
    }
]

available_functions = {
    "open_website": open_website,
    "calculate": calculate,
    "open_app": open_app,
    "create_file": create_file,
    "create_folder": create_folder,
    "open_folder": open_folder,
    "search_files": search_files,
    "system_command": system_command,
    "exit_conversation": exit_conversation
}

# ========== 主函数 ==========
def main():
    print("\n" + "=" * 50)
    print("🤖 AI电脑助手 v2.0")
    print("=" * 50)
    print("\n支持功能：")
    print("  🌐 打开网站：打开百度、打开淘宝")
    print("  📱 打开软件：打开微信、打开QQ、打开计算器")
    print("  🔧 系统工具：打开任务管理器、打开控制面板")
    print("  🔢 数学计算：计算 25*4、123+456 等于多少")
    print("  📁 文件操作：在桌面创建 笔记.txt、创建 学习资料 文件夹")
    print("  🔍 搜索文件：搜索 Python 文件")
    print("  🔊 音量控制：音量调到50、增大音量、静音")
    print("  🔒 系统命令：锁屏")
    print("  👋 退出：再见、退出\n")
    print("-" * 50)
    
    messages = [{"role": "system", "content": SYSTEM_PROMPT}]
    should_exit = False
    
    while not should_exit:
        try:
            user_input = input("\n你：").strip()
            if not user_input:
                continue
                
            if user_input.lower() == 'exit':
                print("再见")
                break
            
            messages.append({"role": "user", "content": user_input})
            
            response = client.chat.completions.create(
                model="deepseek-chat",
                messages=messages,
                tools=tools,
                tool_choice="auto",
                temperature=0.3,
                timeout=30
            )
            
            assistant = response.choices[0].message
            messages.append(assistant)
            
            if assistant.tool_calls:
                for tool_call in assistant.tool_calls:
                    func_name = tool_call.function.name
                    arguments = json.loads(tool_call.function.arguments)
                    
                    if func_name == "exit_conversation":
                        print("再见")
                        should_exit = True
                        break
                    
                    if func_name in available_functions:
                        result = available_functions[func_name](**arguments)
                        if result and result != "✅":
                            print(f"→ {result}")
                        elif result == "✅":
                            print("→ 完成")
                        
                        messages.append({
                            "role": "tool",
                            "tool_call_id": tool_call.id,
                            "content": result
                        })
                
                if not should_exit and assistant.tool_calls:
                    final_response = client.chat.completions.create(
                        model="deepseek-chat",
                        messages=messages,
                        temperature=0.3,
                        timeout=30
                    )
                    ai_reply = final_response.choices[0].message.content
                    if ai_reply and ai_reply not in ["✅", "好的", "完成"]:
                        print(f"{ai_reply}")
                    messages.append({"role": "assistant", "content": ai_reply})
            else:
                print(f"{assistant.content}")
                
        except KeyboardInterrupt:
            print("\n再见")
            break
        except Exception as e:
            print(f"错误：{e}")
            continue

if __name__ == "__main__":
    main()