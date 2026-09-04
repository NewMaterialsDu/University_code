a = -1.2
print(type(a))
b = int(a)
# int 转换为一个整数  只能转纯数字（字符串和浮点型都行），有正负号以外的字符会不行
print(type(b))
print(b)
# 浮点型转换为整型会直接去掉小数部分

print(float(11))
# float   转换为浮点型，只能转纯数字（字符串和浮点型都行），有正负号以外的字符会不行

print(str(a),type(str(a)))
# str()  转换为字符串   浮点型转换为字符串会自动去掉浮点型末尾的0

li = [1,2,3]
print(type(li))
print(type(str(li)))
# 将列表转换为字符串类型

print(10+10)
print('10'+'10')
print('10+10')
print(eval('10+10'))
# 执行一个字符串表达式，并返回运算值

st1 = "[[1,2,3],[4,5,6],[7,8,9]]"
li = eval(st1)
print(type(st1),type(li))
# 去掉引号，str（字符串）-->list（列表）

st1 = "{'name':'bing','age':18}"
li = eval(st1)
print(type(st1),type(li))
# 同理 str --> dict(字典)或者字符串转换为元组
# eval非常强大，但是不够安全，容易被恶意修改数据，不建议使用

# list() 将可迭代对象转换为列表
print(list('hgfhgj'))
print(list((1,2,3,4,5)))  #将tuple（元组）转换为列表
print(list({'name':'bing','age':18}))
# 字典转换为列表，会取键名作为列表的值
print(list({'a','b','c'}))
# 集合转换成列表会去重再转换，转换后同样是无序的








