ls = ["北京","深圳","广州","上海"]
f = open("city.csv","w")
s =  ",".join(ls)
f.write(s)
f.close()


