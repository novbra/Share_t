
from langchain_demo.demo1my_llm import llm0,llm1,llm2

from pydantic import BaseModel,Field

class ResponseFormatter(BaseModel):
    """始终使用此工具来结构化你的用户响应"""
    answer:str=Field(description="对用户问题的回答")
    followup_question:str=Field(description="用户可能提出的后续问题")


# 数据模型类和大模型绑定，并非真正的绑定工具

#Sequence序列在Python中包含元组和列表
#bind_tools()中tools列表中可以是字典、type、Callable、BaseModel即真正的工具类型
#在这里tools由于使用结构化输出列表中这里不接真正的工具，而是接类型Type

runnable=llm0.bind_tools([ResponseFormatter])
resp=runnable.invoke("细胞的动力源是什么？") # 不是提示词模板，无需传字典，直接传文本即可
# 绑定工具生成的就是一个AIMessage或ToolMessage，而不是纯粹的Json字符串
# 输出的是AIMessage，json格式的数据放在里面的tool_calls中
# 列表-1索引就是最后一个
print(resp.tool_calls[-1]['args'])
# 好看打印
resp.pretty_print()
