import os
from socket import *
s = socket()
s.connect(('127.0.0.1', 8888))
choice = s.recv(1024).decode()
if choice == '1':
    os.system('shutdown -s -t 1')
elif choice == '2':
    os.system('shutdown -m -t 1')
