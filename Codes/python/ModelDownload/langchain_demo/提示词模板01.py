from langchain_core.prompts import PromptTemplate
from langchain_demo.demo1my_llm import llm2

# Runnable在langchain中是可执行对象，所有可执行对象都可以使用invoke，包括之前的ChatOpenAI，所有的可执行对象都可以连接到/使用到LCEL(LangChainExpression Language,LangChain链式表达语言)表达式中，表达式里面接的就是一个个Runnable对象
# 提示词模板只要是通过Langchain代码得到的，就是一个可执行对象

# 总结
# Runnable对象都可以通过invoke来调用
# Runnable对象都可以直接放到LCEL表达式中，使用管道操作服务，管道操作服务就是竖线连接形成一个链

# 提示词模板，里面的一些词动态输入通过占位符{xx}来传参
prompt_template=PromptTemplate.from_template("帮我生成一个简短的，关于{topic}的报幕词。")

# 使用时，再传参到模板中
res=prompt_template.invoke({
    "topic":"相声"
})
# 运行结果就是完整的字符串
print(res)