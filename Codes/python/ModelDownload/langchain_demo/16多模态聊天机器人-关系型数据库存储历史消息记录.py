# 提示词模板
from langchain_community.chat_message_histories import SQLChatMessageHistory
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from langchain_core.runnables import RunnableWithMessageHistory

from langchain_demo.demo1my_llm import llm0,llm1,llm2

# 1. 提示词模板
prompt_template=ChatPromptTemplate.from_messages(
    [
        ("system","你是一个乐于助人的助手，尽你所能回答所有问题。提供的聊天历史包含与你对话用户的相关信息。"),
        MessagesPlaceholder(variable_name="chat_history",optional=True), #尽量别改占位符变量名，未来需要用到Runnable对象，RunnableWithMessagesHistory这是一个专门构建一个链的，链里面默认读取的是chat_history
        #("placeholder","{chat_history}"), # 等价于上面的消息占位符，但是理解起来还是上面的那个好理解
        ("user","{input}")
    ]
)
chain=prompt_template | llm1


# 2. 聊天记录的工厂函数. 存储聊天记录（内存，关系型数据库或redis数据库）
# 2.1 对于存储于内存中，定义字典
store={}    # 真正的聊天机器人要跟很多人进行交互的，不能放到列表中，而应该用key-value的形式存储对应用户的多条聊天记录
#key:会话ID,session_id. 即每次会话存一次ID

def get_session_history(session_id):
    """从关系型数据库的历史消息列表中 返回当前会话 的所有历史消息"""
    return SQLChatMessageHistory(            #langchain包里的类
        session_id=session_id,
        connection_string='sqlite:///chat_history.db', ##LangChainDeprecationWarning: `connection_string` was deprecated in LangChain 0.2.2 and will be removed in 1.0. Use connection instead.
    )


# 3. 创建带历史记录功能的处理链

chain_with_message_history=RunnableWithMessageHistory(
    chain,
    get_session_history,
    input_messages_key='input',          # 提示词模板中用户输入的占位符变量名
    history_messages_key='chat_history', # 提示词模板中历史记录的占位符变量名
)


res1=chain_with_message_history.invoke(
    {'input':'你好，我是王祥。'},
    config={                         # 用于函数传参
    "configurable":
        {"session_id":"user123"}
    }
)
print(res1)
# 首次调用，自动取调用get_session_history去创建MessageHistory

res2=chain_with_message_history.invoke(
    {'input':'我的名字叫什么？'},
    config={                         # 用于函数传参
    "configurable":
        {"session_id":"user123"}
    }
)
# 第二次调用，自动从历史聊天信息中获取，并喂给大模型
print(res2)

res3=chain_with_message_history.invoke(
    {'input':'历史上和我同名的人有哪些？'},
    config={                         # 用于函数传参
    "configurable":
        {"session_id":"user123"}
    }
)

print(res3)


