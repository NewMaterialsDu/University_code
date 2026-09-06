import turtle as t

t.setup(600,600,10,20)  # 窗口宽度，窗口高度，窗口与屏幕左侧距离，窗口与屏幕顶部距离


# 前进 forward()      简写 下同  fd()
 # 后退 backward() bk()

t.forward(100)
t.fd(200)

t.bk(100)



t.left(90)
t.fd(100)
t.left(90)
t.fd(100)
t.left(90)
t.fd(100)

t.left(90)
t.fd(100)


t.bk(300)
for i in range(4):  # 循环4次
    t.fd(100)
    t.left(90)
