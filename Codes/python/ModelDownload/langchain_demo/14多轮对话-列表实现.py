from langchain_core.messages import HumanMessage, AIMessage
from langchain_core.prompts import ChatPromptTemplate

from langchain_demo.demo1my_llm import llm1

prompt=ChatPromptTemplate.from_messages(
    [
        ("system","你是个智能助手"),
        ("placeholder","{chat_history}"),
        ("human","{input}")
    ]
)



chain=prompt | llm1


chat_history=[]

def invoke_record(input):
    chat_history.append(HumanMessage(content=input))
    prompt_data={
        "chat_history":chat_history,
        "input":input,
    }

    res=chain.invoke(prompt_data) # 返回值就是AIMessage类型
    chat_history.append(AIMessage(content=res.content))
    #chat_history.append(res) 无需记录除了content之外的内容
    return res

print(invoke_record("我是王祥"))
print(invoke_record("我叫什么名字？"))