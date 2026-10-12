# 110.文件操作入门

# 打开文件(不存在时会自动创建)
# encoding指定编码格式(uft-8, gbk,gb2312,ascii等)
# mode参数：
f = open(file="./Heima_python/test.txt", mode="r", encoding="utf-8")  

# 读取文件
content = f.read()
print(content)

# 关闭文件
# 操作完后一定要关闭文件，不然会一直被这个程序占用着，导致其他程序无法使用这个文件
f.close()

# 写入文件
f1 = open(file="./Heima_python/hello.txt", mode="w", encoding="utf-8")  
f1.write("Hello word")
f1.close()

# 111.文件操作-资源释放
f2 = open(file="./Heima_python/test.txt", mode="r+", encoding="utf-8")

# 这样的话，无论程序是否出现异常，都能保证文件被关闭
try:
    f2.write("Hello word")
    f2.write("Hello word")
    f2.write("Hello word")
    f2.write("Hello word")
finally:
    f2.close()

# 更简洁的方式
# with语句(上下文管理器)的核心作用就是确保资源总是被正确获取和释放（即使发生异常，也会被正确释放）
with open(file="./Heima_python/hello.txt", mode="w", encoding="utf-8") as f3:
    f3.write("Hello word")
    f3.write("Hello word")
    f3.write("Hello word")
    f3.write("Hello word")
    f3.write("Hello word")
    f3.write("Hello word")

# 112.读取json格式文件
import json
user = {
    "name":"张三",
    "age":18,
    "gender":"男",
    "hobbies":["reading","swimming"]
}
with open(file="./Heima_python/user.json",mode="w",encoding="utf-8") as f4:
    # ensure_ascii:默认为True，确保所有的数据输出都是ASCII码（非ASCII码会默认进行转义）;False，非ASCII码保留原样输出
    # dump：将python对象序列化为json格式字符串并写入文件
    json.dump(user,f4,ensure_ascii=False,indent=4)

# 读取json格式文件
with open(file="./Heima_python/user.json",mode="w",encoding="utf-8") as f5:
    # load：从文件中读取json格式数据，并将其反序列化为python对象
    user1 = json.load(f5)
    print(user1,type(user1))


