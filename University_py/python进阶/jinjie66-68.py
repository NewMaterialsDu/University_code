# 66.深拷贝和浅拷贝
import copy
# 可变对象和不可变对象
# 除了列表字典集合，其他都是不可变对象

# 可变对象：改变其对象的值时，就在原地址直接改变当中存储的值
# 不可变对象：改变其对象的值时，是先把原来的值复制一份再改变，这会开辟一个新的地址，变量再指向新的地址

#所谓深浅拷贝其实指的是：
# 浅拷贝：copy模块的copy()函数
# 深拷贝：copy模块的deepcopy()函数

# 深浅拷贝主要针对于可变类型来讲的，深拷贝拷贝所有层，浅拷贝拷贝第一层
# 如果是对于不可变类型，则和赋值操作无区别

# 对于可变类型（list）
# 赋值操作，对象完全共享
a = [1, [2, 3]]
b = a

print(id(a), id(b))          # 相同
print(id(a[1]), id(b[1]))    # 相同
print(a is b)                # True

# 浅拷贝
print('=' * 23)
a = [1, [2, 3]]
c = copy.copy(a)      # 或 a.copy() / a[:] / list(a)

print(id(a), id(c))          # 不同
print(id(a[1]), id(c[1]) )   # 相同
c[1].append(999)
print(a)   # [1, [2, 3, 999]]

# 深拷贝
print('=' * 23)
d = copy.deepcopy(a)

print(id(a), id(d)  )        # 不同
print(id(a[1]), id(d[1]))    # 不同
d[1].append(888)
print(a)   # [1, [2, 3, 999]]
print(d)   # [1, [2, 3, 888]]

# 67.操作不可变类型
# 对于不可变类型
print("=" * 23, "tuple 内含 list（外壳不可变，内层可变）")
a = (1, [2, 3])
b = a
c = copy.copy(a)
d = copy.deepcopy(a)

print("外层 id：")
print("a", id(a))
print("b = a", id(b))          # 同 a
print("c = copy", id(c))       # 同 a，浅拷贝 tuple 直接返回原对象
print("d = deep", id(d))       # 不同，内部有 list，deepcopy 新建 tuple

# 68.深拷贝——操作可变和不可变类型


