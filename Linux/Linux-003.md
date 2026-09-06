# 安装软件
Linux软件安装一般有四种；
1) 第一种为解压缩版本，IDEA，pycharm等工具采用的方式
2) 第二种是rpm、deb安装程序，使用dpkg命令或者linux 软件市场程序安装；
3) 第三种使用apt从软件仓库下载安装，本质上是deb的安装方式，自动安装依赖； 
4) 第四种是源码编译安装；

## 基于解压缩安装方式
官网下载最新的idea、pycharm等开发工具
```
tar -xvf idea-2026.1.2.tar.gz -C ~/DevTools
```

## 基于dpkg安装软件
QQ官网下载qq，微信软件
```
sudo dpkg -i QQ_3.2.29_260528_amd64_01.deb
```

搜索已安装的软件
```
sudo dpkg -l | grep QQ
```

## 基于apt的安装方式
采用apt从软件仓库下载安装，安装之前需要update本地仓库信息
安装openjdk-8
```
sudo apt update
sudo apt install openjdk-8-jdk openjdk-8-jdk-headless
```

apt安装管理器自动从仓库下载，并保存在 `/var/cache/apt/archives`  目录中

## 编译安装方式
以nginx为例，从官网下载最新版本nginx并安装
```
mkdir ~/Server
cd ~/Downloads
wget https://nginx.org/download/nginx-1.28.3.tar.gz
tar -xvf nginx-1.28.3.tar.gz
cd nginx-1.28.3
./configure --prefix=~/server/nginx
make && make install
```

# 远程桌面
ubuntu,debian桌面程序默认集成了gnome-remote-desktop组件，可以通过桌面设置启动远程桌面服务，该桌面服务只有当用户登录后，才会启动，不适合生成案例。   

## vnc远程桌面
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

配置xstartup，
### gnome 桌面
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

### 启动vnc
vncserver :1 -geometry 1600x900 -depth 24 -localhost no

:1 表示第一个桌面   将使用5901端口    
:2 表示第二个桌面   将使用5902端口     
-geometry 1600x900 表示分辨率    
-depth 24          表示颜色深度，最高32位    
-localhost no      表示可以外部访问，一般会配置为yes，通过ssh隧道提供ssl服务


## xrdp远程桌面
xrdp和gnome-remote会冲突，使用xrdp需要关闭gnome-remote
```
sudo apt install xrdp
sudo systemctl is-enabled xrdp
sudo systemctl status xrdp
```

部分操作系统可能出现黑屏，安装dbus-x11
```
sudo apt install dbus-x11
```


修改 `/etc/xrdp/startwm.sh` 文件，添加：
export $(dbus-launch)

修改后样子：
export $(dbus-launch)
test -x /etc/X11/Xsession && exec /etc/X11/Xsession
exec /bin/sh /etc/X11/Xsession


重启xrdp
sudo systemctl restart xrdp

# 环境变量设置
ubuntu环境变量可以配置在/etc/profile 也可以配置当前用户home的配置文件，等于~/.bashrc两个文件中
其中/etc/profile等价于全局，~/.bashrc等价于用户环境变量

## 全局配置
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
## 用户变量
```
vim ~/.bashrc
```

文件底部新增
```
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk
CLASSPATH=.
PATH=$PATH:$JAVA_HOME/bin
export JAVA_HOME CLASSPATH PATH
```
配置后，使用source ~/.bashrc生效，或者用户重新登录ssh即可.

# 常用软件安装
## http服务器
目前http服务器，有nginx、apache2，其中，apache2是老牌的http服务器，nginx属于后起只修，现在基本上国内的nginx为主   
```
sudo apt install nginx
```

## mysql服务器
```
sudo apt install mysql-client mysql-server
sudo systemctl start mysql.service
```

关于服务，centos体系mysql对应的服务名为mysqld.service，debian体系mysql对应的服务名为mysql.service，注意区别
同样的，centos体系ssh对应的服务名为sshd.service,debian体系ssh对应的服务器名为ssh.service
注意差别

切换到root用户
```
sudo -i
```

mysql，登录数据库，mysql本地用户默认和linux操作系统root用户集成，root用户登录不需要密码，可以通过修改plugin，同意登录方式

查询mysql用户信息
```
select user,host,plugin from mysql.user
```



创建用户root，允许远程登录
```
create user root@'%' identified by 'Mysql@2026'
```

给root@'%' 授权
```
grant all privileges on *.* to root@'%'；
flush privileges
```

登录
```
mysql -u root -p
```
参数 -u 值  表示登录用户    
参数 -p     表示需要密码     

远程登录
```
mysql -u root -h 192.168.199.80 -p
```
参数 -u 值  表示登录用户    
参数 -h 值  表示服务器IP地址    
参数 -p     表示需要密码     


## python 环境
```
sudo apt install python3-pip python3-venv
```

设置pip国内源，否则所有软件都会在海外下载

```
pip config set global.index-url "https://mirrors.tuna.tsinghua.edu.cn/pypi/web/simple"
```

创建虚拟环境
```
# 创建项目
mkdir myproject
cd myproject

python -m venv .venv
source ./.venv/bin/activate
pip install bs4 requests
```

编辑一下内容
```
vim http_parse.py
```

插入以下内容
```
from bs4 import BeautifulSoup
import requests

url = 'https://www.gdep.edu.cn/'
response = requests.get(url)
response.encoding = 'utf-8'
if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
   
    title_tag = soup.find('title')
   
    if title_tag:
        print(title_tag.get_text())
    else:
        print("未找到<title>标签")
else:
    print("请求失败，状态码：", response.status_code)
```



## python学习平台jupyter lab/notebook安装
```
sudo apt install python3-pip
pip install jupyterlab
```

jupyter安装在当前用户的.local/bin/下，需要修改当前用户环境变量
vim ~/.bashrc

添加变量，linux path通过冒号隔开，和windows有所区别
```
PATH=$PATH:~/.local/bin/
export PATH
```

```
source ~/.bashrc
```

运行程序，程序只允许本地运行
```
jupyter lab
```

生成配置文件
```
jupyter lab --generate-config
vim ~/.jupyter/jupyter_lab_config.py
```
找到 `c.ServerApp.ip` 将# 去掉

将监听地址修改为
```
c.ServerApp.ip = '0.0.0.0'
```

保存退出

生成密码
```
jupyter lab password
```

运行程序
```
jupyter lab --no-browser
```

windows客户机，打开浏览器，访问jupyter