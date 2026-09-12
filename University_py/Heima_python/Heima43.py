# 43.字符串 字符的容器 序列对象 不可更改的 有序性 可迭代性 基本操作：
s = "Hello_Python"

# 序列对象，因此可以切片，索引操作（索引修改会报错，因为字符串不可修改）
print(s[4])
print(s[-8])

# 切片截取的步长，正数是从左往右，负数是从右往左
print(s[0:5:1])
print(s[-1:-7:-1])

# 44.字符串常用方法（这些方法不修改原字符串，而是返回新的字符串）

# 在字符串中查找子串，返回第一次出现的索引位置，如果没有找到返回-1
print(s.find("Python"))
# 统计字符串中某个子串出现的次数
print(s.count("o"))
# 所有字母变为大写
print(s.upper())
# 所有字母变为小写
print(s.lower())
# 将字符串按指定分隔符分割成列表
print(s.split("_"))
# 去除字符串首尾的空格或指定字符
print("   Hello Python   ".strip())
print("###Hello Python###".strip("#"))
# 将字符串中的指定子串替换为新的子串
print(s.replace("Python", "World"))
# 判断字符串是否以指定子串开头或结尾，返回布尔值
print(s.startswith("Hello"))
print(s.endswith("Python"))









