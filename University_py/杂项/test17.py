# 内置函数
# 查看所有的内置函数
import builtins
print(dir(builtins))
# 大写字母开头一般是内置常变量名，小写字母开头一般是内置函数名

# zip()将可迭代对象作为参数，将对象中对应的元素打包成一个个元组
li = [1,2,3]
li2 = ['a','b','c']
print(zip(li,li2))
# 第一种方式取出：for循环
for i in zip(li,li2):
    print(i)
    print(type(i))
# 如果元素个数不一致，就按照长度最短的返回
#第二种方式：转换成列表打印
print(list(zip(li,li2)))
# li和li2都必须是可迭代对象，否则报错



#map（）：可以对可迭代对象中的每一个元素进行映射，分别去执行
# map(func,iterl):func---自己定义的函数 iterl---要放进去的可迭代对象
# 对象中的每一个元素都会去执行这个函数
li = [1,2,3]
def funa(x):
    return x * 5
mp = map(funa, li)
for i in mp:
    print(i)



# reduce()  对参数序列中元素进行积累
# 先把对象中的两个元素的值取出并计算出一个值保存着，接下来把计算值跟第三个元素进行计算
# 先导包
from functools import reduce
# reduce(function,sequence) function--函数：必须是要有两个参数的函数，sequence--序列：可迭代对象
li2 = [1,2,3,4]
def add(x,y):
    # 把x和y累加
    return x+y
ok = reduce(add,li2)
print(ok)


# 拆包含义：对于函数中返回的多个数据，去掉元组，列表或者字典 直接获取里面数据的过程
tua = (1,2,3,4,5)
# 方法一
a,b,c,d,e = tua
print(a,b,c,d,e)
# 要求个数一样




# 方法二
p, *g = tua
# 加星号表示可变参数，p取一个值后，g作为可变参数取剩下的值
print(p)
print(g,type(g))
# 一般在函数调用时使用
def funa(x,y, *args):
    print(x,y)
    print(args,type(args))
# args是元组类型，因为加了*
funa(1,2,3,4,5)

# 方法二中，g输出是liat（列表），args输出是tuple（元组）






