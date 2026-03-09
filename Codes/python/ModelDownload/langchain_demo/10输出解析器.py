from langchain_core.messages import HumanMessage
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import ChatPromptTemplate, FewShotChatMessagePromptTemplate, PromptTemplate, \
    MessagesPlaceholder

from langchain_demo.demo1my_llm import llm1

# 2 X 2 =4
# 3 x 3 =6

# 3 x 4 的结果是多少？

examples=[
    {
        "input":"2 j 2",
        "output":"4"
    },
    {
        "input":"3 j 3",
        "output":"6"
    },
    {
        "input":"4 j 5",
        "output":"9"
    }
]

example_prompt=ChatPromptTemplate.from_messages(
    [
        ("human","{input}"),
        ("ai","{output}"),
    ]

)

few_shot_template = FewShotChatMessagePromptTemplate(
    example_prompt=example_prompt,
    examples=examples,
)

# 提示词模板之间可进行拼装

final_template=ChatPromptTemplate.from_messages(
    [
        ("system","你是智能助手"),
        few_shot_template,                          # 里面封装了一个模板
        MessagesPlaceholder("msgs")
    ]
)
# 加入输出解析器
# 字符串解析器，直接从AIMessage中的content内提取内容
parser=StrOutputParser()
# chain =final_template | llm1
chain =final_template | llm1 | parser
resp=chain.invoke({
    "msgs":[HumanMessage("1 j 1")]
})
print(resp)
