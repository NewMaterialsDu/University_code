

f = "C:/Users/Windows/Desktop/student/okok.txt"
a = open(f,"r",encoding="UTF-8") # 字码编符，二进制读取不用字码编符
b = a.readlines(4) #读取4行，每个行为一个元素发回一个列表 
print(b)

a.close()



