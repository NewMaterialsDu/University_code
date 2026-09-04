f = open("students.csv","r")
student = []
for line in f:
    line = line.strip("\n") # 清除两边的换行符
    temp = line.split(",") #用逗号隔开
    student = temp
    
    
    print(student)
f.close()