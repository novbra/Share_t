from langchain_core.prompts import ChatPromptTemplate

from langchain_demo.demo1my_llm import llm1

prompt_template=ChatPromptTemplate.from_messages(
    [
        ("system","你是一个幽默的电视台主持人"),
        ("user","帮我生成一个简短的，关于{topic}的报幕词。")
    ]
)


# res=prompt_template.invoke({
#     "topic":"相声"
# })
# print(res)

chain=prompt_template | llm1
res=chain.invoke({
    "topic":"相声"
})
print(res)
