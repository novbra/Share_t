from openai import OpenAI

#测试


#首先要创建一个openAI的类

client=OpenAI(base_url="http://localhost:6006/v1",api_key="xxxx") #测它里面的chat, chat又在v1下, 所以要加个v1. 如果部署时没有加api_key的命令, 这里api_key可以不用写。可以设置一个加密文件，给我们大模型来认证


resp=client.chat.completions.create(
    model='qwen3-4b',
    messages=[{'role':'user','content':'请介绍一下什么是深度学习?'}],
    temperature=0.8,
    presence_penalty=1.5, #保证生成的内容不重复
    #   qwen3特有的参数: enable_thinking 表示是否开启深度思考
    extra_body={'chat_template_kwargs':{'enable_thinking':True}}, #,不用删吗？
)
print(resp.choices[0].message.content)