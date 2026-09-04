ls = list([])

print(ls)



ls.append(123) #在末尾加元素123
ls.insert(1,253) #在第1位加253,原来的第1位往后移
ls.insert(2,4456)
ls.insert(3,15)
ls.remove(15) #将第一个253删除
print(ls)
ls.pop(1) #第1位删除，没有1就默认删除最后一位
print(ls)
ls.clear() #清除所有元素







print(ls)
print(type(ls))