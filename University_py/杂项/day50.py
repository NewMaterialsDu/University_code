'''
a = "二级考试"
print("{:25}".format(a))
print("{:1}".format(a))
print("{:^25}".format(a))
print("{:*>25}".format(a))
b = "+"
print("{0:{1}^25}".format(a,b)) # 1为第二个，即b，0到25用b填充a
print("{0:{1}<{2}}".format(a,b,25))
#2.3为填充 4居中  5*右对齐
'''
a = "{0:{1}^18}"
b = "中央"
c = "*"
print(a.format(b,c))