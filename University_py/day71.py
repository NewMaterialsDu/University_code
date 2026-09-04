students = [
["学号","姓名","性别","年龄"]
["1001","张三","男","14"]
["1002","李四","男","21"]
["1003","王五","男","17"]
["1004","赵六","女","18"]
]
print(students)
print(students[1])
print(students[1][2])
for s in students:
    for i in s:
        print(i)