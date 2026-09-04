try:
    a = 5
    b = 0
    print(a / b)
except ZeroDivisionError: # 这种错误类型
    print("0不能被除")
except: # 其他错误类型
    print("出错了")
