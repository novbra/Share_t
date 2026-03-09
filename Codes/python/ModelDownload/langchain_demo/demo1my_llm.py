from langchain_openai import ChatOpenAI

from env_utils import OPENAI_API_KEY, OPENAI_BASE_URL, LOCAL_BASE_URL, DEEPSEEK_API_KEY, DEEPSEEK_BASE_URL

#调用小爱中的各种大模型
llm0=ChatOpenAI(
    model='gpt-4o-mini', # gpt-4o-mini
    temperature=0.8,
    api_key=OPENAI_API_KEY,
    base_url=OPENAI_BASE_URL,
)
# deepseek官方大模型r1
# https://api-docs.deepseek.com/zh-cn/
# 若输出的内容需要有thinking，则需要在提示词中加标签
llm1=ChatOpenAI(
    model='deepseek-reasoner', # gpt-4o-mini
    temperature=0.8,
    api_key=DEEPSEEK_API_KEY,
    base_url=DEEPSEEK_BASE_URL,
)
# 本地私有化部署的大模型
# llm2=ChatOpenAI(
#     model='qwen3-4b', # 你部署的时候自己命名的
#     temperature=0.8,
#     api_key="xx",
#     base_url=LOCAL_BASE_URL,
#     # 额外的参数该怎么添加
#     extra_body={'chat_template_kwargs':{'enable_thinking':True}},
# )

llm2=ChatOpenAI(
    model='ds-qwen3-8b', # 你部署的时候自己命名的
    temperature=0.8,
    api_key="xx",
    base_url=LOCAL_BASE_URL,
    # 额外的参数该怎么添加
    extra_body={'chat_template_kwargs':{'enable_thinking':True}}, # 该模型自带think，不管你设置True还是False不影响结果
)

#messages是一个列表，列表里面可以是字典也可以是二元组
# 字典相对麻烦些要写2个字典，每个字典里要写role和content键值对，二元组简单些只用些role和content关键字对应的值就行了
# messages=[
#     {
#         'role':'system',
#         'content':'你是一个智能助手'
#     },
#     {
#         'role':'human',
#         'content':'请介绍一下什么是深度学习？'
#     }
# ]
messages=[
    ('system','你是一个智能助手'),
    ('human','深度学习是什么')
]
# 同步调用
#resp=llm2.invoke(messages)
#print(resp)
# 流式响应
#for chunk in llm1.stream(messages):
#    print(chunk.content,end="",flush=True)