# 函数参数
# 必备参数（位置参数）
# 含义：传递和定义参数的顺序及个数必须一致
def funa(name1,name2,name3):
    print(name1,name2,name3)
funa("<NAME>","<NAME>","<NAME>")
# 写几个就传几个，不能多或少，顺序也要一样


# 默认参数
# 含义：为参数提供默认值，调用函数时可不传该默认参数的值
# 所有的位置参数必须出现在默认参数前，包括函数定义和调用
def funb(a = 8):
    print(a)
funb()
funb(200)
# 没有传值会用默认参数，有传值则用传值


# 可变参数
# 含义：传入的值和数量是可以改变的，可以传多个，也可以不传
def func(*args):
    print(args)
    print(type(args))
# args可以改成其他参数名，但星号（有特殊含义）必须有，以元组的形式接收
func(1,2,3,4)



# 关键字(不能改，有特殊含义)参数
# 以字典的形式接收
def fund(**kwargs):
    print(kwargs)
    print(type(kwargs))
fund(name='bingbing',age=18)
# 传值时，要用键=值的形式
# 作用：可以扩展函数功能



def study():
    print("在学习")
def cos():
    study()
    print('学习python')
# 在函数里调用函数
cos()


def funf():
    print('在学习')
    def fung():
        print('学习python')
    fung()
# 在函数里定义函数，并调用   不要在内函数里调用外函数，会进入死循环
funf()











