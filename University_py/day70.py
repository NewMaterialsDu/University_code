f = open("city.csv","r")
info = f.read()
f.close()
ls = info.split(",")  #将info中的字符用，分开并返回一个列表
print(ls)