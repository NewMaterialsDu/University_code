a = [-1,True,2,67]
b = [0,14,True,False]
print(all(a),all(b))  
print(any(a),any(b))     
# 当组合类型中所有元素都为真时返回True（为空亦是如此），否则返回False    组合类型即集合列表元组
# 当组合类型中任一元素都为真时返回True（为空亦是如此），否则返回False    非零即真

print(list(reversed(a)))
  # 返回a的逆序形式   list将它转换为列表形式

print(sorted(a))  # a中的元素从小到大排序

print(sum(a))  # a中元素之和



