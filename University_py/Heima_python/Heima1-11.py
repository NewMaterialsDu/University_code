

# 变量
a = 10 # 整数int
b = 3.14 # 浮点数float
c = "Hello, World!" # 字符串str
d = True # 布尔值bool，bool类型本质上是整数，True对应1，False对应0
e  = None # NoneType，表示空值或无值


#数据容量# int: 4字节（32位）或8字节（64位），取决于系统
# float: 8字节（64位）
# str: 取决于字符串的长度，每个字符占用1字节（ASCII）或2字节（Unicode）
# bool: 1字节（8位）
# 列表，元组，字典，集合等数据结构的容量取决于其中元素的数量和类型

print("Hello, World!")
print(d - 1) # True对应1，False对应0
print(False - 1) # False对应0，结果为-1
print(e) # 输出None

# 变量命名规则
# 1. 变量名必须以字母（a-z，A-Z）或 下划线（_）开头，后续可以包含字母、数字（0-9）或下划线。
# 2. 变量名区分大小写，a和A是不同的变量。
# 3. 变量名不能使用Python的保留字（如if、for、while等）。
# 4. 变量名应该具有描述性，能够清晰地表达变量的用途和含义。
# 5. 变量名不能包含空格，可以使用下划线来分隔多个单词，例如：my_variable。
# 6. 变量名不能以数字开头，例如：1variable是无效的变量名。
# 7. 变量名应该简洁明了，避免过长或过短，通常建议使用小写字母和下划线的命名风格（snake_case）。
f,g = 5,10; # 多变量赋值
print(f,g)
