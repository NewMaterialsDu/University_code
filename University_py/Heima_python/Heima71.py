# 71.类型注解
# 用于明确标识变量、函数参数和返回值类型

a: int = 608
score: float = 78.5

names: list[str] = ["a","b","c"]
phones: set[str] = ["561456156156","56456416545"]

# 72.函数类型注解
# float为返回值类型
def calc(scores: list[int]) -> float:
    return sum(scores)/len(scores)

def calc_b(*args:tuple[str,float,int])->tuple[float,float]:
    return 

# 73.模块介绍
# 创建一个文件，作为自定义模块，引入就可以调用模块里的相关功能
import Heima_main 
Heima_main.print_add(7,8)

# 74.导入模块，可以导入部分功能，也可以全部导入。语法：

#  导入形式                     调用方式
#  import 模块名                模块名.功能名
#  import 模块名 as 别名         别名.功能名
#  form 模块名 import 功能名     功能名
#  from 模块名 功能名 as 别名     别名
#  from 模块名 import *         功能名

import random

for i in range(100):
    print(random.randint(1,100))

# 75.自定义模块

