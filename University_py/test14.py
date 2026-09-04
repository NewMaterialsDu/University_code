# 函数：
# def 函数名：
#     函数主体（）
# 调用函数：
# def 函数名（）
# 调用几次，函数里面的代码就会运行几次，每次调用时函数都会从头开始执行

# 打招呼函数：
def hello():
    print("Hello World")
    print("Hello bingbing")
hello()

def buy():
    return "mony"
buy()
print(buy())
# return会返回一个值（mony），不会输出，要打印

def bu():
    return "mony",20
    print("hello")
# 函数中遇到return，return下面的代码不会执行，表示函数到此结束
bu()
print(bu())
# 返回多个值时，以元组的形式

def bus():
    return
# 没有返回值时，返回None

print(print(123))
# 会打印123再输出None

def add():
    return 12 + 2
print(add())
# return会返回计算值

# 有参数的函数
def abb(a,b):
    return a+b
print(abb(1,2))
# 相当于给a赋值为1，给b赋值为2








