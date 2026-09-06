
n = 2

def add(a, b):
    global n # 声明下面的n为全局变量（即：如果没有这行函数，输出结果为30和2）
    n = a * b
    print(n)
add(5, 6)
print(n)
