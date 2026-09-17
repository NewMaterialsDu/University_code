# 57.函数介绍

# 58.函数定义
def print_values():
    print("Hello, World!")
    print("Welcome to Python programming.")

print_values()  # 调用函数

# 59.函数参数与返回值
def add_numbers(a, b):
    return a + b

result = add_numbers(5, 3)
print(result)  # 输出: 8

# 60.函数说明文档
def print_values():
    """
    打印欢迎信息的函数。
    """
    print("Hello, World!")
    print("Welcome to Python programming.")

print_values.__doc__ = "打印欢迎信息的函数。"
print(print_values.__doc__)

# 使用help()函数查看函数的说明文档
help(print_values)

# 61.函数嵌套
def outer_function():
    def inner_function():
        print("This is the inner function.")
    print("This is the outer function.")
    inner_function()

outer_function()  # 调用外部函数

# 函数调用遵循栈的原则，先调用外部函数，再调用内部函数，最后返回到外部函数。（后进先出）
def function_a():
    print("Function A is called.")
    function_b()
    print("Function A is returning.")

def function_b():
    print("Function B is called.")
    function_c()
    print("Function B is returning.")

def function_c():
    print("Function C is called.")
    print("Function C is returning.")

function_a()  # 调用函数A

# 62.案例

# 63.函数变量作用域
# 全局变量和局部变量
# 在局部变量前加上global关键字可以在函数内部修改全局变量的值（注意：使用global关键字要先声明，再使用）
x = 10  # 全局变量
def print_values():
    global x  # 声明x为全局变量
    x = 20  # 修改全局变量的值
    print("Inside function, x =", x)

print("Before function call, x =", x)
print_values()
print("After function call, x =", x)

# 64.函数参数
# 传参方式

# 位置参数
def print_values(a, b):
    print("a =", a)
    print("b =", b)

print_values(5, 10)

# 关键字参数（不要求顺序）

def print_values(name,age,city):
    print("Name:", name)
    print("Age:", age)
    print("City:", city)

print_values(name="Alice", age=30, city="New York")

def print_values(**kwargs):
    for key, value in kwargs.items():
        print(f"{key} = {value}")

print_values(name="Alice", age=30, city="New York")
print_values(city="New York", name="Alice", age=30)

# 如果位置参数与关键字参数混用，关键字参数必须放在位置参数的后面，否则会报错。

def print_values(a, b, name="Alice", age=30, city="New York"):
    print("a =", a)
    print("b =", b)
    print("Name:", name)
    print("Age:", age)
    print("City:", city)

print_values(1, 2, name="Bob", age=25, city="Los Angeles")

# 65.默认参数（也叫缺省参数）
def print_values(a, b=10):
    print("a =", a)
    print("b =", b)

print_values(5)  # b使用默认值10
print_values(5, 15)  # b使用传入的值15

# 66.不定长参数：基于位置参数或者关键字参数的传递方式
# 位置传递的不定长参数
def print_values(*args):
    for arg in args:
        print(arg)

print_values(1, 2, 3, 4, 5)

# 关键字不定长参数
def print_values(**kwargs):
    for key, value in kwargs.items():
        print(f"{key} = {value}")

print_values(name="Alice", age=30, city="New York")

# 67.参数类型
# 普通参数：数字、字符串、列表、字典、布尔值等
# 特殊参数：函数、类、模块等

def add_numbers(a, b):
    return a + b

def calc(x,y, operation):
    return operation(x,y)

result = calc(5, 3, add_numbers)
print(result)

# 68.匿名函数
# 匿名函数也叫lambda函数，是一种简洁的函数定义方式。
# 语法：lambda 参数: 返回值

add_numbers = lambda a, b: a + b
result = add_numbers(5, 3)
print(result)  # 输出: 8

date_list = ["C++", "Python", "Java", "C#", "JavaScript"]
print(date_list)

# 关键字sort()方法对列表进行从小到大排序，默认按字母顺序排序
date_list.sort(key=lambda x: len(x))  # 按字符串长度排序,匿名函数的典型应用场景
print(date_list)  # 输出: ['C++', 'C#', 'Java', 'Python', 'JavaScript']

# 69.案例1（递归）
# 根据传入的数字，计算该数字阶乘的值
def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

result = factorial(10)
print(result)

# 70.函数案例2