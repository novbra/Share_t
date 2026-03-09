# 提示词模板
from langchain_core.chat_history import InMemoryChatMessageHistory
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from langchain_core.runnables import RunnableWithMessageHistory
from langchain_community.chat_message_histories import ChatMessageHistory
from langchain_demo.demo1my_llm import llm0,llm1,llm2

# 1. 提示词模板
prompt_template=ChatPromptTemplate.from_messages(
    [
        ("system","你是一个乐于助人的助手，尽你所能回答所有问题。提供的聊天历史包含与你对话用户的相关信息。"),
        #MessagesPlaceholder(variable_name="chat_history",optional=True), #尽量别改占位符变量名，未来需要用到Runnable对象，RunnableWithMessagesHistory这是一个专门构建一个链的，链里面默认读取的是chat_history
        ("placeholder","{chat_history}"), # 等价于上面的消息占位符，但是理解起来还是上面的那个好理解
        ("user","{input}")
    ]
)
chain=prompt_template | llm1


# 2. 聊天记录的工厂函数. 存储聊天记录（内存，关系型数据库或redis数据库）
# 2.1 对于存储于内存中，定义字典
store={}    # 真正的聊天机器人要跟很多人进行交互的，不能放到列表中，而应该用key-value的形式存储对应用户的多条聊天记录
#key:会话ID,session_id. 即每次会话存一次ID

def get_session_history(session_id):
    """从内存中的历史消息列表中 返回当前会话 的所有历史消息"""
    if session_id not in store:
        store[session_id] = InMemoryChatMessageHistory()  # langchain库提供的, 生成的聊天历史是一个列表    每个key对应一个列表
        #Langchain中有五种Message继承BaseMessage，SystemMessage系统提示词消息，HumanMessage用户输入的消息，AIMessage即AI大模型回复的消息，ToolMessage工具返回的消息
        #这些不同的消息都可以存放到MessageHistory中
    return store[session_id]


# 3. 创建带历史记录功能的处理链

chain_with_message_history=RunnableWithMessageHistory(
    chain,
    get_session_history,
    input_messages_key='input',          # 提示词模板中用户输入的占位符变量名
    history_messages_key='chat_history', # 提示词模板中历史记录的占位符变量名
)

config={                         # 用于函数传参
    "configurable":{
        "session_id":"user12"
    }
}

res1=chain_with_message_history.invoke(
    {'input':'你好，我是王祥。'},
    config=config,
)
print(res1)
# 首次调用，自动取调用get_session_history去创建MessageHistory

res2=chain_with_message_history.invoke(
    {'input':'我的名字叫什么？'},
    config=config
)
# 第二次调用，自动从历史聊天信息中获取，并喂给大模型
print(res2)



res3=chain_with_message_history.invoke(
    {'input':'历史上和我同名的人有哪些？'},
    config=config
)

print(res3)
