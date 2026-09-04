# 20.比较运算符
# ==为等于，!=为不等于，>为大于，<为小于，>=为大于等于，<=为小于等于
# 比较运算符的结果会返回一个布尔值：True为真，False为假
from unittest import case

print(10==10)
print(10!=10)

# 21.逻辑运算符：and  or  not分别表示并且  或者  相反

# 22.if语句
# 语法 if 要判断的条件：
#           条件成立执行

# 23.if案例

# 24.if进阶语法：
# if 条件：
#     代码
# else：
#   代码

# 25.if进阶语法：
# if 条件：
#   代码
# elif 条件：
#   代码
# else：
#   代码

# 26.案例

# 27.match...case相当于switch...case
# 语法：
# day = input("请输入今天·是星期几：")
# match day:
#     case 1:
#         print("01")
#     case 2:
#         print("02")
#     case 3:
#         print("03")
#     case '_':
#         print("其他")

# 28.whle循环
# 语法：while 条件：
#       代码
#      else：
#       条件为false，循环正常结束时执行

# 29.案例

# 30.for循环（论序遍历）
# for 元素 in 待处理数据集：
#       代码
# else：
#       循环结束时执行
msg = "Hello World"
for i in msg:
    print(i)
else:
    print("执行完毕！")

# 31.案例

# 32.嵌套循环

# 33.案例：99乘法表
# end=“\t”表示后面加制表符
for x in range(1,10):
    for y in range(1,x+1):
        print(f"{x}x{y}={x*y}",end="\t")
    print()

# 34.案例1

# 35.案例2

