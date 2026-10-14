# 104.界面基本布局
# 105.界面消息展示
# 106.会话记忆问题
# 107.流式输出
# 108.侧边栏制作
# 109.会话管理-思路分析

# 113.会话管理
# 114.新建会话
# 115.展示会话
# 116.加载会话
# 117.删除会话
# 118.功能优化与小结
# 119.文件操作知识扩展
import datetime
import os
from openai import OpenAI
import streamlit as st
import json

SESSIONS_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "sessions")

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

# 生成会话标识函数
def generate_session_name():
    st.session_state.current_session = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S")

# 保存会话信息函数
def save_session():
    if st.session_state.current_session:
                # 新建一个会话对象，存储
                session_date = {
                    "nick_name":st.session_state.nick_name,
                    "nature":st.session_state.nature,
                    "current_session":st.session_state.current_session,
                    "messages":st.session_state.messages
                }
                os.makedirs(SESSIONS_DIR, exist_ok=True)
                # 保存会话数据
                session_path = os.path.join(SESSIONS_DIR, f"{st.session_state.current_session}.json")
                with open(session_path, "w", encoding="utf-8") as f:
                    json.dump(session_date,f,ensure_ascii=False,indent=4)


# 大标题
st.title("AI智能伴侣")

# logo
st.logo("https://www.streamlit.io/images/brand/streamlit-mark-color.png")

# 系统提示词
system_prompt = """
                你%s，现在是用户的真实伴侣，请完全带入伴侣角色
                规则：
                    1.匹配用户的语言
                    2.回复简短，像微信聊天一样
                    3.有需要的话可以用emoji表情
                    4.用符合伴侣身份的语气和性格方式回复用户
                    5.回复的内容要充分体现伴侣的性格
                伴侣性格：
                    %s
                你必须严格遵守以上规则回复用户
                """

# 初始化聊天信息
if "messages" not in st.session_state:
    st.session_state.messages = []

# 昵称
if "nick_name" not in st.session_state:
    st.session_state.nick_name = ["deepseek"]
# 性格
if "nature" not in st.session_state:
    st.session_state.nature = ["傲娇，可爱"]

#会话标识
if "current_session" not in st.session_state:
    # 获取当前系统时间，然后格式化输出:年-月-日_时-分-秒
    generate_session_name()

# 展示聊天信息
for message in st.session_state.messages:   #{“role”:”user”,”content”:”你好”}
    st.chat_message(message["role"]).write(message["content"])
    # if message["role"] == "user":
    #     st.chat_message("user").write(message["content"])
    # else:
    #     st.chat_message("assistant").write(message["content"])

# 创建一个与AI模型交互的客户端对象
client = OpenAI(api_key=os.environ.get('DEEPSEEK_API_KEY'),base_url="https://api.deepseek.com")

# 左侧侧边栏
with st.sidebar:
    # AI控制面板
    st.subheader("AI控制面板")

    # 新建会话
    if st.button("新建会话",width="stretch"):
        # 1.保存当前会话信息
        save_session()

        # 2.创建新的会话
        st.session_state.messages = []
        generate_session_name()
        save_session()





    st.subheader("伴侣信息")
    # 昵称输入框
    nick_name = st.text_input("昵称",placeholder="请输入昵称",value=st.session_state.nick_name[0] if st.session_state.nick_name else "")
    if nick_name:
        st.session_state.nick_name = [nick_name]

    # 性格
    nature = st.text_area("性格",placeholder="请输入性格描述",value=st.session_state.nature[0] if st.session_state.nature else "")
    if nature:
        st.session_state.nature = [nature]

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
        {"role": "system", "content": system_prompt % (st.session_state.nick_name, st.session_state.nature)},
        # 把用户输入的内容和之前的聊天记录一起发送给大模型，但是数据类型是list，不能直接传入st.session_state.messages，需要用*解包成多个字典
        *st.session_state.messages
    ],
    stream=True,
    reasoning_effort="high",
    extra_body={"thinking": {"type": "enabled"}}
    )

    # # 输出大模型的返回(这是非流式输出的解析方式)
    # print("大模型返回：", response.choices[0].message.content)
    # st.chat_message("assistant").write(response.choices[0].message.content)
    
    # # 保存用户输入的内容到会话状态中
    # st.session_state.messages.append({"role": "assistant", "content": response.choices[0].message.content})

    # 流式输出大模型的返回
    response_message = st.empty()   #创建一个空的容器
    full_response = ""
    for chunk in response:
        if chunk.choices[0].delta.content is not None:
            content = chunk.choices[0].delta.content
            full_response += content
            response_message.chat_message("assistant").write(full_response)
    # 保存用户输入的内容到会话状态中
    st.session_state.messages.append({"role": "assistant", "content": full_response})


