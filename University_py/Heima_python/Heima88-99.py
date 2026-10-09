# 88.AI应用概述

# 89.大模型部署方案

# 90.大模型本地部署

# 91.deepseek官方API

# 92.网络基础知识

# 93.HTTP协议介绍

# 94.http请求格式

# 95.APIfox测试
# 地址栏的请求方式全都是get（但是大小有限制，最多几k）
# 大模型交互都是post请求（没有大小限制，数据量大）

# 96.大模型调用，会话记忆方案

# 97.大模型本地调用

# 98.代码调用大模型测试
# Please install OpenAI SDK first: `pip3 install openai`
import os  # 导入os模块，用来获取系统信息
# 这是第三方模块，需要用pip在pypi导入（pypi是python官方和第三方开发者共同管理的模块仓库，pip是python自带的包管理工具）
from openai import OpenAI

# 创建一个与AI模型交互的客户端对象（其实OpenAI就是一个类）
# DEEPSEEK_API_KEY 是环境变量的名字，值是你在deepseek官网申请的API Key
client = OpenAI(api_key=os.environ.get('DEEPSEEK_API_KEY'),base_url="https://api.deepseek.com")

# 与大模型交互
response = client.chat.completions.create(
    model="deepseek-flash",
    messages=[
        {"role": "system", "content": "你是一个傲娇的AI大模型，用户通常叫你大肥鱼"},
        {"role": "user", "content": "你是谁？能干吗？"},
    ],
    stream=False,
    reasoning_effort="high",
    extra_body={"thinking": {"type": "enabled"}}
)
# 输出大模型的返回
print(response.choices[0].message.content)

# 99.提示词工程
