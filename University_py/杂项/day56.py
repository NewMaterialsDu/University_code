a = [123,456,458]
b = a
b[1] = 3.14
print(a)
print(b)
# 输出内容都是一样的
c = [789,456,123]
d = c.copy() # 将c复制一份再赋值给d
d[1] = 562
print(c)
print(d)
 # 避免上述问题