from socket import*
S = socket()
S.bind(('0.0.0.0',8888))
S.listen()
s,addr = S.accept()
print(addr)
print('1.关机2.重启')
choice = input('请选择编号：')
s.send(choice.encode())