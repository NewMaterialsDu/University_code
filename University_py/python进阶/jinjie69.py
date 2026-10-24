# 69.网编，进程，线程大纲介绍

# 70.网络编程简介
# 网编三要素：IP地址，端口，协议

# 71.TCP协议介绍
# 三次握手，建立客户端 输出流 --》 输入流 服务器端 和 服务器端 输出流 --》 输入流 客户端
# 所以不在连接的时候要断四个（四次挥手）

# 72.socket套接字与TCP开发流程
# 创建socket对象

# 网络编程也叫网络通信，socket通信：通信双方都有自己的socket对象
# 数据在socket之间通过 数据包（UDP协议） 或者字节流（TCP协议）的形式进行传输
# socket可以理解为两部手机在通信

import socket
# 创建socket对象
# 参数一：Address Family，地址簇，即：IPv4 或者 IPv6，默认值：AF_INET(IPv4) AF_INET6(IPv6)
# 参数二：Socket Type ，socket类型，即TCP 或者 UDP ，默认值：SOCK_STREAM(TCP) SOCK_DORAM(UDP)
# socket_obj = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# print(socket_obj)
#
# # 73.TCP开发流程——服务端代码
# # 注意：客户端和服务端是通过字节流的形式实现的
# # 1.创建服务器端socket对象
# server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# # 2.绑定IP地址和端口号（绑定的是服务器端的IP和端口号，服务器用这个IP和端口号接受和发送数据）
# server_socket.bind(('192.168.66.236', 10086))
# # 3.设置最大监听数
# server_socket.listen(5)
# # 4.等待客户端申请建立连接（会返回一个元组,返回的元组其实是（一个新的和客户端连接的socket，（客户端IP，客户端端口号）））
# # 这里IPv4返回的是二元组，IPv6则返回的是四元组
# accept_socket , client_info = server_socket.accept()
# # 5.给客户端发送消息(这里加个b的意思是转为二进制，但是有中文不行)
# accept_socket.send(b'Hello, world')
# # 6.接受客户端的信息并打印(1024的意思是最大接受1024个字节)(后面的decode意思是将二进制解码，用utf-8格式)
# data = accept_socket.recv(1024).decode('utf-8')
# print(f"服务器端收到来自{client_info}的信息：{data}")
# # 7.释放资源(客户端关闭，服务器端一般不关闭)
# accept_socket.close()

# 74.客户端开发流程
# 1.创建客户端套接字对象
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 2.客户端连接服务器端（指定IP跟端口）
client_socket.connect(('192.168.66.236', 10086))
# 3.接受数据
client_data = client_socket.recv(1024).decode('utf-8')
print(f"客户端收到:{client_data}")
# 4.发送数据（encode是编码，utf-8格式，转为二进制）
client_socket.send("socket你好，服务器".encode('utf-8'))
# 5.关闭套接字
client_socket.close()









