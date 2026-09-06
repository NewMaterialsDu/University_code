for i in range(1, 10):
    for j in range(1, i+1):
        print(f"{j}*{i} = {j*i}",end="\t")
    print()
# 九九乘法表


str = "hello world"  # 字符串是可迭代对象（整形还和浮点型不是可迭代对象），就是遍历取值的整体
for i in str:
    print(i)
for i in range(1,10):
    print(i)
    print("hhhhhhh")

s = 0
for i in range(1,101):
    s += i
print(s)



a = 1
while a <= 10:
    print(f"吃第{a}个苹果")
    if a == 5:
        print(f"第{a}个苹果，吃饱了")
        break   # 结束break所在的循环
    a += 1


a = 1
while a <= 100:
    if a == 5:
        print(f"吃到第{a}个苹果，有虫子")
        a += 1
        continue  # 跳过当前循环的剩余代码，但这里已经打印了有虫子的消息   continue结束本次循环，继续下一次循环
    print(f"吃了第{a}个苹果")
    a += 1

