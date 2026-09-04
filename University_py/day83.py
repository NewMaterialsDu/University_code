import random as d
print(d.random())    # 生成0.0到1.0的随机小数    默认随机数的种子为系统时间
print(d.randint(1,5))   # 生成1到5的随机数整数
print(d.getrandbits(5))    # 生成一个5比特长（二进制长度单位）的随机整数
print(d.randrange(0,50,5))    #  生成从0到50之间以5为步长的随机整数(不写时默认步长为1)
print(d.uniform(5,8))    # 生成5到8之间的随机小数
sl = [50,54,78,51,78]
print(d.choice(sl))   # 从序列中返回一个随机数
d.shuffle(sl)    # 将序列中的元素随机排列，返回打乱后的序列
print(sl)
print(d.sample(sl,3))    # 从sl中随机取3个元素，以列表类型返回
print()



