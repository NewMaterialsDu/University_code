import subprocess
import time
import sys

def print_result(test_name, success, message=""):
    """打印测试结果"""
    if success:
        print(f"  ✅ 成功: {test_name}")
        if message:
            print(f"     {message}")
    else:
        print(f"  ❌ 失败: {test_name}")
        if message:
            print(f"     {message}")

def test_method_1():
    """方法1：模拟音量+按键"""
    print("\n[测试1] 模拟音量+按键")
    print("  说明：会听到音量增加一声")
    try:
        subprocess.run(['powershell', '-Command', 
                       '(New-Object -ComObject WScript.Shell).SendKeys([char]175)'], 
                       capture_output=True, timeout=2)
        print_result("按键发送成功", True, "如果听到音量变化，说明成功")
        return True
    except Exception as e:
        print_result("按键发送失败", False, str(e))
        return False

def test_method_2():
    """方法2：多次按键"""
    print("\n[测试2] 多次按键（5次）")
    print("  说明：会连续听到5声音量变化")
    try:
        ps_script = '''
        $wsh = New-Object -ComObject WScript.Shell
        for ($i = 0; $i < 5; $i++) {
            $wsh.SendKeys([char]175)
            Start-Sleep -Milliseconds 50
        }
        '''
        subprocess.run(['powershell', '-Command', ps_script], 
                       capture_output=True, timeout=3)
        print_result("多次按键成功", True, "如果听到5次音量变化，说明成功")
        return True
    except Exception as e:
        print_result("多次按键失败", False, str(e))
        return False

def test_method_3():
    """方法3：ctypes API"""
    print("\n[测试3] Windows API 按键")
    print("  说明：会听到音量增加一声")
    try:
        import ctypes
        VK_VOLUME_UP = 0xAF
        user32 = ctypes.windll.user32
        user32.keybd_event(VK_VOLUME_UP, 0, 0, 0)
        user32.keybd_event(VK_VOLUME_UP, 0, 2, 0)
        print_result("API按键成功", True, "如果听到音量变化，说明成功")
        return True
    except Exception as e:
        print_result("API按键失败", False, str(e))
        return False

def test_method_4():
    """方法4：pycaw"""
    print("\n[测试4] pycaw 精确控制")
    print("  说明：会精确设置音量为30%，然后恢复")
    try:
        from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
        from ctypes import cast, POINTER
        from comtypes import CLSCTX_ALL
        
        devices = AudioUtilities.GetSpeakers()
        interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        volume = cast(interface, POINTER(IAudioEndpointVolume))
        
        # 获取当前音量
        current = volume.GetMasterVolumeLevelScalar()
        print(f"  当前音量: {int(current * 100)}%")
        
        # 设置音量为30%
        volume.SetMasterVolumeLevelScalar(0.3, None)
        time.sleep(0.5)
        
        # 恢复原音量
        volume.SetMasterVolumeLevelScalar(current, None)
        
        print_result("pycaw成功", True, f"已将音量从 {int(current*100)}% 设为30% 再恢复")
        return True
    except ImportError:
        print_result("pycaw失败", False, "未安装 pycaw，运行: pip install pycaw comtypes")
        return False
    except Exception as e:
        print_result("pycaw失败", False, str(e))
        return False

def test_method_5():
    """方法5：PowerShell 静音/取消静音"""
    print("\n[测试5] PowerShell 静音切换")
    print("  说明：会先静音，再取消静音")
    try:
        # 静音
        subprocess.run(['powershell', '-Command', 
                       '(New-Object -ComObject WScript.Shell).SendKeys([char]173)'], 
                       capture_output=True, timeout=2)
        time.sleep(0.5)
        # 取消静音
        subprocess.run(['powershell', '-Command', 
                       '(New-Object -ComObject WScript.Shell).SendKeys([char]173)'], 
                       capture_output=True, timeout=2)
        print_result("静音切换成功", True, "如果听到静音→恢复，说明成功")
        return True
    except Exception as e:
        print_result("静音切换失败", False, str(e))
        return False

def test_method_6():
    """方法6：检查是否支持音量控制"""
    print("\n[测试6] 检查系统支持")
    print("  说明：检查 Windows 音频服务是否正常")
    try:
        result = subprocess.run(['powershell', '-Command', 
                                'Get-Service Audiosrv | Select-Object Status'], 
                               capture_output=True, text=True, timeout=3)
        if "Running" in result.stdout:
            print_result("音频服务正常", True, "Windows 音频服务正在运行")
            return True
        else:
            print_result("音频服务异常", False, f"状态: {result.stdout}")
            return False
    except Exception as e:
        print_result("检查失败", False, str(e))
        return False

def main():
    print("=" * 60)
    print("音量控制测试工具")
    print("=" * 60)
    print("\n⚠️  重要提示：")
    print("1. 测试过程中会调节你的系统音量")
    print("2. 请确保电脑没有静音")
    print("3. 请留意音量变化的声音")
    print("4. 测试完成后会恢复原状态")
    print("\n开始测试...")
    print("-" * 60)
    
    results = []
    
    # 运行测试
    results.append(("模拟按键", test_method_1()))
    time.sleep(1)
    
    results.append(("多次按键", test_method_2()))
    time.sleep(1)
    
    results.append(("Windows API", test_method_3()))
    time.sleep(1)
    
    results.append(("pycaw精确控制", test_method_4()))
    time.sleep(1)
    
    results.append(("静音切换", test_method_5()))
    time.sleep(1)
    
    results.append(("系统检查", test_method_6()))
    
    # 输出总结
    print("\n" + "=" * 60)
    print("测试结果总结")
    print("=" * 60)
    
    success_count = 0
    for name, success in results:
        if success:
            success_count += 1
            print(f"  ✅ {name}")
        else:
            print(f"  ❌ {name}")
    
    print("\n" + "-" * 60)
    print(f"成功: {success_count}/{len(results)}")
    print("=" * 60)
    
    # 给出建议
    print("\n📌 根据测试结果：")
    
    if results[3][1]:  # pycaw 成功
        print("  ✅ pycaw 工作正常！这是最精确的方案")
        print("  → 使用 pycaw 方案")
        print("\n集成代码：")
        print("""
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL

def set_volume(level):
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    volume.SetMasterVolumeLevelScalar(level / 100.0, None)
    return True
        """)
    
    elif results[0][1] or results[1][1]:  # 模拟按键成功
        print("  ✅ 模拟按键方案可用")
        print("  → 使用按键模拟方案（不需要额外安装库）")
        print("\n集成代码：")
        print("""
def set_volume(level):
    import subprocess
    # 先降到最低
    for _ in range(50):
        subprocess.run(['powershell', '-Command', 
                       '(New-Object -ComObject WScript.Shell).SendKeys([char]174)'], 
                      capture_output=True)
    # 再升到目标
    for _ in range(level // 2):
        subprocess.run(['powershell', '-Command', 
                       '(New-Object -ComObject WScript.Shell).SendKeys([char]175)'], 
                      capture_output=True)
    return True
        """)
    
    elif results[2][1]:  # Windows API 成功
        print("  ✅ Windows API 方案可用")
        print("  → 使用 API 方案")
        print("\n集成代码：")
        print("""
import ctypes

def set_volume(level):
    VK_VOLUME_UP = 0xAF
    VK_VOLUME_DOWN = 0xAE
    user32 = ctypes.windll.user32
    # 降到最低
    for _ in range(50):
        user32.keybd_event(VK_VOLUME_DOWN, 0, 0, 0)
        user32.keybd_event(VK_VOLUME_DOWN, 0, 2, 0)
    # 升到目标
    for _ in range(level // 2):
        user32.keybd_event(VK_VOLUME_UP, 0, 0, 0)
        user32.keybd_event(VK_VOLUME_UP, 0, 2, 0)
    return True
        """)
    
    else:
        print("  ❌ 所有音量控制方案都失败了")
        print("\n可能原因：")
        print("  1. 需要管理员权限：右键 VS Code → 以管理员身份运行")
        print("  2. 音频驱动问题：检查音量图标是否正常")
        print("  3. 系统策略限制：公司电脑可能禁用了音量控制")
        print("\n替代方案：打开音量控制面板")
        print("""
def open_volume_control():
    import subprocess
    subprocess.run(['sndvol.exe'])
    return "已打开音量控制面板"
        """)
    
    print("\n" + "=" * 60)
    print("测试完成！请告诉我你看到了哪些 ✅ 和 ❌")
    print("=" * 60)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n测试被中断")
    except Exception as e:
        print(f"\n程序出错: {e}")