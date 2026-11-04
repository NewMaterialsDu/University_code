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
global_bun = 0
# 加global意思是声明为全局变量
def target_fun1():
    mutex.acquire() # 加锁
    global global_bun
    for i in range(1000000):
        global_bun += 1
    print(f"target_fun1={global_bun}")
    mutex.release() # 释放锁

def target_fun2():
    mutex.acquire()
    global global_bun
    for i in range(1000000):
        global_bun += 1
    print(f"target_fun2={global_bun}")
    mutex.release()

# if __name__ == '__main__':
#     #两个结果应为1000000，2000000
#     # 类似脏读，第一个线程还没加完1，第二个线程就读取，结果大家都返回1，数据大家读取到都变成1，但是实际上加了两次
#     #第一个线程还没执行完一个完整的动作就被第二个线程抢了资源
#     threading.Thread(target=target_fun1).start()
#     threading.Thread(target=target_fun2).start()
#
#     # t1 = threading.Thread(target=target_fun1)
#     # t2 = threading.Thread(target=target_fun2)
#     #
#     # t1.start()
#     # t2.start()

# 96.互斥锁思想（线程同步），解决上述问题（保证同一时刻只能有一个线程去操作全局变量）
# 即在第一个线程完成一个完整的动作之前，线程二是无法读取共享的变量的
# 使用互斥锁要注意死锁问题：未在合适的地方释放锁，导致其他线程一直等待的情景
# 创建线程锁
mutex = threading.Lock()

if __name__ == '__main__':
    threading.Thread(target=target_fun1).start()
    threading.Thread(target=target_fun2).start()

# 97.进程和线程的对比
# 进程间不共享数据
# 线程间共享数据，但是要注意资源抢夺问题，可以用互斥锁
# 创建进程资源开销比创建线程的资源开销大
# 进程是操作系统资源分配的基本单位，线程是cpu调度的基本单位
# 线程不能独立执行，只能依存在进程中
# python中多进程开发比单进程多线程开发稳定性要强
# 进程:可以使用多核，资源开销大；线程：不能使用多核，资源开销小



























































