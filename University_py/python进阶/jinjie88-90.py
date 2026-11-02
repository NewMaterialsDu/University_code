# 88.线程介绍
# 一个进程至少有一个线程
# 线程之间数据是共享的，因为都是用同一个进程的数据
# 线程是依附于进程执行的，是cpu调度的基本单元

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






















