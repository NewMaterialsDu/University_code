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

# 不能混合使用位置参数跟默认参数，会报错
# total02 = c3.total_cost(0.9,0.3)
# print("提车的总费用为:",total02)

# 80.魔法方法
# 这里的魔法方法指的是python提供了以下划线开头和结尾的特殊方法，用于定义的特殊行为，比如：__init__。
# 魔法方法不需要手动调用，名字是固定的，但是里面的具体内容是自己定义的
# __init__                        初始化方法
# __str__                         字符串的表示方法
# __eq__                          比较两个对象是否相等（equal）
# __lt__,__le__,__gt__,__ge__     支持比较两个对象的大小（小于（less than），小于等于（less than or equal），大于（greater than），大于等于（greater than equal））

c4 = Car02("蓝色","BMW","X9",800000)
# print(c3 == c4)  #false 默认基于内存地址进行比较
# print(c3 < c4)  #报错

class Car03:
    def __init__(self,c_color,c_name,c_brand,c_price):
            self.color = c_color
            self.name = c_name
            self.brand = c_brand
            self.price = c_price
            print("Car01 对象初始化完毕！")
    def __str__(self):
        return f"{self.brand},{self.color},{self.name}"
    def __eq__(self,other):
        return self.brand == other.brand and self.name == other.name and self.color == other.color
    def __lt__(self,other):
        return self.price < other.price
    
c5 = Car03("蓝色","BMW","X9",800000)
c6 = Car03("蓝色","BMW","X9",800000)
# 定义魔法方法之后，下面的比较跟输出就会自动调用魔法方法，类似运算符重载
print(c5,c6)
print(c5 == c6)
print(c5 < c6)

# 81.实例属性跟类属性
# 实例属性属于具体对象的属性，每个对象都是独立的（每个对象有各自的数据）
# 类属性属于类本身的属性，所有实例共享的（所有对象共享的数据或配置）
# 实例属性通过实例对象.属性访问，比如：self.name
# 类属性通过类名.属性访问，比如：Car.wheel
# 说明：通过实例对象查找属性时，会先查找实例属性，实例属性不存在时，再查找类属性（所以实例对象也可以访问类属性）
class Car04:
    # 类属性
    wheel = 4  #轮胎
    tax_rate = 0.1  #购置税
    # 实例属性
    def __init__(self,c_color,c_name,c_brand,c_price):
            self.color = c_color
            self.name = c_name
            self.brand = c_brand
            self.price = c_price
            print("Car01 对象初始化完毕！")

c7 = Car04("蓝色","BMW","X9",800000)
c8 = Car04("蓝色","BMW","X9",800000)
print(c7.wheel)
print(c8.tax_rate)
print(Car04.tax_rate,Car04.wheel)

# 82.-85.面向对象案例（教务系统）

# 86.异常介绍
# 捕获异常，语法：
# try：
#   可能出现异常的代码1
#   可能出现异常的代码2
#   。。。
# except [异常类型 as 变量名]:
#   出现异常时的预案
# else：
#   没有报错时运行的代码
# [finally：
#   无论是否出现异常都会执行的代码]

try:
    print("----------")
    #  print(my_name)
    print(1/0)
    print("------------")
except NameError as e:
    print("报错了：",e)
except ZeroDivisionError as e:
    print("0不能做分母")
else:
    print("没有报错时运行的代码")
finally:
    print("资源释放")

# 87.异常，案例代码完善
# 程序出现异常时，会将异常沿着函数调用层层上报，直到被处理，如果一直没处理，就会上报到主函数给用户

