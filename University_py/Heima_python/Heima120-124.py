# 120.爬虫介绍

# 121.爬虫概述
# robots协议（也称为爬虫协议爬虫规则）：是网站根目录下存放的一份文本文件robots.txt，用于告诉爬虫哪些页面可以抓取，哪些页面不能抓取（君子协议）
# User-agent：用户代理，通过请求头确认爬虫的类型
# Disallow：禁止访问的资源
# Allow：允许访问的资源
# Sitemp：网站地图，帮助爬虫更高效地获取网站内容
# Craw-delay：爬取间隔时间，避免频繁访问造成网站压力过大
# 例如：通用规则和针对Google爬虫的特定规则
# User-agent：*
# ...
# ...
# ...
# 
# User-agent:Mediapartners-Goole
# ...
# ...
# ...

# 122.入门程序
# 要用到requests库，发送网络请求，要pip安装
import requests
# 定义URL
target_url = "https://www.tiobe.com/tiobe-index/"
# 发送请求，获取数据
response = requests.get(target_url)
# 输出数据到控制台
# print(response.text)

# 123.网页结构讲解

# 124.网页解析
# lxml：是一个高性能的HTML/XML文档的解析库，支持基于Xpath语法来解析和获取网页数据
# 安装：pip install lxml
# Xpath：是一种存在于HTML/XML文档中导航或定位元素的查询语言，让你能够精确的定位文档中的特定元素、属性或文本
from lxml import html
# 读取html文件
with open("C:/Users/NewMaster/Desktop/University-code-study/University_code/University_H5_C3_JS/dayiqimo/html/qimo02.html","r",encoding="utf-8") as f:
    html_text = f.read()

    # 解析html的文本，将其转换为一个文档
    document = html.fromstring(html_text)

    # 解析表头 - Xpath语法
    li_list = document.xpath("//div/ul/li/a/text()")
    print(li_list)

    # 解析表格中的数据 - Xpath语法
    p_list = document.xpath("//div/div/div/p/text()")
    print(p_list)




