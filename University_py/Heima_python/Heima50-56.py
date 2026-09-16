# 50.集合
# 集合是无序且不重复可修改的元素容器，使用大括号{}定义
s1 = {"apple", "banana", "cherry"}
s2 = set()  # 空集合必须使用set()创建，{}会创建一个空字典
s3 = {1, 2, 3, 4, 5}
print(s1, type(s1))  # <class 'set'>

# 集合的基本操作
# 添加元素
s3.add("orange")
print(s3, type(s3))  # <class 'set'>
# 删除元素
s1.remove("banana")  # 如果元素不存在会报错
print(s1, type(s1))  # <class 'set'>
# 随即删除元素后返回该元素
removed_element = s3.pop()
print(removed_element, s3, type(s3))  # <class 'set'>
# 清空集合
s3.clear()
print(s3, type(s3))  # <class 'set'>
# 求两个集合的交集、并集、差集
s4 = {1, 2, 3, 4}
s5 = {3, 4, 5, 6}
print(s4 & s5)  # 交集 {3, 4}
print(s4 | s5)  # 并集 {1, 2, 3, 4, 5, 6}
print(s4 - s5)  # 差集 {1, 2}

# 51.集合案例

# 52.字典
# 字典是无序的键值对集合，使用大括号{}定义，
# 键必须是不可变类型（如字符串、数字、元组），值可以是任意类型
# 键不能重复，可以修改
d1 = {"name": "Alice", "age": 25, "city": "New York"}
print(d1, type(d1))  # <class 'dict'>
# 根据键获取值
print(d1["name"])  # 输出：Alice
d1["age"] = 26  # 修改值
print(d1)  # 输出：{'name': 'Alice', 'age': 26, 'city': 'New York'}

# 53.字典的常用方法
# 添加键值对
d1["country"] = "USA"
print(d1)  # 输出：{'name': 'Alice', 'age': 26, 'city': 'New York', 'country': 'USA'}
# 删除指定键值对
del d1["city"]
print(d1)  # 输出：{'name': 'Alice', 'age': 26, 'country': 'USA'}
# 删除字典中指定的key
removed_value = d1.pop("age")
print(removed_value)  # 输出：26
print(d1)  # 输出：{'name': 'Alice', 'country': 'USA'}
# 修改字典中指定的key对应的value
d1["name"] = "Bob"
print(d1)  # 输出：{'name': 'Bob', 'country': 'USA'}
# 根据key获取value，如果key不存在则返回默认值
print(d1.get("age", "Not Found"))  # 输出：Not Found
print(d1["name"])  # 输出：Bob
# 获取字典中所有的键
print(d1.keys())  # 输出：dict_keys(['name', 'country'])
# 获取字典中所有的值
print(d1.values())  # 输出：dict_values(['Bob', 'USA'])
# 获取字典中所有的键值对
print(d1.items())  # 输出：dict_items([('name', 'Bob'), ('country', 'USA')])

# 遍历字典
for key, value in d1.items():
    print(f"Key: {key}, Value: {value}")

# 54.字典案例

# 55.案例测试

# 56.总结








