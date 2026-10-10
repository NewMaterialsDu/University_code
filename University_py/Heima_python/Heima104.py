# 104.界面基本布局
import os
from openai import OpenAI
import streamlit as st
# 设置页面布局
st.set_page_config(
    page_title="AI智能伴侣",
    page_icon="机器人",
    # 布局
    layout="wide",
    # 控制侧边栏的状态
    initial_sidebar_state="expanded",
    menu_items={
        
    }
)

# 大标题
st.title("AI智能伴侣")

# logo
st.logo("https://www.streamlit.io/images/brand/streamlit-mark-color.png")

# 系统提示词
system_prompt = "你是一个傲娇的AI大模型，用户通常叫你大肥鱼"

# 初始化聊天信息
if "messages" not in st.session_state:
    st.session_state.messages = []

# 展示聊天信息
for message in st.session_state.messages:   #{“role”:”user”,”content”:”你好”}
    st.chat_message(message["role"]).write(message["content"])
    # if message["role"] == "user":
    #     st.chat_message("user").write(message["content"])
    # else:
    #     st.chat_message("assistant").write(message["content"])

# 创建一个与AI模型交互的客户端对象
client = OpenAI(api_key=os.environ.get('DEEPSEEK_API_KEY'),base_url="https://api.deepseek.com")

# 聊天输入框
prompt = st.chat_input("请输入您的问题：")
if prompt: #字符串会自动转换为布尔值，非空字符串为True，空字符串为False
    # 显示用户输入的内容
    st.chat_message("user").write(prompt)
    print("-------->调用AI模型，提示词：", prompt)
    # 保存用户输入的内容到会话状态中
    st.session_state.messages.append({"role": "user", "content": prompt})

    # 调用AI模型进行处理
    response = client.chat.completions.create(
    model="deepseek-flash",
    messages=[
        {"role": "system", "content": system_prompt},
        # 把用户输入的内容和之前的聊天记录一起发送给大模型，但是数据类型是list，不能直接传入st.session_state.messages，需要用*解包成多个字典
        *st.session_state.messages
    ],
    stream=False,
    reasoning_effort="high",
    extra_body={"thinking": {"type": "enabled"}}
    )
    # 输出大模型的返回
    print("大模型返回：", response.choices[0].message.content)
    st.chat_message("assistant").write(response.choices[0].message.content)
    # 保存用户输入的内容到会话状态中
    st.session_state.messages.append({"role": "assistant", "content": response.choices[0].message.content})


# 105.界面消息展示

# 106.会话记忆问题

# 107.流式输出
