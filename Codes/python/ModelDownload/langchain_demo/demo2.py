from langchain_openai import ChatOpenAI

from env_utils import OPENAI_API_KEY, OPENAI_BASE_URL, LOCAL_BASE_URL, DEEPSEEK_API_KEY, DEEPSEEK_BASE_URL


# 本地私有化部署的大模型
llm=ChatOpenAI(
    model='ds-qwen3-8b', # 你部署的时候自己命名的
    temperature=0.8,
    api_key="xx",
    base_url=LOCAL_BASE_URL,
    # 额外的参数该怎么添加
    extra_body={'chat_template_kwargs':{'enable_thinking':True}}, # 该模型自带think，不管你设置True还是False不影响结果
)

messages=[
    ('system','你是一个智能助手'),
    ('human','深度学习是什么')
]
# 同步调用
resp=llm.invoke(messages)
print(resp)
# 流式响应
#for chunk in llm1.stream(messages):
#    print(chunk.content,end="",flush=True)