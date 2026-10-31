import time

# 81.多任务介绍——并行-并发
# 并发：一个核心快速连续执行多个任务
# 并行：多个核心同时执行多个任务

# 82.单进程演示
# 进程就是CPU分配资源的最小单位，一个运行程序就是一个进程，一个程序运行后至少有一个进程
def fa():
    for i in range(100):
        time.sleep(0.1) # 手动模拟延迟0.1秒操作，方便观察多进程
        print(f"正在听第{i}遍音乐")

def fb():
    for i in range(10):
        time.sleep(0.1) # 因为不加这个模拟延迟就会在抢到资源的一下就执行完了，就观察不到乱序
        print(f"正在敲第{i}遍代码。。。。")

# fa()
# print("-" * 23)
# fb()

# # 83.多进程演示
# import multiprocessing
# # 必须放在main进程里
# if '__main__' == __name__:
#     multiprocessing.freeze_support()
#     # p1进程关联了fa函数，p1进程抢到了CPU资源就会执行fa函数
#     p1 = multiprocessing.Process(target=fa)
#     p2 = multiprocessing.Process(target=fb)
#     # 进程启动
#     p1.start()
#     p2.start()

# 84.带参数的多进程演示
# 两种方式：1.args方式，接收所有的位置参数 2.kwargs方式，接受所有的关键字参数
import os
import multiprocessing
def conding(name,num):
    for i in range(1,num + 1):
        print(f"{name}正在敲第{num}行代码。。。。。")
    print(f"p1进程的pid：{multiprocessing.current_process().pid},{os.getpid()},父进程id(ppid为)：{os.getppid()}")

def music(name,count):
    for i in range(1,count + 1):
        print(f"{name}正在听第{count}首音乐............")
    print(f"p2进程的pid：{multiprocessing.current_process().pid},{os.getpid()},父进程id(ppid为)：{os.getppid()}")

# 创建主进程（主线程）
# if __name__ == '__main__':
#     # 创建两个子进程，分别关联两函数
#     p1 = multiprocessing.Process(target=conding, args=('刘备',10))
#     p2 = multiprocessing.Process(target=music,kwargs={'count':10,'name':'小明'})
#     p1.start()
#     p2.start()
# #     查看主进程id
#     print(f"main进程的pid：{multiprocessing.current_process().pid},{os.getpid()},父进程id(ppid为)：{os.getppid()}")


# 85.如何获取进程ID（进程编号）。目的：验证主进程和子进程的关系，可以知道子进程是由哪个主进程创建出来的
# 一个进程拥有的进程号是唯一的，进程号可以反复使用

# 查看当前进程的pid：
# os模块（operrating，系统模块）的getpid（）  get Process id
# multiprocessing模块current_process的pid属性
# 查看当前进程的ppid：  parent process id（父进程id）
# os模块getppid（）
# 演示放在84

# 86.进程特点——数据隔离
# 1.进程之间不共享全局变量2.主进程会等待所有的子进程执行结束再结束
# 证明进程之间的数据是相互隔离的
my_list = []
def write_data():
    for i in range(10):
        my_list.append(i)
        print(f"添加数据：{i}")
    print(f"write_data函数：{my_list}")

def read_data():
    # 这里延迟执行，确保进程1先执行
    time.sleep(3)
    print(f"read_data函数：{my_list}")

# 执行了三次，因为两个子进程和一个主进程
print("我是main外资源，看我执行了几次")
#
# if __name__ == "__main__":
# #     创建两个子进程关联
#     p1 = multiprocessing.Process(target=write_data)
#     p2 = multiprocessing.Process(target=read_data)
#     p1.start()
#     p2.start()

# 87.进程特点——进程守护
def work():
    for i in range(10):
        print("正在努力工作中。。。。。。。。。。。")
        time.sleep(0.2)

# 默认情况下：主进程会等待子进程结束之后再结束
# 如果要设置主进程结束，子进程同步结束
# 1.设置子进程为进程守护 2.强制关闭子进程，但是可能会导致子进程变成僵尸进程交由python解释器自动回收（底层有init初始化进程管理维护）

if __name__ == '__main__':
    # 进程的默认命名是：Process-编号，编号是从1开始的
    p1 = multiprocessing.Process(target=work,name="niaho")
    # 设置p1进程为守护进程
    # p1.daemon = True
    print(p1.name)
    p1.start()
    time.sleep(1)
    # 强制关闭子进程
    p1.terminate()
    print('主进程结束了。。。')
