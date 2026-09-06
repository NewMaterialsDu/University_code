print("Hello","World")
# 当输入print（）时会出现sep，end
print("Hello","word",sep="***")
#   sep用来间隔多个对象，默认是一个空格
print("Hello",end="")
print("word")
#   end用来设定以什么结尾。默认是换行符\n
print("Hello","word",end="\n",sep="***")
# 此处存在换行符，所以下个输出内容会换行

name = "bingbing"
print("我的名字是%s"% name)
#   %s为字符串占位符
age = 18
print("我的名字是%s，年龄为%d"%(name,age))
#   %d为整数占位符
a = 123
print("%06d"% a)
print("%2d"% a)
#   表示输出6位数，不足用0补全。输出少于原位数时，按原位数输出
b = 1.256415611
print("%f"% b)
#   默认六位小数，四舍五入原则
print("%.3f"% b)
#   输出三位小数，四舍五入原则
print("我是%%"% ())
#   输出我是%
print(f"我的名字是{name}，我今年{age}岁了。")
#   f表示格式化输出










