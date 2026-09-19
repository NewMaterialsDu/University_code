# 77.面向对象基础概述

# 78.类与对象
# 定义类
# class 类名:
#     pass
# 创建对象
# 对象名 = 类名()
# 对象名.属性名1 = 属性值1

class Car:
    pass
# 创建对象后动态的为对象创建属性
c1 = Car()
c1.color = 'red'
c1.name = 'x5'
c1.brand = 'BWM'
c1.price = 500000
print(c1)
# 会将对象的属性以字典的形式输出
print(c1.__dict__)
# 输出单个属性
print(c1.color)

# 上述定义方法不推荐

# 定义类
# class 类名:
#     def __init__(self,参数列表):
#         self.属性名 = 参数值
#         self.属性名 = 参数值
# # 创建对象
# 对象名 = 类名（参数列表）

# __init__：初始化方法（定义在类内称为方法，定义在类外称为函数），对象创建后自动调用，主要用于设置对象的初始状态（设置对象属性）
# self：方法的第一个参数，表示当前创建的第一个实例对象（类似于this）

class Car01:
    def __init__(self,c_color,c_name,c_brand,c_price):
        self.color = c_color
        self.name = c_name
        self.brand = c_brand
        self.price = c_price
        print("Car01 对象初始化完毕！")

c2 = Car01("red","X7","BMW",80000)

# 79.面向对象实列方法

# class 类名:
#     def __init__(self,形参列表):
#         self.属性名 = 参数值
#         self.属性名 = 参数值

#     def 方法名(self,形参列表):
#         ...

#     def 方法名(self,形参列表):
#         ...

# 对象名 = 类名(参数列表)
# 对象名.方法名(实参)

class Car02:
    def __init__(self,c_color,c_name,c_brand,c_price):
        self.color = c_color
        self.name = c_name
        self.brand = c_brand
        self.price = c_price
        print("Car01 对象初始化完毕！")

    def running(self,):
        print(f"{self.brand}{self.name}正在高速行驶。。。。")

    def total_cost(self,discount,rate=0.1):
        '''
        计算提车的总费用，包含两个部分：车的价格，税费
        param discount ：折扣
        param rate:税费
        return：提车的总费用
        '''
        self.total_cost = self.price * discount + rate * self.price
        return self.total_cost


c3 = Car02("红色","BMW","X7",800000)
c3.running()
total01 = c3.total_cost(0.9)
print("提车的总费用为:",total01)

total02 = c3.total_cost(0.9,0.2)
print("提车的总费用为:",total02)

# 80.魔法方法
# 这里的魔法方法指的是python提供了以下划线开头和结尾的特殊方法，用于定义的特殊行为，比如：__init__。
# 魔法方法不需要手动调用
# __init__                        初始化方法
# __str__                         字符串的表示方法
# __eq__                          比较两个对象是否相等（equal）
# __lt__,__le__,__gt__,__ge__     支持比较两个对象的大小（小于（less than），小于等于（less than or equal），大于（greater than），大于等于（greater than equal））

c4 = Car02("蓝色","BMW","X9",800000)
print(c3 == c4)  #false 默认基于内存地址进行比较
print(c3 < c4)  #报错

