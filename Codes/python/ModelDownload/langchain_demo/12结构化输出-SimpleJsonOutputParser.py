
from langchain_core.output_parsers import SimpleJsonOutputParser
from langchain_core.prompts import PromptTemplate, ChatPromptTemplate

from langchain_demo.demo1my_llm import llm0,llm1,llm2








# 创建聊天提示词模板，要求模型以特定格式回答问题
prompt=ChatPromptTemplate.from_template(
    "尽你所能回答用户的问题。" #基本指令
    '你必须始终输出一个包含"answer"和"followup_question"键的JSON对象。其中"answer"代表：对用户问题的回答; "followup_question"代表：用户后续可能提出的问题'
    "{question}" #用户问题占位符
)

chain=prompt | llm1 | SimpleJsonOutputParser()

resp=chain.invoke({
    "question":"细胞的动力源是什么？"
})

# resp是个字典,json形式
print(resp)

