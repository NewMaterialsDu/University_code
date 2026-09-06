# 系统常用命令
## 压缩以及解压缩
linux常见的压缩文件有.tar .tar.gz .zip .bz2 .gz .rar .7z
其中.tar .tar.gz .zip压缩格式最为常见   
.rar 为商业软件，所以，rarlinux仅仅提供简化版   
同样的文件，压缩后文件大小大致为：   
```
.tar  < .tar.gz < .bz2
```
### tar
tar --help 查看帮助
#### 解压缩
命令模板
```
解压缩文件xxx.tar.gz
tar -xvf xxx.tar.gz

解压缩并解压缩到指定目录
tar -xvf xxx.tar.gz -C ~/Downloads

解压缩并解压缩到指定目录，静默解压
tar -xf xxx.tar.gz -C ~/Downloads

-j表示打开.bz2支持
-z表示打开.gz支持，默认支持
tar -jxf xxx.bz2 -C ~/Downloads
```

#### 压缩
命令模板
```
压缩目录dir1，dir2，压缩文件命令为xxx.tar.gz
tar -cvf xxx.tar.gz dir1 dir2
```

### unzip
查询帮助，如果提升命令不存在需要通过apt安装unzip命令
```
unzip --help
```

命令例子
unzip xxxx.zip
unzip -q xxx.zip

### zip
如果提升命令不存在需要通过apt安装zip命令
```
zip --help
```
命令例子
```
zip xxx.zip file1.txt file2.txt
zip -q xxx.zip file1.txt file2.txt
压缩目录，静默压缩
zip -rq xxx.zip file1.txt file2.txt
压缩目录文件，静默压缩，最大压缩率
zip -rq9 xxx.zip file1.txt file2.txt dir
```
### unrar

sudo apt install unrar

```
显示压缩包
unrar l test.rar
在当前目录下解压缩,并解压完整路径
unrar x test.rar
解压缩到当前路径
unrar e test.rar
```

### 7z
.7z开源的压缩软件，支持mac，linux，windows，特点体积小，功能强，性能中上，没广告，简约
.7z比tar命令支持更多的压缩文件，包括zip tar tar.gz .bz2都可以使用7z命令压缩和解压缩
命令例子
```
压缩包添加文件
7z a test.7z file1.txt
压缩包删除文件
7z d test.7z file1.txt
解压缩
7z x test.7z
```

## 网络工具
查看正在监听的tcp，udp进程
netstat -tulpn | grep LISTEN

ping 检查网络是否通畅
```
ping 192.168.199.1
```

查看IP地址
```
ifconfig
ip addr show
```

查看路由信息
```
ip route
route
```

追踪网络路径
```
traceroute www.baidu.com
```

telnet远程主机端口是否可联通
```
telnet 192.168.199.80 443
```

查询域名解析，nslookup默认没有安装，第一次使用需要先安装
```
sudo apt install dnsutils

nslookup www.gdep.edu.cn
nslookup -type=MX www.gdep.edu.cn
nslookup -type=NS www.gdep.edu.cn
```

Netcat工具，启动服务，并监听9988端口
```
nc -l 9988
```

wget下载网络资源
```
wget https://mirrors.tuna.tsinghua.edu.cn/Adoptium/8/jdk/x64/linux/OpenJDK8U-jdk_x64_linux_hotspot_8u492b09.tar.gz
```

curl下载网络资源
```
curl -O https://mirrors.tuna.tsinghua.edu.cn/Adoptium/8/jdk/x64/linux/OpenJDK8U-jdk_x64_linux_hotspot_8u492b09.tar.gz
```

远程登录
```
ssh student@192.168.199.80
```

远程下载
```
scp student@192.168.199.80:/home/student/Download/openssl.tar.gz .
```

## 查看硬件信息
### 查看cpu信息
```
cat /proc/cpuinfo
```

### 查看内存信息
```
cat /proc/meminfo 
```
## 磁盘管理工具
### 查看磁盘情况
```
df
```

```
fdisk -l
```

### 查看当前目录存储情况
```
du --max-depth=1 -h
```

### 磁盘分区
vmware，点击虚拟机，属性，新增磁盘，关闭虚拟机，重新开机
#### 查看新增磁盘情况
```
fdisk -l
```

磁盘分区，对新的/dev/vdb进行分区
```
disk /dev/vdb
```
格式化
```
mkfs ext4 /dev/vdb1
```
挂载
```
mount /dev/vdb1 /opt/software
```