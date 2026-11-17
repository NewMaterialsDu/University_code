# 98.迭代器介绍
# python中的一种对象用于在数据集合中逐个访问元素，而不需要暴露数据集合的底层实现
# 提供了一种遍历集合元素的标准方式，适用于任何支持迭代器的数据结构，例如：列表，元组，range（）等就是一个迭代对象
# 自定义迭代器：自定义的类，需要重写__iter()__和__next()__方法
# 演示：重写range（）
class MyIterator:
    def __init__(self,start,end):
        self.current_value=start
        self.end=end

    def __iter__(self):
        return self


    def __next__(self):
        # 判断，如果出界则抛出异常结束
        if self.current_value >= self.end:
            raise StopIteration
        value=self.current_value
        self.current_value+=1
        return value

for i in MyIterator(1,10):
    print(i)

print('*'*23)

# 99.python生成器
# 数据不是一次性生成出来的，用一个生成一个，可以节约内存
# 推导式写法和yield关键字
my_generator = (i for i in range(1,11))
print(my_generator)
print(type(my_generator))
# 从生成器中获取数据
print(next(my_generator))
print(next(my_generator))
print('-'*23)
for i in my_generator:
    print(i)
print('-'*23)

# 验证生成器可以节省内存
my_list = [i for i in range(1000000)]
my_gt3 = (i for i in range(1000000))
import sys
# 查看空间占用
print(f"my_list: {sys.getsizeof(my_list)}")
# 懒汉式：用的时候再生成
print(f"my_gt3: {sys.getsizeof(my_gt3)}")

print('-'*23)

# 100.yield生成器语法
# 只要在def函数里面有yield关键字，那么就是生成器
def my_fun():
    # my_list1 = []
    # for i in range(1,11):
    #     my_list1.append(i)
    # return my_list1

    # yield做了三件事，创建生成器对象，把值存储到生成器中，返回生成器（跟上面效果一样）
    for i in range(1,11):
        yield i

# 测试
print('-'*23)
my_g2 = my_fun()
print(type(my_g2))

print(next(my_g2))
print(next(my_g2))
print('-'*23)
for i in my_g2:
    print(i)

# 101.生成器案例

# 102.上午总结

# 103.property属性介绍
# 就是把函数当属性用，两种使用方法，装饰器方式跟类属性方式
# 装饰器用法:
print('-'*23)












