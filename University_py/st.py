students = [
            ["学号","姓名","性别","年龄"]
            ["1001","张三","男","14"]
            ["1002","李四","男","21"]
            ["1003","王五","男","17"]
            ["1004","赵六","女",]
            ]
f = open("students.csv","w")
for row in students:
    s = ",".join(row) + "\n"
    f.write(s)  #row表示行，一行一行写入，join用逗号分开行，循环一次写入一行


f.close()
