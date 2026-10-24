#  49.大纲介绍

# 50.闭包背景介绍

# 51.闭包入门
# 在函数嵌套的前提下，内部函数使用了外部函数的变量，并且返回了内部函数(就是把内部函数当作外部函数的一个对象返回)
def fn_outer(num1):
    def fn_inner(num2):
        sum = num1 + num2
        print(sum)
    return fn_inner
inner = fn_outer(5)
inner(10)

fn_outer(10)(20)

# 52.闭包图解

# 53.闭包和装饰器-nonlocal关键字
# nonlocal使得内部函数可以修改外部函数的变量
def fn01_outer():
    a = 100
    def fn01_inner():
        nonlocal a
        a = a + 10
        print(a)
    return fn01_inner
fn01 = fn01_outer()
fn01()
fn01()
fn01()

# 54.闭包总结
# 作用：保存函数中的变量（外部函数的变量）
#有嵌套，有引用，有返回

