import turtle as t

t.setup(600,600,10,20)  # 窗口宽度，窗口高度，窗口与屏幕左侧距离，窗口与屏幕顶部距离
t.pensize(2)  # 画笔粗细
t.width(9)  # 画笔粗细的缩写
t.pencolor("blue")
t.pencolor(1,0.5,0.6)  #改变画笔颜色,红绿蓝组合（0~~1）
t.color("red")  # 设置填充的颜色，也可以组合，同上

t.write("呵呵")  # 写字
t.begin_fill()  #  开始填充

for i in range(4):   # 循环4次
    t.fd(100)
    t.left(90)

t.end_fill() # 填充结束
t.hideturtle()  # 隐藏画笔
t.showturtle()  # 显示画笔
t.write("呵呵")


print(t.filling())   # 返回填充状态
t.clear()  # 清空内容，但不改变画笔位置
t.rese()   # 清空内容，并重置位置状态为默认值