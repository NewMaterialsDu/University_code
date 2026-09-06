name = input("请输入您的姓名：")
height = float(input("请输入您的身高(米）："))
weight = float(input("请输入您的体重（kg）："))
print(f"姓名：{name}")
bmi = weight / (height ** 2 )
print(f"{name}的BMI指数是:{bmi:.2f}")
if bmi >= 24 :
    print("体重过重")
elif 18.5 <= bmi < 24 :
    print("正常范围")
else :
    print("体重过轻")