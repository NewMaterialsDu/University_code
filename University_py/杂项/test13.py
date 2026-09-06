#  赋值相当于完全的资源共享，例如
li = [1,2,3,4,5]
print(li)
li2 = li
print(li2)
print(id(li),id(li2))
# 内存地址一样
li2.append(6)
print(li2,li)
# 一个改变，另一个也会改变

import copy
# 导入浅拷贝模块,浅拷贝：
li = [1,2,3,[4,5,6]]
li2 = copy.copy(li)
# 浅拷贝会创建新的对象，拷贝第一层数据，嵌套层会指向原来的内存地址
print(id(li),id(li2))
# 内存地址不一样，不是同一个对象
li.append(8)
print(li)

print(li,li2)
li[3].append(7)
# 往嵌套列表里添加7
print(li,li2)
# 两个列表的嵌套列表都有7
print(id(li[3]),id(li2[3]))
# 外层地址不同，内层地址一样（浅拷贝）

# 深拷贝(数据完全不共享)
import copy
# 导入模块
li = [1,2,3,[4,5,6]]
li2 = copy.deepcopy(li)
print(id(li),id(li2))
# id地址完全不同
li[3].append(8)
print(li,li2)
# 深拷贝数据变化与对方无关



# 可变对象：值可以修改，但是内存地址不改变
# 常见的有：list(列表) dict(字典) set(集合)
li = [1,2,3,[4,5,6]]
print(id(li))
li.append(8)
print(id(li))

# 不可变对象，保存的内容不允许修改，如果修改就会生成一个新的值并分配新的内存空间
#  常见有：int（整型） bool（布尔类型） float（浮点数） complex（） str（字符串） tuple（元组）
n = 'sdghjf'
print(id(n))
n = 'hello'
print(id(n))





