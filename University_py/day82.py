import turtle as t
t.setup(600,600,10,20) 
t.pensize(7)
t.speed(5)   # 画笔速度0~10
t.circle(60,360)   # 半径为60，角度为360的园，默认为逆时针
t.goto(9,10)  #移动到坐标9，10 
t.setx(10)  #移动横坐标
t.sety(9)   #移动纵坐标
t.setheading(90)   # 修改画笔绝对角度，向右为0，正方向为逆时针
t.undo()   # 撤销画笔的最后一部动作

t.fd(200)
t.left(90)
t.penup()  # 提起画笔  相当于不画  简写pu或up


t.fd(100)
t.pendown()   # 放下画笔  相当于开始画   简写down或pd
t.left(90)
t.fd(200)
t.circle(60,steps=6)   # 画一个内切正多边形 
t.home()  # 画笔回到原点，朝右
