mkdir ~/Tools

上传node-16压缩包到Downloads目录
```
tar -xvf  node-v24.18.0-linux-x64.tar.xz -C ~/Tools
cd ~/Tools
mv node-v24.18.0-linux-x64 node-v24
```


cd  ~/
vim .bashrc
最下面添加西面内容

```
NODEJS_HOME=/home/ubt/Tools/node-v24
PATH=$PATH:$NODEJS_HOME/bin
export NODEJS_HOME PATH
```

```
source ~/.bashrc
```

```
npm config set registry npm config set registry https://registry.npmmirror.com
```

安装依赖

```
npm install -g pnpm

pnpm install
```

启动项目

```
npm run dev
```

打包项目

```
npm run build
```