# ICL: In Context Learning
# 问题：巴伦·特朗普的父亲是谁？
from langchain_core.prompts import PromptTemplate, FewShotPromptTemplate

from langchain_demo.demo1my_llm import llm1

# 回答问题不生硬，而是把整个分析的过程搞清楚

# 比如分析巴伦特朗普的母亲是谁，这个母亲跟谁结婚了，就可以推理出其父亲。
# 就需要给大模型提供一些示例，示例

# 步骤一：提供示例， 给模板思路，任何一个问题我想要大模型根据我的问题得到一个推理链，推理链的展示是通过中间问题和中间答案，一步步推出最终答案。就是教大模型怎么去推
# 通过中间问题和中间答案，不断推理出来


examples=[
    {
        "question":"穆罕默德·阿里和艾伦·图灵谁活得更久？",
        "answer":"""
        是否需要后续问题：是。
        后续问题：穆罕默德·阿里去世时多大？
        中间答案：穆罕默德·阿里去世时74岁。
        后续问题：艾伦·图灵去世时多大？
        中间答案：艾伦·图灵去世时41岁。
        所以最终答案是：穆罕默德·阿里
        """,
    },
    {
        "question": "乔治·华盛顿的外祖父是谁？",
        "answer": """
        是否需要后续问题：是。
        后续问题：乔治·华盛顿的母亲是谁？
        中间答案：乔治·华盛顿的母亲是玛丽·鲍尔·华盛顿。
        后续问题：玛丽·鲍尔·华盛顿的父亲是谁？
        中间答案：玛丽·鲍尔·华盛顿的父亲是约瑟夫·鲍尔
        所以最终答案是：约瑟夫·鲍尔
        """,
    },
    {
        "question": "《大白鲨》和《007：大战皇家赌场》的导演是否来自同一个国家？",
        "answer": """
        是否需要后续问题：是。
        后续问题：《大白鲨》的导演是谁？
        中间答案：《大白鲨》的导演是史蒂文·斯皮尔伯格。
        后续问题：史蒂文·斯皮尔伯格来自哪里？
        中间答案：美国。
        后续问题：《007：大战皇家赌场》的导演是谁？
        中间答案：《007：大战皇家赌场》的导演是马丁·坎贝尔。
        后续问题：马丁·坎贝尔来自哪里？
        中间答案：新西兰。
        所以最终答案是：否
        """,
    },
]

# 先写一个基本提示词 问题以及答案的模板
example_prompt=PromptTemplate.from_template("问题：{question}\n{answer}")

final_template=FewShotPromptTemplate(
    examples=examples,
    example_prompt=example_prompt,
    prefix="请根据以下示例，回答问题",
    suffix="问题:{input}",
    input_variables=["input"],
    example_separator="\n\n",
)
chain=final_template | llm1

while True:
    question=input("请输入问题：")
    res=chain.invoke(
        {"input":question}
    )
    print(res.content)
