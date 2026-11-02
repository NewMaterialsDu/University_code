# 88.线程介绍
# 一个进程至少有一个线程
# 线程之间数据是共享的，因为都是用同一个进程的数据
# 线程是依附于进程执行的，是cpu调度的基本单元
import time

# 89.线程无参入门
import threading
def conding():
    for i in range(10):
        print(f"正在敲第{i}遍代码。。。。。。。")

def music():
    for i in range(10):
        print(f"正在听第{i}遍音乐。。。。。。。。")

# if __name__ == '__main__':
#     t1 = threading.Thread(target=conding)
#     t2 = threading.Thread(target=music)
#     # 启动后才有资格抢资源
#     t1.start()
#     t2.start()

# 90.线程带参数入门
# 跟进程一样，args位置传参，kwargs关键字传参

# 91.生成器与正则表达式
# 扩展题讲解

# 92.线程特点-随机性
# 线程之间执行是无序的，主线程会等待所有的子线程执行结束再结束，(同一个进程间)线程之间共享全局变量，多线程之间共享全局变量数据出现错误问题

def print_info():
    time.sleep(0.2)
    # 获取当前线程对象
    current_thread = threading.current_thread()
    # 打印当前线程
    print(current_thread)

# if __name__ == '__main__':
#     # 创建10个线程,启动发现是随机的
#     for i in range(10):
#         t = threading.Thread(target=print_info)
#         t.start()

# 93.线程守护
# 默认情况下，主线程会等待所有的子线程结束再结束
def work():
    for i in range(10):
        time.sleep(0.2)
        print("工作中。。。。。。。。")
#
# if __name__ == '__main__':
#     # 守护线程写法1：
#     t = threading.Thread(target=work,daemon=True)
#     # 守护线程写法2：(这里出现一个横杠是因为已经过时了，所以是官方不建议使用，因为以后可能会被删掉)
#     # t = threading.Thread(target=work)
#     # t.setDaemon(True)
#     # t.daemon = True #现在推荐用这个
#     t.start()
#
#     # 设置主线程休眠1秒
#     time.sleep(1)
#     # 设置主线程结束标志
#     print("主线程结束了。。。。。。。。。")

# 94.（同一个进程内）线程数据之间全局变量数据共享
my_list = []

def write_data():
    for i in range(1,6):
        my_list.append(i)
        print("写入数据：",i)
    print(f"write_data()函数：{my_list}")

def read_data():
    # 加入休眠，确保write_data函数执行结束之后在结束
    time.sleep(2)
    print(f"read_data()函数：{my_list}")

# if __name__ == '__main__':
#     t1 = threading.Thread(target=write_data)
#     t2 = threading.Thread(target=read_data)
#     t1.start()
#     t2.start()

# 95.操作共享全局变量可能会出现的问题

































































