name = "Bingbing"
print(name.find("i"))   #  从左到右查找第一个i，并返回他的坐标
print(name.find("bing"))   # 返回最开始的坐标
print(name.find("b",3))   # 从坐标3开始
print(name.find("b",5))    #超出范围（或没找到）返回-1
print(name.find("b",3,5))  #从3到5查找
# print(name.index("b",5,7))  # 与find区别：没找到会报错



print(name.count("b",3,5))
# 返回b在字符串中出现的次数，从坐标3开始到5结束，3和5都可省略   没有出现会返回0



# startswith():判断是否以某个子字符串开头，返回True或False，如果设置开头结尾则在指定范围内查找
print(name.startswith("Bing",0,6))
# endswith():判断是否以某个子字符串结尾，返回True或False，如果设置开头结尾则在指定范围内查找
print(name.endswith("b",4,6))
# isupper(): 判断字符串中所有的字母是否为大写，返回True或False
print(name.isupper())

me = "dgfdga"
tt = '天天向上'
print(tt.replace('天','shi',1))
# replace(旧内用，新内用，替换次数)：  没有次数默认为全部替换
print(tt.split("天",2))
# split():以列表形式返回分割内容，2为分割次数，字符串中如果没有分割内容则整体返回
# capitalize（）：  第一个字符大写
print(me.capitalize())
# lower（）：大写字母变小写
ni = "FGcCF"
print(ni.lower())
ne = 'hghjghj'
print(ne.upper())#小写变大写

new_name = "python  "
print(new_name.rstrip())
# rstrip（）删除字符串右端的空白
new = "  python"
print(new.lstrip())
# lstrip（）删除字符串左端的空白
new = "  python    "
print(new.strip())
# strip（）同时删除字符串两端的空白






