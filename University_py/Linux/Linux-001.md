# 系统常用命令
## 查询当前登录用户
查询当前登录用户基本信息，含IP地址
```
who
```
查询登录用户名
```
whoami
```
## 文件系统操作
### 目录创建
创建目录data
```
mkdir data
```
创建子目录，如果上级目录不存在，一并创建
```
mkdir -p ./data/logs
```


### 文件创建
创建空白文件，字节数为0
```
touch file.txt
```
使用echo，文件字节数为1
```
echo > file.txt
echo "hello" >  file.txt
```

### 文件删除
```
rm -f file.txt
```
-f 强制实行，不用询问，有点风险


### 目录删除
```
rm -rf file.txt
```


-r 表示删除目录
-f 表示强制性


### 目录列出
列出(普通形式)
```
ls
```

列出（列表形式）
```
ls -l
```
列出，含隐藏目录
```
ls -la
```
列出，排序，正序
```
ls -lt
```
列出，倒序
```
ls -ltr
```

## 目录，文件移动
将文件移动到当前用户home目录的Downloads目录中
```
mv file.txt ~/Downloads/
```
命令可以增加 `-f` `-u` 参数   
-f 强制，存在同文件替换   
-u 如果移动文件更加新，替换   

### 文件查看
在窗口将文件打印
```
cat  file.txt
```
在串口将文件打印，之显示包含key的内容
```
cat file.txt | grep key
```
逐页显示
按照屏幕高度自动分页，按键盘向下键（如果不行使用空格键），每次一页
file.txt数据量可能不够，可以进入/var/log找一个log文件测试
```
more file.txt
```
每页10行
```
more -10 file.txt
```
按键盘方向下键（如果不行使用空格键），每次10行
分页显示file.txt
```
less file.txt
```

查看文件头部,前10行
```
head -n 10 file.txt
```

查看文件最后50行
```
tail -n 50 file.txt
```

查看文件最后100行，实时查询，文件有变化，实时输出，日志查询最有用的一个工具
```
tail -100f file.txt
```

### 文件查询
从当前目录开始查询，查找名字为file.txt的文件
```
find ./ -name file.txt
```
### 文件排序
执行下面语句生成`file.txt`

```
echo 'https://www.gdep.edu.cn
https://www.bing.com
https://www.google.com
https://www.baidu.com' > file.txt
```

执行下面命令，看看差异
```
sort file.txt
sort -r file.txt
```

### 文件比较
使用comm比较文件，需要两个文件都按照排序排列好
执行下面语句生成两个文件    
文件filea.txt
```
echo 'https://www.baidu.com
https://www.bing.com
https://www.gdep.edu.cn
https://www.google.com' > filea.txt
```
文件fileb.txt
```
echo '
https://www.bing.com
https://www.gdep.edu.cn
https://www.google.com
https://www.sogou.com' > fileb.txt
```

执行下面语句，感受差异性
```
comm filea.txt fileb.txt
comm -12 filea.txt fileb.txt
comm -3 filea.txt fileb.txt
```

### 文件编辑
vim比vi容易使用，ubuntu默认可能没有安装，需要安装
```
vim file.txt
```
按i进入编辑模式   
esc退出编辑模式   
dd删除行并上移
D删除行，变空行

:q 退出   
:q! 不保存退出   
:wq 保存退出   
:wq! 强制保存（针对只读文件）    
:set paste 进入粘贴模式    
:set number  显示行号   
:set nonumber 不要显示行号   
上面的指令有简的写法，自己查询，不推荐，原始写法可读性更好

其他编辑器
`nano` `emacs`  自行学习

## 运维相关
### 新增用户
新增用户newUserId
```
useradd -m newUserId -s /bin/bash
```

新增用户newUserId，加入到sudo组中，可以执行管理员权限
```
useradd -m newUserId -G sudo -s /bin/bash
```

新增用户newUserId，禁止登陆
```
useradd -s /sbin/nologin newUserId
```

删除用户
```
userdel newUserId
userdel -r newUserId
userdel -r -f newUserId
```

### 修改文件归属
在Linux系统中，谁创建的用户归谁，但是文件可以修改所有者
```
chown student:student ./data
chown -R student:student ./data
```

### 修改文件权限

初学者建议只需要读懂下面几个授权命令即可
```
可执行
chmod +x myshell.sh

只有我有读写权限
chmod 600 ./data

#只有我能写，其他人能读能执行，但是不能写
chmod 755 /etc/supervisor/supervisord.conf

#不管了，谁都可以
chmod 777 ~/resources
```
说明
```
-rw------- (600)    只有拥有者有读写权限。
-rw-r--r-- (644)    只有拥有者有读写权限；而属组用户和其他用户只有读权限。
-rwx------ (700)    只有拥有者有读、写、执行权限。
-rwxr-xr-x (755)    拥有者有读、写、执行权限；而属组用户和其他用户只有读、执行权限。
-rwx--x--x (711)    拥有者有读、写、执行权限；而属组用户和其他用户只有执行权限。
-rw-rw-rw- (666)    所有用户都有文件读、写权限。
-rwxrwxrwx (777)    所有用户都有读、写、执行权限。
```

### 修改系统时间
修改时间，这个命令少用，因为在怎么用也没啥用，系统有同步时钟
```
sudo date -s 21:00
sudo date -s 2025-12-30
```
写入硬件时钟,bios
```
sudo hwclock -w
```
上面的修改，随着下一次时间同步，自动恢复时钟

时钟同步
```
sudo ntpdate -u time.pool.aliyun.com
```
如果提升ntpdate命令不存在，需要安装
```
sudo apt install ntpdate
```
### 修改时区
```
timedatectl
```

如果时区不是shagnhai，需要指定
```
sudo timedatectl set-timezone Asia/Shanghai
```

### 修改设备名称
```
查询主机名称
hostnamectl status

设置主机名称
sudo hostnamectl hostname httpserver
```

手动方式
```
sudo vim /etc/hostname
```

修改主机名称需要重启

### 修改路由表
sudo vim /etc/hosts

添加
```
127.0.0.1   student.baidu.com
```

```
ping student.baidu.com
```

### 查看网络信息
```
ifconfig

ip addr show
```

查看网关
```
ip route
```

### 查看进程

```
ps -ef | grep nginx

netstat -tulpn | grep LISTEN | grep nginx
```

### 配置网络地址相关
debian和ubuntu网络配置不一样   
```
cd /etc/netplan/
```
下面是配置需要调整网卡名称，IP地址，网关，dns(例子)
```
network:
  renderer: networkd
  ethernets:
    enp1s0:
      dhcp4: false
      addresses: 
        - 192.168.199.80/24
      routes: 
        - to: default
          via: 192.168.199.1
      nameservers:
        addresses: [192.168.199.1, 114.114.114.114]
  version: 2
```
vmware修改成功案例
```
network:
  version: 2
  renderer: NetworkManager
  ethernets:
    ens33:
      dhcp4: false
      addresses:
        - 192.168.32.135/24
      routes:
        - to: default
          via: 192.168.32.2
      nameservers:
        addresses: [192.168.32.2, 114.114.114.114]
```


接受网络修改，生效
```
sudo netplan apply
```


### 防火墙
ubuntu默认使用ufw防火墙，centos默认使用firewall防火墙   
```
sudo systemctl status ufw
或
sudo ufw status
```

开机自动启动
```
sudo ufw enable
```
禁止开机启动
```
sudo ufw disable
```

开放22，80，443端口
```
sudo ufw allow 22,80,443/tcp
```
拒绝3306端口对外提供服务
```
sudo ufw deny 3306/tcp
```

允许网段访问
```
sudo ufw allow from 192.168.199.0/24
```

允许特定地址访问
```
sudo ufw allow from 192.168.199.80
```

重置配置的规则，ufw会自动关闭，并且禁止开机启动
```
sudo ufw reset
```

删除特定规则
```
sudo ufw delete allow 22/tcp
```


### 安装软件
Linux软件安装一般有四种；
1) 第一种为解压缩版本，IDEA，pycharm等工具采用的方式
2) 第二种是rpm、deb安装程序，使用dpkg命令或者linux 软件市场程序安装；
3) 第三种使用apt从软件仓库下载安装，本质上是deb的安装方式，自动安装依赖； 
4) 第三种是源码编译安装；

官网下载最新的idea、pycharm等开发工具
```
tar -xvf idea-2026.1.2.tar.gz -C ~/DevTools
```

QQ官网下载qq，微信软件
```
sudo dpkg -i QQ_3.2.29_260528_amd64_01.deb
```

采用apt从软件仓库下载安装
安装openjdk-8
```
sudo apt install openjdk-8-jdk openjdk-8-jdk-headless
```
apt安装管理器自动从仓库下载，并保存在 `/var/cache/apt/archives`  目录中

编译安装方式
以nginx为例，从官网下载最新版本nginx并安装
```
wget https://nginx.org/download/nginx-1.28.3.tar.gz
mkdir ~/server
tar -xvf nginx-1.28.3.tar.gz
cd nginx-1.28.3
./configure --prefix=~/server/nginx
make && make install
```

### 远程桌面
ubuntu,debian桌面程序默认集成了gnome-remote-desktop组件，可以通过桌面设置启动远程桌面服务，该桌面服务只有当用户登录后，才会启动，不适合生成案例。   

#### vnc远程桌面
```
sudo apt install tigervnc-standalone-server tigervnc-common
```

ubuntu 24需要额外安装x11
```
sudo apt install dbus-x11 dbus
```
设置访问密码
```
vncpasswd
```

配置xstartup，gnome桌面
```
#!/bin/sh

test x"$SHELL" = x"" && SHELL=/bin/bash
test x"$1"     = x"" && set -- default

unset SESSION_MANAGER
unset DBUS_SESSION_BUS_ADDRESS

vncconfig -iconic &
"$SHELL" -l << EOF
export XDG_SESSION_TYPE=x11
export GNOME_SHELL_SESSION_MODE=ubuntu
dbus-launch --exit-with-session gnome-session --session=ubuntu
EOF
vncserver -kill $DISPLAY
```

#### xface 桌面
```
#!/bin/bash

xrdb $HOME/.Xresources
startxfce4 &
```

xrdp远程桌面

```
sudo apt install xrdp
sudo systemctl is-enabled xrdp
sudo systemctl status xrdp
```

### 环境变量
ubuntu环境变量可以配置在/etc/profile 也可以配置在~/.bashrc两个文件中
其中/etc/profile等价于全局，~/.bashrc等价于用户环境变量

```
vim /etc/profile
```

文件底部新增
```
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk
CLASSPATH=.
PATH=$PATH:$JAVA_HOME/bin
export JAVA_HOME CLASSPATH PATH
```

使其生效并验证
```
source /etc/profile
echo $JAVA_HOME
```

~/.bashrc 配置后，仅需要让用户重新登录ssh即可.