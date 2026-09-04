

f = "C:\Users\Administrator\Desktop\student\Wormhole jEjeoq"
a = open(f,"r",encoding="UTF-8") # 字码编符，二进制读取不用字码编符
b = a.read()
print(b) # 第一次读取完后，指针在末尾
a.seek(0) # 指针回到文件开头

ls = a.readlines()
print(ls) # 第二次读取，指针在末尾开始

a.close()

