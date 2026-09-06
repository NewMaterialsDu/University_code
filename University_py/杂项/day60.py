d = {"2020":"张三","2021":"李四","2022":"王五"}
print(d.keys())
print(type(d.keys()))
print(d.values)
print(type(d.values()))
print(d.items())
print(type(d.items()))
for i in d:
    print(i)
for i in d.keys():
    print(i)
for i in d:
    print(d[i])
for i in d.values():
    print(i)
for i in d.items():
    print(i)
for k,v in d.items():
    print(k,v)