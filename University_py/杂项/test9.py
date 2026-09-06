li = [1,'dsf',45,12]
for i in li:
    print(i)
#  列表也是可迭代对象，可以遍历循环取值
# 添加元素
shu = [1,2,3,4,5]
shu.append("six")
#  整体添加元素
print(shu)
shu.extend("seven")
#  分散添加，将元素逐一添加  整形不是可迭代对象不能用这个添加
print(shu)
shu.insert(0,'one')
#   在指定位置添加元素，原元素往后移 必须要有指定位置
print(shu)

# 修改元素
shu[0] = 0
# 通过下标修改
print(shu)

# 查询元素 in和not in  和字符串一样
print(1 in shu)

# 游戏中名称重复不能使用
# while True:
#     name_list = ['bingbing','susu','zihan']
#     name = input("请输入您的名称：")
#     if name in name_list:
#         print("您输入的名称已存在")
#     else:
#         name_list.append(name)
#         print('创建成功！')
#     break
# print(name_list)

# 列表中index和count与字符串用法一样，列表没有find
li = ['a','b','c','d','e','f','g','h','i','j']
# del li
# # 整个列表删除，会报错
# print(li)
del li[0]
#  下标是0的元素删除
print(li)

li.pop()
li.pop(2)
# 删除指定下标元素，无指定下标时默认删除最后一个
print(li)


li.remove('f')
# 删除某个指定元素，不存在时会报错,有两个相同元素时默认删除第一个
print(li)

li = [1,21,45,12,878,545,456]
li.sort()
#  默认将列表从小到大进行排列
print(li)
li.reverse()
# 将列表倒叙排列
print(li)


 # 格式一
li = [1,2,3,4,5,6,7,8,9]
for i in li:
    print(i)
# [print(i) for i in li]   for循环的另外写法，结果同上
li = []
for i in range(0,19):
    li.append(i)
print(li)
# [li.append(i) for i in range(0,19)]

# 格式二
li = []
for i in range(0,19):
    if i % 2 == 1:
        li.append(i)
print(li)
# [li.append(i) for i in range(0,19) if i % 2 == 1]


# 列表嵌套
li = [1,2,3,[4,5,6,7]]
print(li[3][0])


