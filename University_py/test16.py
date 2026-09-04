# 作用域：
# 变量的生效范围，全局变量或局部变量
# 函数外部定义的变量，在整个文件中都是有效的
a = 100
def test1():
    print("这是test1中a的值：",a)
def test2():
    global a
    a = 120
    # global 变量名
    # 在函数内部将局部变量声明为全局变量
    print("这是test2中a的值:",a)
print(a)
test1()
print(a)
#未调用test2函数，声明了函数也不会生效
# 函数内部如果要使用变量，会先从内部找，有的话会直接使用，没有的会到外面去找


def test3():
    global name,age
    name = 'bingbing'
    age = 18
    print(name)
    print(age)
#     有多个变量需要声明时
test3()
# 调用函数后声明才会生效
print(name)
print(age)

# nonlocal
# 用来声明外层的局部变量，只能在嵌套函数中使用，在外部函数先声明，内部函数进行nonlocal声明
a = 10
def test4():
    a = 5
    def test5():
        # nonlocal a
        # 如果这里没被注释掉，结果会是三个7
        a = 6
        def test6():
            nonlocal a
            a = 7
            print(a)
        test6()
        # # 调用test6函数后，nonlocal开始生效，将a = 7声明为上层外函数的变量
        print(a)

    test5()
    # 调用test5函数后，nonlocal开始生效，将a = 6声明为上层外函数的变量
    print(a)
test4()
print(a)


# 匿名函数
# 格式
# 函数名  = lambda 形参 ： 返回值（表达式）
# 调用：结果 = 函数名（实参）
# 普通函数:
def add(a,b):
    return a+b
print(add(10,20))
# 匿名函数
abb = lambda a,b:a+b
# ab就是匿名函数的形参，a+b就是返回值的表达式
# lambda不需要写return，表达式本身结果就是返回
print(abb(10,20))






























