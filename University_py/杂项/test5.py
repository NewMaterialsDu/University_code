i = 1
while i <= 100:
    print("想你")
    i += 1
print("想你一百次")
# # while True:
# #     print("一直想你")
# #   死循环   只要不是False或0都可以
#
#
#
i = 1
s = 0
while i <= 100:
    s += i
    i += 1
print(s)
#   表示从0加到100



# while循环嵌套格式
i = 1
while i <= 3:
    print(f"外循环第{i}次")
    j = 1
    i += 1
    while j <= 5:
        print(f"内循环第{j}次")
        j += 1
