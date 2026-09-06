

import day74
day74.fun1()  #调用day74中的fun1函数

import day74 as t   # 给day74起别名t
t.fun1()   #调用day74中的fun1函数

from day74 import *  # 引用day74中的所有内容


from day74 import fun1,fun2,fun3,fun4  # 引用来自day74中的函数
fun4()  # 调用来自day74中的函数
