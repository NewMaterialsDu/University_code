# 元组
tua = (1,2,3,4,5,'a','asfd',[41,21,2312,])
# 只有一个元素的时候，末尾要加上逗号,否则返回唯一的数据类型
print(tua)
print(type(tua))
b = (1)
print(b)
a = ()
# 定义空元组
# 元组只能查询不能修改
# count() index()   len()  跟列表用法相同

name = 'bingbing'
age = '18'
print('%s的年龄是%d',(name,age))
# 格式化输出本质是个元组


# 字典 键具有唯一性，但值可以重复
dic = {'name':'bing','age':'18'}
dic2 = {'name':'bing','name':'susu'}
print(dic2)
# 不会报错，但前面的键值会被后面的覆盖
# 字典没有下标，查看元素要用键
print(dic.get('name',"不存在"))
# 查询值，键名不存在时默认返回None，可以设置返回的字符（不存在）
print(dic.get('1',"不存在"))

dic['age'] = 20
print(dic)
# 通过键来修改值
dic['name2'] = 'susu'
print(dic)
# 如果键不存在，就新增值

del dic['age']
# 删除某个键值对
del dic2
# print(dic2)  删除整个字典
print(dic)

dic.clear()
print(dic)
# 清空整个字典，但保留这个字典
dic = {'name':'bing','age':'18',1:2,2:3}
dic.pop('name')
print(dic)
# 删除某个键值对
dic.popitem()
print(dic)
# 默认删除最后一个键值对
print(len(dic))
# 字典中有两对键值对
print(dic.keys())
# 返回字典的所有键
for i in dic:
    print(i)
# 只取出键，不取值
for i in dic.values():
    print(i)
print(dic.values())
# 取出所有值
print(dic.items())
for i in dic.items():
    print(i)
# 以元组形式取出键值对











