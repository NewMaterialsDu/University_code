 #字典
d = {"2020":"张三","2021":"李四","2022":"王五"}
print(type(d))
print(d)
 # 字典索引：
print(d["2020"])
d["2021"] = "老刘"
print(d)
d["2023"] = "老大"
print(d)
print("2020" in d)
print("张三" in d)