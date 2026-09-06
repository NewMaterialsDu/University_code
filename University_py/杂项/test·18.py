# 创建抛出异常步骤：
# 1.创建一个Exception('xxx')对象，xxx---异常提示信息
# 2.raise抛出这个对象（异常对象）
# def funa():
#     raise Exception('抛出一个异常')
#     print('ohhkjhjihui')
# funa()
# # 这里执行了raise语法，print不再运行



#  案例：密码长度不足会报错
#  自定义抛出异常，并捕获



def funb():
    mima = input('请输入密码：')
    if len(mima) >= 6:
        return "密码输入成功"

    else:
        raise Exception('请输入6位及以上的密码')
# print(funb())
#  密码长度检测,但是报错无法继续运行
try:
    print(funb())
except Exception as e:
    print(e)
# try是异常捕获
# try 后面是可能产生异常的代码块
# except Exception as e 后面则是捕获异常后的处理





#
#





