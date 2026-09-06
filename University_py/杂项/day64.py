


f = "C:/Users/Windows/Desktop/student/okok.txt"
a = open(f,"r",encoding="UTF-8") # 字码编符，二进制读取不用字码编符
b = a.readline(4) # 读取一行前4个字符，再次调用就读第二行
print(b)

a.close()



