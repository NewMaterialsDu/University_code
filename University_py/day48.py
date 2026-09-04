s = "i miss you"
print(s.index("o"))
print(s.find("o"))
 # o在s中第一次出现的位置，没找到时，第一个会报错，第二个返回-1
print(s.find("o",5,7)) # 从第5个开始,到第7个
print(s.find("o",6))