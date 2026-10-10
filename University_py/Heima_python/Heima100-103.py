# 100.实战-streamlit入门
# 导入前要先安装
import streamlit as st

# 基于streamlit中提供的API构建web应用，运行：streamlit run 文件名.py
# 大标题
st.title("Streamlit入门演示")
st.header("Streamlit 一级标题")
st.subheader("Streamlit 二级标题")

# 101.Streamlit基础用法
# 段落文字
st.write("Streamlit是一个非常好用的Python库，可以快速构建Web应用。")
# 显示图片
st.image("https://www.streamlit.io/images/brand/streamlit-mark-color.png")
# 音频
st.audio("https://www.soundhelix.com/examples/mp3/SoundHelix-Song-1.mp3")
# 视频
st.video("https://www.youtube.com/watch?v=JwSS70SZdyM")
# logo
st.logo("https://www.streamlit.io/images/brand/streamlit-mark-color.png")
# 表格
st.table(
    {
        "姓名": ["张三", "李四", "王五"], 
          "年龄": [18, 19, 20]
          }
          )
# 输入框
name = st.text_input("请输入您的姓名：")
age = st.number_input("请输入您的年龄：")
if st.button("提交"):
    st.write(f"您好，{name}！您今年{age}岁。")
#密码输入框 
password = st.text_input("请输入您的密码：", type="password")
# 单选按钮
gender = st.radio("请选择您的性别：", ("男", "女"))

# 102.Streamlit页面设置
st.set_page_config(
    page_title="Streamlit入门演示",
    page_icon=":smiley:",
    # 布局
    layout="wide",
    # 控制侧边栏的状态
    initial_sidebar_state="expanded",
    menu_items={
        "Get Help": "https://www.streamlit.io/help",
        "Report a bug": "https://www.streamlit.io/bug",
        "About": "这是一个Streamlit入门演示应用。"
    }
)

# 103.安装AI插件
