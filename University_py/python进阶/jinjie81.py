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

# 83.多进程演示
import multiprocessing
# 必须放在main进程里
if '__main__' == __name__:
    multiprocessing.freeze_support()
    # p1进程关联了fa函数，p1进程抢到了CPU资源就会执行fa函数
    p1 = multiprocessing.Process(target=fa)
    p2 = multiprocessing.Process(target=fb)
    # 进程启动
    p1.start()
    p2.start()

# 84.


















