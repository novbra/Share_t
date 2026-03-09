# 提示词模板
from langchain_community.chat_message_histories import SQLChatMessageHistory
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from langchain_core.runnables import RunnableWithMessageHistory, RunnablePassthrough

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


# 3. 创建带历史记录功能的处理链，历史记录会被自动处理，如果chat_history被执行clear，数据库中也会被清除
chain_with_message_history=RunnableWithMessageHistory(
    chain,
    get_session_history,
    input_messages_key='input',          # 提示词模板中用户输入的占位符变量名
    history_messages_key='chat_history', # 提示词模板中历史记录的占位符变量名
)



# 4.剪辑和摘要上下文，历史记录。：保留最近的前n条消息记录

def summarize_messages(current_input):
    """剪辑和摘要上下文，历史记录"""
    #大模型总结前面的聊天消息或用知识图谱模型来总结

    # 获取当前会话ID
    session_id=current_input['config']['configurable']['session_id']     # 待会需将config的信息也扔到input的字典中

    if not session_id:
        raise ValueError("必须通过config参数提供session_id")

    #获取当前会话ID的所有历史聊天记录
    chat_history=get_session_history(session_id)    # 获取到的是ChatHistory对象，并非消息
    # 获取到的chat_history是引用对象还是复制的对象
    stored_messages=chat_history.messages           # 需要获取History对象中存放的具体消息

    #判断历史消息是否超过2条
    if len(stored_messages)<=2:
        return False

    #剪辑消息列表

    #总结第一条到倒数第第三条的内容
    messages_to_summarize=stored_messages[:-2] # 需要进行摘要的消息列表
    last_n_messages=stored_messages[-2:]       # 保留的2条消息

    #大模型总结
    summarization_prompt=ChatPromptTemplate.from_messages(
        [
            ("system","请将以下对话历史压缩为一条保留关键信息的摘要信息。"),
            ("placeholder","{chat_history}"),
            ("human","请生成包含上述对话核心内容的摘要，保留重要事实和决策。")
         ]
    )
    summarization_chain=summarization_prompt | llm1
    #生成摘要
    summary_message=summarization_chain.invoke({
        'chat_history':messages_to_summarize,
    })
    # 重构历史记录：摘要 + 最后2条原始消息
    chat_history.clear() #执行clear()后数据库中的数据也同时消失
    chat_history.add_message(summary_message) # 第1条是AI总结的消息
    for msg in last_n_messages:
        chat_history.add_message(msg)          #第2只2+n-1条是保留的后n条消息
    return True

# 最终的链
# RunnablePassthrough 默认会将输入数据原样传递到下游，而.assign()方法允许在保留原始输入的同时，通过指定键值对（如messages）
final_chain=(RunnablePassthrough.assign(messages_summarized=summarize_messages) | chain_with_message_history)


# RunnableWithMessageHistory可以自动识别config参数，但是使用我们自己定义的summarize_messages，只能传一个参数进去，如果原封不动的把input和config两个传进去，肯定读取不到config，需要把config塞到input的字典中，同时保留函数第二个参数config以供RunnableWithMessageHistory操作



res=final_chain.invoke(
    {
        'input':'王祥喜欢射吗',
        "config" :{  # 用于函数传参
             "configurable":
                 {"session_id": "user123"}
        }
    },
    config={
        "configurable":
            {"session_id": "user123"}
    }
)
print(res)