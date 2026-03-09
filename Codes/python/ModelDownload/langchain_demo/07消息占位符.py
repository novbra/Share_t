from langchain_core.messages import HumanMessage
from langchain_core.prompts import MessagesPlaceholder, ChatPromptTemplate

from langchain_demo.demo1my_llm import llm1

prompt_template=ChatPromptTemplate.from_messages([
    ("system","你是一个电视台,高端访谈节目的主持人!"),
    MessagesPlaceholder("msgs")
])

#SystemMessage: 系统消息
#HumanMessage: 用户输入的消息
# 能否在消息占位符中再使用变量占位符？


chain=prompt_template|llm1

resp=chain.invoke({
    "msgs": [
        HumanMessage(content="你好,主持人!"),
        HumanMessage(content="昨晚访谈哪些人?")

    ]
})

print(resp)
