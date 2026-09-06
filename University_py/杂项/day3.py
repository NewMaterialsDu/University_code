print("=====时间问候程序=====")
time = float(input("当前时间（小时.分钟） : "))
if time < 0 or time > 24:
    print("错误，请输入二十四小时时间制")
elif time >= 5.0 and time < 12.0:
    print("早上好！")
elif time >= 12.0 and time < 18.0:
    print("下午好")
elif time >= 18.0 and time  < 22.0:
    print("晚上好")
else:
    print("夜深了")
print("=====完毕=====")
input("按Enter键退出...")