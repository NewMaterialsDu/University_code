ls = "[45,154,12,45]"
print(type(ls))
ls = eval(ls)  # 将两边双引号去掉
print(ls)
print(type(ls))
exec("a = 1 + 99")
print(a)

print(range(1,5,2))
for i in range(1,101,2):
    print(i)

