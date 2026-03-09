from langchain_core.prompts import PromptTemplate
from langchain_demo.demo1my_llm import llm1

prompt_template=PromptTemplate.from_template("帮我生成一个简短的，关于{topic}的报幕词。")


chain=prompt_template | llm1

#调用的时候要把提示词模板中的参数传进去，字典键值对的方式传进去

resp=chain.invoke({
    "topic":"相声"
})

print(resp)