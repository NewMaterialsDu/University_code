# 43.字符串 字符的容器 序列对象 不可更改的 有序性 可迭代性 基本操作：
s = "Hello_Python"

# 序列对象，因此可以切片，索引操作（索引修改会报错，因为字符串不可修改）
print(s[4])
print(s[-8])

# 切片截取的步长，正数是从左往右，负数是从右往左
print(s[0:5:1])
print(s[-1:-7:-1])

# 44.字符串常用方法（这些方法不修改原字符串，而是返回新的字符串）

# 在字符串中查找子串，返回第一次出现的索引位置，如果没有找到返回-1
print(s.find("Python"))
# 统计字符串中某个子串出现的次数
print(s.count("o"))
# 所有字母变为大写
print(s.upper())
# 所有字母变为小写
print(s.lower())
# 将字符串按指定分隔符分割成列表
print(s.split("_"))
# 去除字符串首尾的空格或指定字符
print("   Hello Python   ".strip())
print("###Hello Python###".strip("#"))
# 将字符串中的指定子串替换为新的子串
print(s.replace("Python", "World"))
# 判断字符串是否以指定子串开头或结尾，返回布尔值
print(s.startswith("Hello"))
print(s.endswith("Python"))

# 45.案例

# 46.元组
# 元组是不可变的序列对象，使用小括号()定义
# 元组的基本操作与列表类似，但不能修改元素
t1 = (1, 2, 3, 4, 5)
print(t1[0])
t2 = ()
print(t2)
# count()方法统计元组中某个元素出现的次数
print(t1.count(2))
# index()方法返回元组中某个元素第一次出现的索引位置
print(t1.index(3))
# 定义单个元素的元组时，需要在元素后面加上逗号，否则会被认为是普通的括号运算
t3 = (1,)
print(type(t3))  # <class 'tuple'>

# 47.元组的组包与解包
# 组包：将多个值合并到一个容器（元组，列表）中
# 解包：将容器中的值拆分到多个变量中

ty1 = (1, 2, 3)#定义元组，组包
ty2 = 4, 5, 6  # 省略小括号也可以定义元组
# 基础的解包操作
a, b, c = ty1
print(a, b, c)  # 输出：1 2 3

# （*）扩展解包
# 在解包时，如果变量名前加上星号（*），表示将剩余的元素收集到一个列表中
x, *y = ty2
print(x)  # 输出：4
print(y)  # 输出：[5, 6]
*x, z = ty2
print(x)  # 输出：[4, 5]
print(z)  # 输出：6
print(type(x))  # 输出：<class 'list'>
print(type(z))  # 输出：<class 'int'>

# 案例*2

# 48.元组案例

# 49.元组案例优化




