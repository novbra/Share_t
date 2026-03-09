import json
from typing import Optional

from langchain_core.prompts import PromptTemplate
from pydantic import BaseModel,Field

from langchain_demo.demo1my_llm import llm0,llm1,llm2


# 生成一个笑话的段子：生成的内容结构化成三个属性
# 1. 笑话的内容
# 2. 笑话中包含的笑点
# 3. 笑话的评分

# 使用pydantic定义一个类，用于规范数据结构

class Joke(BaseModel):
    """笑话（搞笑段子）的结构类(数据模型类 POJO )仅封装数据和基础访问逻辑，不依赖任何框架 / 容器的特殊接口、注解或父类"""
    setup:str=Field(description="笑话的开头部分")
    punchline:str=Field(description="笑话的包袱/笑点")
    rating:Optional[int]=Field(description="笑话的有趣程度评分，范围1到10")


prompt=PromptTemplate.from_template("请帮我生成一个关于{topic}的笑话")

runnable=llm0.with_structured_output(Joke)

chain=prompt | runnable

resp=chain.invoke({
    "topic":"猫"
})

print(resp)

print(resp.__dict__)

print(json.dumps(resp.__dict__))
