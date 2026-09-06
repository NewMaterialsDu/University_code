n = 5 # 这是全局变量


def fun(a):
    a = 10 # a和b是局部变量，因为在函数内声明的
    b = 15
    print(a, b)
    print(n)
fun(1)
print(a, b) # 所以输出会出现a未被定义

