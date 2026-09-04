# 13.
# type（）查看数据类型
a = 10
b = type(a)
print(a,b)
print(type(3.14))
print(type(True))
print(type(False))
print(type(None))
# isinstance（数据，数据类型） 用来检查数据是否属于指定类型，返回的是一个bool类型，是则返回True，否则返回False
print(isinstance(a,int))
print(isinstance(b,int))
print(isinstance(b,str))
print(isinstance(b,bool))
print(isinstance(b,float))
c = True
print(isinstance(c,bool))
print(type(c))
#14.
# 字符串的定义方式单引号，双引号或者三引号，其中三引号可以多行定义。单双引号定义换行需要拼接
a = 'ok'
b = "okok"
c = '''
ok
ok
ok'''
print(a,b,c)
# 在字符串中用单引号定义具有单引号的内容，要使用转义字符
a = 'It \'s very good'#单引号转义字符
b = "It \"s very good"#双引号转义字符
print(a,"\n","\t",b)#\n为换行符，\t为制表符，表示缩进一个Tab
# 15.
# 字符串的拼接，直接用+来拼接（+号只能是两个str拼接）
a = "Hello"
b = "World"
c = a + b
print("我说："+a+b)
print(a+b,"\n",c)
a = "Hello" "world"
print(a)#像这种会直接拼接输出
d = 18
# 不是str类型的拼接要转为str
# str（）将类型强制转换为str
print("今年刚满"+str(d))
# 16.
# 占位符%s，会将后面的变量强制转换为str，占位符数量要和变量数一样
print("今年刚满%s" % d)
print("我说：%s %s" %(a,b))
# 字符串格式化：f"内容{变量/表达式}"
print(f"大家好，我今年刚满{d}")
print(f"我说：{a+b}")#拼接输出
print(f"我说：{a} {b}")#拼接输出
print(f"我说：{a,b}")#分别输出
print(f"我说：{a,d}")#分别输出
# 17.输入与输出
# a = input("请输入你的年龄：")#使用input输入，无论输入什么，传给变量的都是str类型
# print(f"你的年龄是：{a}")
# print(f"你的出生年为：{2026-int(a)}")#int（）强制转换为int类型
# 18.运算符
# /为除法，结果是小数；//为整除，结果是整数；%为取余/求模；**为幂函数
print(10/5)
print(10//5)
print(10%5)
print(10**2)
# 算术运算符的优先级：**--* / // % --+ -
print(10**2/50+20//2)
# 计算机底层为二进制，不能表示所有小数，所有会出现精度损失
x = 0.5
y = 0.4
print(x-y)
# 19.赋值运算符：=，把右边的值赋值给左边
# a += 2相当于a = a + 2；a -= 2相当于a = a - 2； a *= 2相当于a = a * 2；a /= 2相当于a = a / 2；a %= 2相当于a = a % 2；
# a //= 2相当于a = a // 2；a **= 2相当于a = a ** 2；
a = 2
print(a)
a += 2
print(a)
a -= 2
print(a)
a *= 2
print(a)
a /= 2
print(a)
a //= 2
print(a)#后面出现小数是因为有小数参与运算
a %= 2
print(a)
a **= 2
print(a)


















