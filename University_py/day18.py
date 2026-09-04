age = input("请输入您的年龄：") # 接受键盘输入的内容(是一个字符串）并赋值给age
print("年龄为：" + age)
print(type(age))
age_new = int(age) + 10 # 整数化
print("计算后的年龄为：" + str(age_new)) # 字符串化
