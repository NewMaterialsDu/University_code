a = ('hello')
print(type(a))
a1 = a.encode()    # 编码
print(type(a1))   #bytes,以字节为单位进行处理
print(a1)
a2 = a1.decode()  # 解码
print(a2)
# 对于bytes，只要知道它跟字符串之间的互相转换



st = "中国教育"
st1 = st.encode("utf-8")#转换为uft-8的编码类型
print(st1, type(st1))
st2 = st1.decode()  # 解码
print(st2, type(st2))
print(st[3:1:-1])  # 步长正负号表示方向