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
# 每一个python文件就是一个模块，可以导入使用

# 76.python软件包：本质是一个文件夹（本质也是一个模块），可以用来管理模块（python文件），文件夹下面还包含一个__init__.py文件
# 包的导入方式
# 导入形式                          调用方式
# import 包名.模块名                包名.模块名.功能名
# from 包名 import 模块名           模块名.功能名
# from 包名 from *                  模块名.功能名
# from 包名.模块名 import 功能名     功能名
# from 包名.模块名 import *         功能名

# 注意：使用from 包名 from * 方式导入模块时，需要在包下的 __init__.py文件 下写__all__ = ["需要导入的模块名字"]
# 如果包不在当前文件夹，可以用绝对路径，比如：文件夹.文件.模块
# 当导入一个模块时，Python 会按照以下顺序查找模块：

# 当前目录。

# 环境变量 PYTHONPATH 指定的目录。

# Python 标准库目录。

# .pth 文件中指定的目录。



