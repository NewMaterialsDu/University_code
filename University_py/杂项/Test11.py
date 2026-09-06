#  集合
s1 = {1,2,3,4,5}
print(s1,type(s1))
s2 = {}
print(s2,type(s2))
#  定义空字典
s3 = set()
print(s3,type(s3))
#  定义空集合
s4 = {'a','b','c','d','e'}
print(s4)
# 集合的无序性   无序性的方式涉及hash表
print(hash('a'))
print(hash('b'))
print(hash('c'))
# 每次运行结果都不同，hash值不同，在hash表位置也不同
print(hash(1))
print(hash(2))
print(hash(3))
# python中hash值就是它本身，在hash表中位置不会发生改变
print(hash('1'))
print(hash('2'))
print(hash('3'))
# 字符串不一样
# 无序性：不能修改集合中的值
# 集合具有唯一性，不能重复，会自动去重

s2 = {1,2,3,4,5}
s2.add('hjghjg')
print(s2)
# 添加一个整体，一次只能一个元素，如果添加的元素原集合中有了，则不进行操作
s2.update('hgfhjhj')
print(s2)
#  update分散添加，元素必须是可迭代对象

s2.remove('hjghjg')
print(s2)
#  删除集合的某个元素，没有时会报错
s2.pop()
print(s2)
#默认删除根据hash表排序后的第一个元素

s2 = {1,2,3,4,5}
s2.discard('hjghjg')
print(s2)
# 指定删除某个元素，没有则不进行处理

a = {1,2,3,4,5}
b = {6,7,8,9,10}
print(a & b)
# 交集符合&，没有则返回空集
print(a | b)
# 并集符合|，集合有唯一性，重复的不算











