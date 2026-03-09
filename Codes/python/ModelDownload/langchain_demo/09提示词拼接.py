# PromptTemplate.from_template("do{doi}") 在拼接中可，直接写do{doi}功能一样也能够后续填入变量
# 可用+来拼接
from langchain_core.prompts import PromptTemplate

prompt0=( # 外层的模板
    PromptTemplate.from_template("帮我生成一个简短的，关于{topic}的报幕词。")
    +"，要求：1、内容搞笑一点；"
    +"2、输出的内容采用{language}。"
)

prompt1=( # 外层的模板
    "帮我生成一个简短的，关于{topic}的报幕词。"
    +"，要求：1、内容搞笑一点；"
    +"2、输出的内容采用{language}。"
)

print(type(prompt0))
print(prompt0.invoke({
    "topic":"射",
    "language":"chn"
}))
# 以下会报错，因为prompt1是str, 而prompt0是提示词模板
print(type(prompt1))
print(prompt1.invoke({
    "topic":"射",
    "language":"chn"
}))
