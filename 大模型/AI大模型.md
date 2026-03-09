# AI大模型工程师

![c50ba3699f59160f4c66f8607fc32e59](E:\WeChatDoc\xwechat_files\wxid_ggubr1ock2do21_2d85\temp\RWTemp\2026-01\50648aaec11990bdc4ce07bc9b6a3819\c50ba3699f59160f4c66f8607fc32e59.jpg)

AI大模型算法工程师≠AI算法，前者门槛低许多，只干些微调的活

AI大模型预训练这个岗位门槛高



直播课里 AI大模型工程师简历和面试指导



**先应用**

先学17 新版langchain+langgraph+MCP

再学13 携程AI智能助手项目

再做14 Rag企业知识库项目 检索增强生成（Retrieval-augmented Generation）课时07 服务器部署Unstructured 需要私有化部署Unstructured 可能需要GPU也可能用到CPU，自己需要租服务器  课时04 租服务器部署Milvus数据库 包括后面的BGE也是做私有化。

企业在什么样的环境下需要私有化什么东西，私有化模型不是指私有AI*大模型*，还有可能私有化嵌入模型，还有可能私有化多模态的解析模型，还有可能私有化向量数据库，还有可能私有化其他模型比如说Rank模型。五个模型一起才能构成这个Rag项目



再做15

再做16

再做直播课中直播二期 多模态RAG+RAGAS实战项目 考虑到了图片、语音这些多模态的数据都放到向量数据库中采用一个多模态大模型帮我解决多模态RAG的问题



这五个学完了就可以学微调和算法了



python中的FastAPI类似于Java中的SpringBoot，其在后端的性能上与Go并肩，未来部署智能体，RAG，优先使用FastAPI。未来如果用到，要看下python全栈工程师里的第21课 速度最快的异步框架FastAPI



**再算法**

先从25 程序员的数学开始

重点如下

- **微积分**，尤其是微积分导数部分，包括我们讲的神经网络激活函数和损失函数，整个推导的过程都用到了导数
- 线性代数以理解为主， 知道向量计算的方法就行，不用自己计算，计算交给计算机
- **多元函数微分学**，重点
- **概率论**，重点
- 最优化，以理解为主

**7算法1框架**

**7个算法**是大模型研发/算法岗必学的。 **有11个算法**

- **线性回归**，若以大模型应用开发，则第三章节及之后的内容以理解为主。但你要转到大模型算法岗位，那第三章节的梯度下降及之后的内容必须掌握
- 线性分类中的**逻辑回归**，主要学逻辑回归二分类和逻辑回归多分类softmax

AI人工智能零基础入门班下的

- **决策树系列算法**，重点学前面2个章节 京东购买意向预测/天猫用户复购预测就是决策树的实战，还包括线性回归，还包括特征工程怎么处理,以及数据探索，数据清洗包含在内的。会加1-2个数据挖掘的项目。
  - **随机森林**，所谓的随机森林是由多棵决策树组成的
- **概率图模型**

注：梯度下降是求最优解的方法，并非是算法，线性回归会用到梯度下降

深度学习下的3个算法

- **递归神经网络**
- **卷积神经网络**
- **深度神经网络**





**1个框架**

**NLP**

**Transformer架构**/**Pytorch深度学习框架**



**最后微调**

也就是进阶篇



18大模型微调和部署+应用篇里的Huggingface 基础教程+21多模态大模型项目实战+23 Huggingface项目实战。

其余的是预训练相关的,专门给大模型预训练岗位设置的。只有10家公司在招Deepseek, Qwen，智谱，百川。门槛高，20 从0到1训练私有大模型必学+大模型直播课二期从0到1训练MOE架构大模型,告诉你1.如何训练模型2.算力卡与算力卡之间通讯的优化3.如何准备数据集，矩阵的优化，MOE整个Transformer架构的优化问题，学历高的一定要把预训练学下。学完有机会进入deepseek这样的公司。市面上没有自由的预训练程序员



简历里加上机器学习的项目**京东购买意向预测/天猫用户复购预测的项目**/**电商项目-用户评论情感分析**，用于替代你简历上非Java项目

## 基础篇 了解即可

目的：应付面试

把后面的算法篇学完后，再回来看

神经网络损失函数，激活函数，解释什么是自注意力机制

### 机器学习篇

### 深度学习篇

### 大模型架构之Transformer

- Self Attention
- 多头注意力

## 应用篇

### 17. 新版LangChain+LangGraph+MCP的智能体和工作流开发



#### 第一章、大模型选择和私有化部署

**Mixture of Experts（MoE）**

分配给专家计算

**Dense**

全员参与计算，不适用于复杂情况下，效率较低



建议：熟悉各种顶级的AI大模型的使用和微调。包括：gpt-4o,gpt-o1-mini,gpt-o3,claude-3.5-sonnet,claude-3.7-sonnet,gemini-1.5,deepseek,qwen.



##### 1. deepseek-V3



deepseek-v3有deepseek-chat和deepseek-reasoner。中的deepseek-reasoner是DeepSeek推出的推理模型，即我们在网页中看到的deepseek-r1。



**deepseek-r1默认不支持Function Call、Json Output、FIM补全（Beta）。**不过对于Function Call，可以通过微调重新训练可以使它支持。或可以通过deepseek v3 0324就可。

当然国外这些模型都是可以用这些功能的。

deepseek v3 0528版本开始支持Function Calling、JsonOutput、对话补全，对话前缀续写（Beta）



| 模型                                           | deepseek R1 0528                                             |      |
| ---------------------------------------------- | ------------------------------------------------------------ | ---- |
| max_tokens单词回答的最大长度（含思维连续输出） | default: 32k<br />max:64k                                    |      |
| 支持的功能                                     | Function Calling<br />Json Output<br />对话补全<br />对话前缀续写（Beta） |      |
| 不支持的功能                                   | FIM补全（Beta）                                              |      |

##### 2. Qwen3



Qwen3-235B-A22B和Qwen3-30B-A3B均是MoE架构，除此之外剩下都是Dense架构，包括1.5B，8B，14B模型

B是billion的意思。235B指的是参数2350亿，A22B指激活参数量220亿。

亮点：

- 灵活，可在思维模式和非思维模式下无缝切换，用户在需要复杂的逻辑推理的时候就把深度思考模式打开，当进行简单的fuction calling或者是MCP结合的时候，我不需要深度思考模式，我就把这个深度思考模式给关闭掉。而Deepseek需要通过用户自己去切换思维模式和非思维模式。
- 精通Agent能力，能够以思考和非思考两种模式与外部工具精准集成，并增强了对MCP的支持，在基于Agent的复杂任务中取得开源模型的领先性能。



##### 3. 私有化部署



**显存计算器**

- 大模型显存需求分析工具|LlamaFactory:

  https://www.llamafactory.cn/tools/gpu-memory-estimation.html

  如果部署8B，且不是量化版本，一般是float16/bfloat16，很少会用到float32，用float32有点浪费显存。主要看两个参数

  - Inference（GB）:模型在进行推理时所需的显存大小。当然这个显存大小是不考虑并发的。1-5并发左右需要的显存大小。如果有100个用户的并发，显存就需要增加。考虑并发，还要由模型的k-v精度来决定等。并发的增加，显存大小的增加并不是指数级的，而是按照倍数来增加的。比如10个并发你需要增加1个G，再增加10个你需要再增加1个G。

    4090卡，不做魔改24G显存，用它去做大模型的推理，一般来说8B，9B都是一点问题都没有，因为推理需要18G，算上k-v缓存也接近20，22G之间，当然并发量并不高的情况下。

    也可以不使用显存，用内存来替代，不过推理速度、训练速度会变慢，这就不符合企业的生产环境需求。

企业的生产环境中建议至少部署30B以上的大模型，若显存不足可以部署量化版本。

###### 一、下载模型

https://www.modelscope.cn/organization/Qwen?tab=collection

选一个点击，然后点击下载模型按钮，会提供3种下载方式



**模型量化**

[一文读懂Ai大模型的专业术语：大模型本体、蒸馏、量化、GGUF、fp32/fp16/bf16/fp8、Q4/Q5/Q6等_原生模型 衍生模型 fp8 gguf q8 q4-CSDN博客](https://blog.csdn.net/EnjoyEDU/article/details/147242296)

- 分组量化，如GPTQ、AWQ、SmoothQuant
- **GGUF 量化**，内存不够可以用这个版本，性能不会损失很大。GPT-Generated Unified Format是一种专为大型语言模型设计的二进制文件格式，旨在优化模型的存储、加载和推理效率，尤其适用于本地部署场景（如llama.cpp框架）。
- FP8/FP16/BF16
- Int4/Int8

*.safetensors是核心文件



###### 二、通过vllm server命令部署

企业生产环境中，不要使用Ollama部署，存在安全风险

vLLM是高性能推理框架，面相企业级生产环境和高并发场景，强制需要GPU，显存要求较高。最高支持128K tokens。在个人电脑上，tokens数量很难超过16K的，因为这需要很大的显存。



**vllm的命令说明**

首先需要安装vllm，需要安装最新的，如果装的是旧版的，有些参数可能不支持。

`pip install vllm`

**命名参数详解**

- \-\-model要使用的huggingface模型的名称或路径。

- \-\-enable-reasoning 开启深度思考，默认是开启的
- \-\-reasoning-parser 深度思考的解析器

**Qwen3部署命令和API调用**

```python
python -m vllm.entrypoints.openai.api_server \
	--model autodl-tmp/models/Qwen/Qwen3-4B \
	--served-model-name qwen3-4b \
	--max-model-len 8k \
	--host 127.0.0.1 \
	--port 6006 \
	--dtype bfloat16 \
	--gpu-memory-utilization 0.8 \
	--enable-auto-tool-choice \
	--tool-call-parser hermes

如果是MoE架构的，如果部署的是满血的Qwen3，建议加上以下参数，让Qwen3支持R1的方式来做思考。如果不加这个采用的是Qwen3自己的
	--enable-reasoning \
    --reasoning-parser deepseek_r1 \
    
    
# Deepseek-r1 0528 QWen3 8B
python -m vllm.entrypoints.openai.api_server \
	--model /root/autodl-tmp/models/deepseek-ai/DeepSeek-R1-0528-Qwen3-8B \
	--served-model-name ds-qwen3-8b \
	--max-model-len 8k \
	--host 127.0.0.1 \
	--port 6006 \
	--dtype bfloat16 \
	--gpu-memory-utilization 0.8 \
	--enable-auto-tool-choice \
	--tool-call-parser hermes
    
```

若要使用其他的模型，应做的替换如下

- \-\-model里面的模型路径
- \-\-served-model-name模型名称
- \-\-max-model-len 最大上下文tokens，在生产环境中多写一点。在一张4090，保证推理速度的情况下，推荐写8k
- \-\-dtype 模型参数精度
- 如果是量化版本，设置一下量化的格式



企业生产中，推理时的输出80k/s以上

`nvidia-smi`可查看显卡使用情况



**测试**

接口文档在`127.0.0.1:6006/docs`

现在的大模型都兼容`openai`的库，可以用其来测试我们的大模型。未来我们是不会用它的。

首先安装`openai`库

`pip install openai`

```python
from openai import OpenAI

#测试

#首先要创建一个openAI的类

#测它里面的chat, chat又在v1下, 所以要加个v1. 如果部署时没有加api_key的命令, 这里api_key可以不用写。可以设置一个加密文件，给我们大模型来认证
client=OpenAI(base_url="http://localhost:6006/v1",api_key="xxxx")


resp=client.chat.completions.create(
    model='qwen3-4b',
    messages=[{'role':'user','content':'请介绍一下什么是深度学习?'}],
    temperature=0.8,
    presence_penalty=1.5,
    #   qwen3特有的参数: enable_thinking 表示是否开启深度思考
    extra_body={'chat_template_kwargs':{'enable_thinking':True}}, #,不用删吗？
)
print(resp.choices[0].message.content)
```



#### 第二章、新版LangChain的应用开发



LangChain是一个帮助你快速构建大模型应用的工具框架，让模型能连接数据、用工具、执行工作流。

为什么需要LangChain？

大模型很强，但：

- 不会主动获取外部数据
- 不会调用工具
- 不擅长多步骤任务
- 缺乏记忆

LangChain专门解决这些问题，让大模型真正变成应用。

##### LangChain的核心理念

1. **模块化**：像积木一样拼应用
2. **链式执行**：把步骤串起来完成复杂任务
3. **集成外部资源**：模型+数据库+API+文件=强大应用

##### LangChain的核心组件（最重要的6个）

1. **Model（模型）**：调用GPT、DeepSeek、HF模型的入口

2. **Prompt（提示词）**：告诉模型要做什么

3. **Chain（链）**：把多步任务连接起来

4. **Memory（记忆）**让对话保持上下文

5. **Retriever（检索器）**：让文档/数据库取信息

   [Retriever]: 可理解为模糊匹配

6. **Tools（工具）**：让模型能执行外部任务（计算器、API、搜索等）

##### LangChain能做什么（重点）

1. **连接外部数据**：数据库、文档、网页
2. **调用外部工具**：计算器、API、代码执行
3. **构建复杂工作流**：多步骤、多逻辑任务
4. **记住上下文**：多轮对话更自然
5. **支持多模态**：文本+图片+音频





开发环境：Pycharm-2025版+Python-3.11+JDK-17+SpringAI(1.0.0-M7)-Spring-boot(3.44) langchain



LangChain不托管任何聊天模型，而是依赖于第三方集成

langchain.com.cn/docs/integrations/chat/



RAG开发现在也要结合工作流、智能体的，一般来说RAG不会单独存在，否则你连RAG的动态路由你都不知道怎么搞，以及RAG的决策能力也需要智能体做决策，整门课的重心还是放在智能体工作流、MCP上



##### 架构

LangChain作为一个框架由多个包组成

- langchain-core

  包含不同组件的基本抽象以及将它们组合在一起的方法。

- langchain

  链、代理和检索策略

- langchain-community

  第三方集成

  langchain-openai也是第三方的

##### 安装

`pip install langchain`会自动安装`langchain`和`langchain-core`但是不会安装`langchain-community`

`pip install langchain-community`

`pip install langchain-openai`



##### 环境变量设置

###### 创建环境文件

`.env`文件存放环境变量以及环境变量相关的配置，主要配置API-KEY, baseurl

提供一个模板

```python
# 在线的API-Key
OPENAI_API_KEY=""
DEEPSEEK_API_KEY=""
OPENAI_BASE_URL=""
DEEPSEEK_BASE_URL=""
```

###### 创建env_utils.py文件用于加载读取环境配置文件

具体见python，环境变量管理



##### 使用langchain_openai库调用模型

```python
# 大模型在langchain中更换是很简单的
# 所有的大模型都支持OpenAI的调用库ChatOpenAI()
# OpenAI并不是公司名，国内外通用专门去调用大模型的库就叫做OpenAI，它是python的官方库，说的不是OpenAI大模型
llm=ChatOpenAI(
	model='qwen3-4b',        #模型名称
	temperature=0.8,         # 温度，增加temperature会增加输出的随机性，产生更多样化的结果，但也可能降低预测准确性，温度为0将始终产生相同的输出。主要用于控制创造力。对于作文等用途可以将温度系数拉高，对于问答类应用场景，可以把温度系数拉低。
	api_key="xx",            # 大模型提供商处获取
	base_url=Local_Base_URL, # 大模型请求地址
)
# 其他ChatModels标准化参数
# timeout: 请求超时
# max_tokens: 生成最大令牌书
# stop: 默认停止序列
# max_retries: 请求重试的最大次数
messages=[# 前者为role,后者为content
    ('system','你是一个智能助手'),       # 系统提示词
    ('human','请介绍一下什么是深度学习?') # 用户提示词
]

# ChatOpenAI类对象方法
# 核心方法，参数可以是String/字典/二元组
# invoke()   - 同步调用模型，获取完整相应
# stream()   - 流式响应，逐步显示结果
for chunk in llm0.stream(messages):
    print(chunk.content,end="",flush=True)
# generate() - 批量生成，多个输入
# bind_tools() - 绑定工具调用，将函数调用能力绑定到当前模型。
# 高级方法
# https://blog.csdn.net/qq_56664222/article/details/149472418
```

##### 提示词模板(含ICL)

在做智能体、RAG开发过程中包括工作流开发过程中一定用得到，有助于将用户的输入和参数转换为大语言模型能够理解的一些指令。说白了，模板就是传给大模型的指令，让大模型来理解上下文语义，让上下文连贯起来，最后得到一个准确的输出。

所以呢，经常所说的大模型出现幻觉，或者大模型回答的准确性不高，马上可以想到的一个解决方法，就是优化你的提示词模板，当然这个解决方法不是百分百可以解决的。优化提示词，大模型就会知道你要干什么。这是提示词模板的最重要的功能，还有可能是传给大模型的语义，大模型理解的不透彻，也不知道它应该怎么做做成什么样子来满足你。



有两种常用的提示词模板类型：

- 字符串提示词模板

  ```python
  # Runnable在langchain中是可执行对象，所有可执行对象都可以使用invoke，包括之前的ChatOpenAI，所有的可执行对象都可以连接到/使用到LCEL(LangChainExpression Language,LangChain链式表达语言)表达式中，表达式里面接的就是一个个Runnable对象
  # 提示词模板只要是通过Langchain代码得到的，就是一个可执行对象
  
  # 总结
  # Runnable对象都可以通过invoke来调用
  # Runnable对象都可以直接放到LCEL表达式中，使用管道操作服务，管道操作服务就是竖线连接形成一个链
  # 提示词模板，不使用便捷类方法
  #prompt_template=PromptTemplate(
  #	input_variables=["topic"],
  #   template="帮我生成一个简短的，关于{topic}的报幕词。"
  #)
  # 提示词模板便捷类方法，自动识别占位符{xxx}
  prompt_template=PromptTemplate.from_template("帮我生成一个简短的，关于{topic}的报幕词。")
  
  # 使用时，再传参到模板中
  res=prompt_template.invoke({
      "topic":"相声"
  })
  #或
  #prompt=prompt_template.format(topic="相声")
  #print(prompt)
  
  # 运行结果就是完整的字符串
  print(res)
  
  """
  # 附上源码解释 
  # Instantiation using from_template (recommended)
  prompt = PromptTemplate.from_template("Say {foo}")
  prompt.format(foo="bar")
  
  # Instantiation using initializer
  prompt = PromptTemplate(template="Say {foo}")
  """
  ```

  **In-context Learning(ICL) 在企业中一定会用到**

  新的自然语言处理范式，核心思想：通过提供少量示例作为上下文，让大模型直接从中学习并做出预测。这一方法不仅省去了传统监督学习中繁琐的训练过程，还为大模型的应用开辟了新的可能性。

  ```python
  #1.准备示例
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
  #2.定义示例模板
  #输入的示例模板，用了便捷方法，其中question和answer是输入变量,会从我们给的example中自动提取question和answer字段的内容
  example_prompt=PromptTemplate.from_template("问题:{question}\n回答:{answer}")
  #3.创建FewShotPromptTemplate
  # 少样本提示词模板，由于没有便捷方法，要写input_variables
  final_prompt=FewShotPromptTemplate(
  	examples=examples,
      example_prompt=example_prompt,
      prefix="请根据以下示例，回答问题",  # 放在example示例内容之前的内容，可不加
      suffix="问题：{input}",        # 放在example示例内容之后的内容
      input_variables=["input"],
      example_separator="\n\n"       # prefix、example和suffix之间的分隔符，可不加
  )
  # 喂给大模型的顺序是：prefix->examples格式化后的内容->suffix
  ```

  

- 聊天提示词模板 ChatPromptTemplate

多一个System角色的Content定义，与字符串提示词模板没区别

角色有两类，用户是`human` `user`,系统是`ai` `assistant` `system`

```python
prompt_template=ChatPromptTemplate.from_messages(
    [
        ("system","你是一个幽默的电视台主持人"),
        ("user","帮我生成一个简短的，关于{topic}的报幕词。")
    ]
)
chain=prompt_template | llm1
res=chain.invoke({
    "topic":"相声"
})
print(res)
```

**消息占位符**

`MessagesPlaceholder(variable_name:str,optional:bool)`

#`optional`:用于控制该占位符是否为必填项，如果为True时，该占位符是可选的。如果在调用模板时没有传入对应的变量（例如对话历史或示例列表），系统将自动跳过该占位符，不会报错。如果为False时, 表示该占位符是必需的。如果调用模板未提供对应变量，系统会抛出错误，要求必须传入一个消息列表。

它本质上是一个占位符，专门用于处理**对话历史**、Agent 推理轨迹等需要动态传入多条结构化消息的场景。‌

**动态注入消息历史**‌：在多轮对话中，`MessagesPlaceholder` 允许将之前的历史消息（如 `HumanMessage`、`AIMessage`、`SystemMessage` 等对象列表）完整地嵌入到提示模板中，使大语言模型能基于上下文生成连贯的回复，而非仅处理当前单条输入。‌

```python
#MessagesPlaceholder（或其简写形式 ("placeholder", "{key}")）允许将历史消息‌直接嵌入消息流‌，保持上下文语义

prompt_template=ChatPromptTemplate.from_messages([
    ("system","你是一个电视台，高端访谈节目的主持人！"),
    MessagesPlaceholder("msgs")
    ("placeholder","{key}") # MessagesPlaceholder的简写形式
])

#SystemMessage: 系统消息
#HumanMessage: 用户输入的消息
# 能否在消息占位符中再使用变量占位符？
prompt_template.invoke({
    "msgs":[HumanMessage(content="你好，主持人!")]  # 是个列表，里面放Message对象
})
```

###### 提示词拼接

```python
# PromptTemplate.from_template("do{doi}") 在拼接中可，直接写do{doi}功能一样也能够后续填入变量，但在整个拼接中必须要出现一个明确声明过是提示词模板类的，否则最后出来的只能是str，无法使用invoke方法

# 可用+来拼接
prompt=( # 外层的模板
    PromptTemplate.from_template("帮我生成一个简短的，关于{topic}的报幕词。")
    +"，要求：1、内容搞笑一点；"
    +"2、输出的内容采用{language}。"
)
```

##### 输出解析器(OutputParser)

`输出解析器`: 负责获取模型的输出并将其转换为更适合下游任务的格式。在使用大型语言模型生成结构化数据或规范化聊天模型和大型语言模型的输出时非常有用。

常见的解析器

- `StrOutputParser` 字符串解析器，直接从AIMessage中的content内提取内容

  ```python
  chain = prompt | llm | StrOutputParser()
  ```

- `SimpleJsonOutputParser` 大模型自带的解析器

  一些模型，例如Mistral,OpenAI,Together AI和Ollama，支持一种称为JSON模式的功能，通常通过配置启用。启用时，JSON模式将限制模型的输出始终为某种有效的JSON。 需要给大模型文字描述，让其知道是JSON输出格式，让它知道哪些键

  ```python
  # 创建聊天提示词模板，要求模型以特定格式回答问题
  prompt=ChatPromptTemplate.from_template(
      "尽你所能回答用户的问题。" #基本指令
      '你必须始终输出一个包含"answer"和"followup_question"键的JSON对象。其中"answer"代表：对用户问题的回答; "followup_question"代表：用户后续可能提出的问题'
      "{question}" #用户问题占位符
  )
  
  chain=prompt | llm1 | SimpleJsonOutputParser()
  
  resp=chain.invoke({
      "question":"细胞的动力源是什么？"
  })
  ```
  
  

##### 结构化输出

`结构化输出`: 限制大型语言模型的输出为特定格式或结构是有用的。

例如：如果输出要存储在关系数据库中，如果模型生成遵循定义的模式或格式的输出，将会容易得多。最常见的输出格式将是JSON，尽管其他格式如YAML也可能很有用。

- **`.with_structured_output()`** 

  专门用于结构化输出，加载到大模型的函数里头，调用里头，是把大模型进行改造，改造成结构化输出的。本质是 OpenAI SDK 对「结构化输出」的封装，核心依赖模型本身是否支持**强制 JSON 输出**

  [结构化输出]:把数据封装成结构化的数据类对象

  一些LangChain聊天模型支持 `.with_structured_output()`方法。该方法只需要一个模式作为输入，并返回一个字典或Pydantic对象。通常，这个方法仅在支持下面描述的更高级方法的模型上存在，并将在内部使用其中一种。它负责导入合适的输出解析器并将模式格式化为模型所需的正确格式。

  [Pydantic对象]: Rag、Agent、工作流等几乎所有的Python中大模型的应用开发全面都会用到这个Pydantic对象
  
  
  ```python
  #对于支持with_structured_output()的大模型,可直接利用属性名和Field中的description让大模型生成对应json格式的内容
  
  #定义结构类
  from pydantic import BaseModel,Field
  class Joke(BaseModel)
  	setup:str=Field(description="笑话的开头部分")
      punchline:str=Field(description="笑话的包袱/笑点")
      rating:Optional[int]=Field(description="笑话的有趣程度评分，范围1到10")
      
  prompt=PromptTemplate.from_template("请帮我生成一个关于{topic}的笑话")
  
  runnable=llm.with_structured_output(Joke)
  chain=prompt|runnable
  resp=chain.invoke(
  {
      "topic":"猫"
  }
  )
  #resp里面放的就是结构体Joke
  print(resp)
  #转换为字典打印
  print(resp.__dict__)
  #转换为json打印
  import json
  print(json.dumps(resp.__dict__))
  ```
  
  注：deepseek目前不支持



- **工具调用**

  形式，而非真正调用。不是真正意义上的工具调用，借用工具调用的方式来结构化输出
  
  原理与`.with_structured_output()`相同，`deepseek`因此用这个也会报错
  
  
  
  对于支持此功能的模型，工具调用可以非常方便地生成结构化输出。它消除了关羽如何最好地提示模式的猜测，而是采用内置模型功能。
  
  
  
  它的工作原理是首先将所需的模式直接或通过LangChain工具绑定到聊天模型，使用`.bind_tools()`方法。然后模型将生成一个包含与所需形状匹配的args的tool_calls字段的AIMessage。工具调用是一种通常一致的方法，可以让模型生成结构化输出，并且是默认技术用于`.with_structured_output()`方法，当模型支持时。
  
  绑定不仅绑定工具，而且绑定pydantic数据类型
  
  ```python
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
  
  runnable=llm1.bind_tools([ResponseFormatter])  # 可以在列表中放多个数据类型，AI会自动决策，选择最佳的数据类型去匹配
  resp=runnable.invoke("细胞的动力源是什么？") # 不是提示词模板，无需传字典，直接传文本即可
  # 绑定工具生成的就是一个AIMessage或ToolMessage，而不是纯粹的Json字符串
  # 输出的是AIMessage，json格式的数据放在里面的tool_calls中
  # 列表-1索引就是最后一个
  print(resp.tool_calls[-1]['args'])
  # langchain提供的好看打印
  resp.pretty_print()
  ```





##### 多轮对话

- 列表实现

```python
prompt=ChatPromptTemplate.from_messages(
    [
        ("system","你是个智能助手"),
        ("placeholder","{chat_history}"),
        ("human","{input}")
    ]
)

chain=prompt | llm1
chat_history=[]
def invoke_record(input):
    chat_history.append(HumanMessage(content=input))
    prompt_data={
        "chat_history":chat_history,
        "input":input,
    }

    res=chain.invoke(prompt_data) # 返回值就是AIMessage类型
    chat_history.append(AIMessage(content=res.content))
    #chat_history.append(res) 无需记录除了content之外的内容
    return res

print(invoke_record("我是王祥"))
print(invoke_record("我叫什么名字？"))
```

- 其他

  - 存储于内存

    langchain_community包下的ChatMessageHistory

    等价于langchain_core包中的InMemoryChatMessageHistory

    原理就是用列表维护消息

    ```python
    history=ChatMessageHistory()
    # 手动记录用户消息
    history.add_user_message("我吃了苹果")
    # 手动记录AI消息
    history.add_ai_message("苹果很健康！")
    # 打印消息列表
    print(history.messages)
    ```
  
    
  
  - 存储于关系型数据库
  
    langchain_community包下的SQLChatMessageHistory
  
    需要传2个参数,一个是`session_id`和`connection_string`
  
    ```python
    def get_session_history(session_id):
        return SQLChatMessageHistory(
            session_id=session_id,
            connection_string='sqlite:///chat_history.db',
        )
    ```
  
    
  
  - 存储于Redis
  
    langchain_community包下的RedisChatMessageHistory

###### **RunnableWithMessageHistory**

自动对话历史，需要

- chain - 包含Prompt和模型
- get_session_history - 获取会话历史消息函数
- input_messages_key - 提示词模板中用户输入的占位符变量
- history_messages_key - 提示词模板中历史记录的占位符变量   提示词中可以不写这个占位符，也会自动把之前的对话给大模型



对`RunnableWithMessageHistory`对象调用`invoke`时需要传入`config`配置

```python
config={
    "configurable":{
        "session_id":"user123"
    }
}
```



##### 大模型应用开发案例 - 多模态的聊天机器人



1. 多模型调用和多模态模型的调用  

   #多模型调用：如果是语音，就调用语音模型，如果是视频，就调用视觉处理模型等，灵活通过程序来切换多个不同的模型

   #多模态模型/全模态大模型：一个模型即能处理文字、语音、视频、文字等

2. 保存历史聊天记录

   #保存到关系型数据库MySQL或缓存数据库Redis中

2. 

3. 修剪聊天上下文

   #聊多了，上下文的信息比较多，每次调用需要把整个聊天记录都要传给大模型，这个时候token占用太大了，钱就花太多了，接受了那么多的数据，处理速度也会变慢。所以要剪辑聊天上下文。

4. 形成摘要记忆

   #同修剪聊天上下文作用一样

5. 拥有web界面，方便用户使用

6. 可以在线录制语音

7. 可以处理语音、图片和视频

# AI 工具 至多20天

## AI大模型提示词工程

大模型自己生成，不需要特地去学

## DALL.E3

## Midjourney

## AI视频工具



## Dify***

涉及Rag, 工作流等的搭建

## Ollama-AI大模型部署工具* 公司开发过程种不太用

由`推理框架`和`可视化软件`组成。前者就是命令行，后者是GUI界面

AI大模型我们会学到4种推理框架



## Claude



## n8n



## Cursor



## RagFlow



## Manus



## Anthropic MCP协议**

模型上下文协议（Model Context Protocol）

***面试***

MCP面试官会问的不太深。

了解MCP，了解MCP协议的底层协议是什么，MCP是干嘛的，MCP由哪些要素组成，了解这些最基本的概念

***开发***

MCP 服务端，客户端应该怎么开发，Python/Java去调用MCP的客户端该怎么调



MCP目前面试时问到的比较少，主要是其还在发展，前几个月通信协议里用的比较多的是SSE，现在企业开发或未来用的比较多的是StringAble?。估计每2个月就做一次迭代，这会影响mcp服务端和客户端代码。

## AI代码编程工具



## Coze AI 开发平台** 私企可能不用，国企可能用



## Spring AI





# 算力服务器如何使用

推荐算力云AutoDL autodl.com 或 算力云 suanlix.com。名称一样，但这俩网站是不同的。这两个网站最便宜。阿里云，华为云等较贵，较为稳定。但跟着老师练习用便宜的就可以了。



AutoDL->算力市场



suanlix配置会比AutoDL高些

suanlix->GPU实例，而不是云电脑，GPU物理卡



不用看CPU核心数，主要看内存大小，数据盘大小

8B 7B 10B左右的模型，一个模型就是16G，数据盘50G的话用2个或3个模型差不多就占满了，我们还需要下载python的一些第三方的库，还包括你的代码，文件，所以50G是不够存放多个模型的，suanlix在相同的价格下会提供更多的内存和数据盘大小

AutoDL没有独立IP，但提供SSH隧道，端口映射，会有一些不方便。在[AutoDL帮助文档](https://www.autodl.com/docs/)搜索SSH隧道

suanlix可以有独立IP，方便但可能要多花一点钱。





对于AutoDL，镜像选PyTorch最新的版本/3.12(ubuntu22.04)/CUDA12.4，反正选最新的就行了。不要选TensorFlow

对于suanlix，在镜像选项中，先选pytorch，再选PyTorch/2.20/12.1/3.11(ubuntu 22.04.2)

如果我们的显卡别人在用，我们可以选择克隆实例，勾选数据盘，然后让你重新选张卡

AutoDL提供一个工具，SSH隧道，作端口映射用的

若用命令行的方式启动隧道，CMD中按Ctrl C可以停止

XShell是登录linux服务器的终端



从事大模型相关，软硬件要求：

- Python 3.11及以上版本（新版Langchain,LangGraph以及新版的Transformer还有新版的VLLM它都默认支持，默认最低版本是3.11，不是由langchain版本来支持的而是VLLM 0.8+要求3.11+），因此课程主流使用的是3.11。

# Python

## 安装

[Python Releases for Windows | Python.org](https://www.python.org/downloads/windows/)

可在命令行中输入`where python`，若输出安装地址表明安装成功

或可在命令行中输入

`python --version`，若输出版本号表明安装成功

或直接输入

`python`后面输出版本号，和带了>>>则表明安装成功



## 卸载

直接搜索Python，弹出右键菜单，点击卸载

把python3.x卸了，然后再把python launcher卸了



## 第三方库

1. **Pygame**：用于开发视频游戏，支持图形绘制和声音处理。 
2. **TensorFlow**：机器学习库，专注于构建用于图像和语音识别的AI模型。
3. **PyTorch**：用户友好的机器学习库，适合轻松构建神经网络。 
4. **Tkinter**：创建图形用户界面的工具，提供预制控件，便于设计布局。 
5. **OpenCV**：计算机视觉库，支持图像处理、实时物体检测和人脸识别。 
6. **NumPy**：科学计算库，主要用于高效处理多维数组和数值计算。 
7. **Pandas**：数据处理库，将数据组织成数据框架，便于数据分析。 
8.  **Kivy**：移动应用程序开发框架，支持自然用户界面。 
9. **Beautiful Soup**：用于网络爬虫的库，允许从网站提取HTML元素。 
10. **Selenium**：适用于动态网站的网络爬虫工具，能够自动化浏览器操作。 
11. **Flask**：轻量级的Web开发框架，适合小型项目。 
12. **Django**：功能丰富的Web开发框架，提供完整的网站构建解决方案。 
13. **Matplotlib**：数据可视化库，能够创建各种图表和图形。 
14. **SciPy**：基于NumPy的科学计算库，提供高级数学功能。
15. **SQLAlchemy**：数据库处理工具包，使数据库管理更加简便。 
16. **FastAPI**：现代框架，用于快速构建API。后端。 
17. **Scrapy**：用于构建网络爬虫的框架，适合大规模数据抓取。 
18. **SQLite**：轻量级的数据库，适合小型应用。 
19. **Pillow**：用于图像处理的库，支持图像编辑和格式转换。 
20. **Natural Language Toolkit (NLTK)**：自然语言处理库，支持文本分析和处理。 
21. **SymPy**：用于符号数学的库，支持代数、微分和积分运算。 
22. **SciKit-Learn**：机器学习库，专注于监督学习和无监督学习。 
23. **PyWin32**：提供对Windows Win32 API的访问，支持与Windows操作系统的交互。 
24. **PyQt**：用于创建图形用户界面的库，支持跨平台应用开发。 
25. **Bokeh**：用于创建交互式数据可视化的库。 
26. **Plotly**：用于创建交互和视觉吸引力图表的库。 
27. **Pickle**：用于对象序列化和反序列化的模块。 
28. **spaCy**：用于高级自然语言处理的库，支持文本分析和处理。 
29. **py2exe**：用于将Python脚本转换为Windows可执行文件的工具。
30. Setuptools 打包
31. Hatchling 打包
32. pip 项目管理
33. uv 项目管理
34. poetry 项目管理



## Pip

### 查看已安装的第三方库

```python
pip list #查看安装的第三方库
```



### 升级pip

`python -m pip install --upgrade pip`

而不能写成

`pip install --upgrade pip`

会报错

### 安装第三方库

#### 更改镜像源

创建pip目录，在pip目录下配置pip.ini文件，文件内容如下

```ini
[global]
index-url=https://mirrors.aliyun.com/pypi/simple/

[install]
trusted-host=mirrors.aliyun.com
```

将pip目录复制到C:\Users\用户名\下

#### 在线安装

`pip install 库名`

`pip install 库名 -i 镜像源`

安装第三方库时，若该库依赖于其他的第三方库，那么pip会将其一同下载下来

```text
阿里云http://mirrors.aliyun.com/pypi/simple/
中科大https://pypi.mirrors.ustc.edu.cn/simple/
豆瓣http://pypi.douban.com/simple/
清华大学https://pypi.tuna.tsinghua.edu.cn/simple/
```

#### 离线安装

https://pypi.org

`pip install 库文件名(.whl)`

#### requirements.txt的使用

requirements.txt记录了当前程序的所有依赖包以及精确版本号，作用就是提供Python包依赖，重构新项目时所需要的环境依赖

通过-r参数一键安装依赖包

`pip install -r requirements.txt`

也可通过它来一键卸载依赖包

`pip uninstall -r requirements.txt`

### 卸载第三方库

`pip uninstall 库名`



## 项目管理

### 项目结构

- Conda宇宙

  免费版有Miniconda，Pixi。有自己的配置文件和软件仓库，连Python解释器都是自己编译的。不仅支持Python服务，也支持Go、Rust、C++、R等等各种各样的语言，理解成一个独立的、跨语言的开发平台。只不过Conda恰好选择了Python作为最主要的交互语言而已。把多语言支持、依赖管理、虚拟环境这些头痛的问题用一套统一的方案全都给解决了。AI框架的依赖是出了名的复杂，经常要跟Nvidia的Cuda这种非Python库打交道。所以想顺利地刨起一个深度的学习框架用Conda来安装就是最省心、最不容易出错的选择。

- Python官方体系

  pip requirements.txt安装第三方库和虚拟环境venv已经过时了。**uv, poetry才是今天的版本答案**



### 依赖管理

早期做法是使用`pip freeze`，打印出当前虚拟环境中的所有已安装好的包以及它的版本号

通常用重定向符，把这些内容输出到一个文件里

`pip freeze >requirements.txt`

不过这个方法有很大的缺陷，`pip freeze`分不清项目真正需要的直接依赖，什么是这些直接依赖而引入的间接依赖。

且`pip uninstall`无法删除间接依赖

现代Python项目的标准解决方案是使用`pyproject.toml`，这个文件是官方指定的统一的配置文件。Python生态中绝大多数主流工具都支持`pyproject.toml`，这样开发者就只需要维护这一个配置文件。

替换`requirements.txt`的功能，需在`pyproject.toml`文件中添加一个叫做`dependencies`的列表

#### pyproject.toml

```text
[project]
name = ""
version = "0.0.0"
dependencies=[
	"Flask==3.1.1"
]
```

未来想要删除依赖库，只需要在dependencies中删除对应的依赖库，而不会留下孤儿依赖。

写好依赖后，使用`pip install .`把当前的项目安装到虚拟环境中。`.`表示当前目录。

这套命令做了2件事

- 构建

  pip会根据pyproject.toml的配置把你当前的项目打包成一个标准的Python软件包

- 安装

  pip会像安装任何其他的第三方包一样，安装刚刚打包好的软件包，并自动把所有声明的依赖一并安装进来

弊端：会把源代码也安装到site-packages目录中，这样就会有2套一模一样的代码。

解决：

在安装时加上一个`-e`参数，就不会再把源代码复制到site-packages目录了，而是只生成一个链接文件，指向源代码。

`pip install -e .`

痛点：

不能像以前一样，用pip install命令去添加新的依赖，这意味着每次添加一个包，都得先去Python的官方软件仓库查好它的名称和版本号，然后再把它写进配置里

#### 第三方管理工具

可以理解为对venv、pip的高级封装，uv事实上重写了，在效率上有所提升

```python
python -m venv .venv #创建虚拟环境
source .venv/bin/activate #激活虚拟环境
edit pyproject.toml #编辑pyproject.toml
pip install -e . #构造安装依赖环境
```

##### UV

`uv add [软件包]`就能完成所有的事情，自动修改pyproject.toml文件，把[软件包]添加到dependencies列表里，它还会检查并自动创建.venv虚拟环境

如果是项目的协作者，从别人那里拿到了这个项目，那我们只需要执行

`uv sync`，uv就会自动读取pyproject.toml文件，搭建好虚拟环境，并且安装好所有的依赖

在用uv管理项目后，我们依然可以用传统的方式来运行代码

先执行`source .venv/bin/activate`

然后再用`python main.py`来运行



同时，uv也提供了一个更加直接的做法

`uv run main.py`

它的作用是在虚拟环境的上下文中执行命令，我们不需要手动激活环境，uv会自动找到项目对应的venv在其中执行命令，然后再退出来

##### Poetry

##### PDM



### 环境变量管理



#### 敏感信息管理

`python-dotenv`



传统硬编码问题

- 安全风险（密钥泄露）

如，API-Key或数据库密码或Token或调试开关



1. `pip install python-dotenv`

2. 创建`.env`文件

   在项目根目录创建`.env`文件，格式为`KEY=VALUE`

   ```python
   # .env 示例文件
   DEBUG=True
   DATABASE_URL=postgresql://user:password@localhost:5432/myapp
   SECRET_KEY=your_super_secret_key_123!
   API_TOKEN=sk-abc123def456ghi789
   
   # 注释行（以 # 开头）会被忽略
   # 空行也会被忽略
   ```

   **务必将 .env加入 .gitignore，防止敏感信息提交到Git**

3. 在Python中加载并使用

```python
load_dotenv(PATH,override=True/False) # 若PATH为空，默认加载当前目录下的.env
# 默认override是关闭的，在使用 dotenv 时，‌override‌ 是一个关键功能，用于控制是否允许 .env 文件中的环境变量覆盖系统中已存在的同名变量。本地调试中建议开启override
#load_dotenv(override=True)
os.getenv("Key",DEFAULT_VALUE) # 第二个参数可以不要

```



## 语法

### 条件判断

#### not

`if not`可用于判断条件为`False`,`None`,空值(如空字符串、空列表)时触发执行快



`None`

`False`

`0`

`“”`

`[]`

`{}`

`()`



特别的，`“0”`是非空字符串，not “0”的输出结果为False



### 函数



#### 关键字参数

关键字参数顺序不重要，关键字参数必须为形参名称

关键字参数和位置参数同时使用时，要先位置参数，后关键字参数（注，这部分关键字参数不要求顺序），反过来则不行。如果用了关键字参数，后面的参数就不能再用位置参数了。

正确的做法：

先把位置参数排好，再排关键字参数

#### 参数默认值

- 函数参数可以有默认值，在函数定义时使用等号指定
- 有默认值的参数为可选参数，在调用时可以不传入

- 有默认值的参数，定义时要放在没有默认值的参数后面

```python
def my_func(a=1,b=2):
    print(a,b)
# 调用时可以没有参数，此时a和b均使用默认值，打印1，2

# 常见默认值
# 数值
# True/False
# None, None是一个类型,NoneType
# ''
# 'first'
# ... 参数有默认值，可以不传入，但是具体是什么还没想好。不传入的话，打印的就是ellipsis
```

#### 可变位置参数

- 可变位置参数用于接收多余的位置参数，使用一个*加参数名组成
- 可变位置参数会将多余的位置参数打包成一个元组
- 位于可变位置参数后面的参数，只能采用关键字传参
- 一个没有参数名的星号，不是可变位置参数，但可以限制后面的参数必须使用关键字传参
- 实际项目中一般使用*args作为可变位置参数

```python
def my_func(a,*args,c=0):
    print(a,args,c)
```

#### 可变关键字参数

- 可变关键字参数用于接收多余的关键字参数
- 使用两个*加参数名定义
- 会把未定义的关键字参数，打包成一个字典，传入函数
- 通常使用**kwargs表示可变关键字参数

```python
def my_func(a,b,*args,c=0,d=0,**kwargs):
    print(a,b,c,d)
    print(type(args),args)
    print(type(kwargs),kwargs)
    
__name__=__main__:
    my_func(1,2,3,4,5,c=-1,d=-2,e=-3,f=-4)
# 1 2 -1 -2
# <class 'tuple'> (3, 4, 5)
# <class 'dict'> {'e':-3,'f':-4}
```

#### 拆包传参

- 使用一个*可以对元组、列表进行拆包传参

*list *tupple

- 使用两个*可以对字典进行拆包传参

** dict

#### 实参是否发生变化问题

##### 不可变类型

new一个新的对象

数字、字符串、元组等不可变类型作为函数的实参时，函数内的改动不会影响变量。

不可变类型其实是创建了一个新对象，值相等

##### 可变类型

引用原对象

列表等可变类型作为函数的参数时，直接修改会影响外部的变量。

实际上是复制了引用，指向了同一个对象

###### 不想让可变类型的对象发生改变，如何操作

- 浅拷贝

  `l2=l2[:] #返回一个副本,对于嵌套其他容器的，其他容器仍然是引用，如果有嵌套其他容器需要使用深拷贝`

- 深拷贝

  ```python
  import copy
  def my_func(12):
      l2=copy.deepcopy(12)
      l2.append(4)
  ```

#### 变量作用域

- 局部变量默认不改变全局变量，若要改变请使用`global`关键字对某个全局变量进行声明后再对该变量进行修改

- 函数内可用`global`关键字创建一个全局变量

```python
a=1
def my_func1():
    a=2 #不改变全局变量a，只改变局部变量a
    
my_func1()
print(a) #a=1

def my_func2():
    global a
    a=2
    
my_func2()
print(a) #a=2
```

- 引用类型如列表等，函数内可直接修改，如果不想修改，请在函数内新建一个容器



#### 函数调用

- 先定义后调用
- 函数体内调用其他函数，即使没有定义也可以，因为定义时不执行



#### 函数返回值

- 返回空值

  NoneType

- 单个返回值

- 多个返回值，使用逗号分隔，打包成元组返回

  ```python
  def my_func():
      return 1,2,3,'a','b','c'
  c=my_func()
  print(type(c),c)
  # 可以使用元组拆包语法，接收返回值
  d,e,*f=my_func() #剩余返回值打包成列表，赋值给f
  ```




#### 参数注解

##### 类型注解

- 可以注明参数类型，便于使用
- 可以使用相应工具进行类型检查，提前发现bug
- **Python解释器会忽略参数注解，并不验证参数类型**

```python
def my_func(a:int,b:float,c:str):
    pass

# 多种类型,需导入annotations
from __future__ import annotations # 现在似乎不需要导入
def my_func(a:int|float,
            b:str|None,
            c:int|float|None
           ):
    pass
```

##### 字符串注解

```python
def my_func(a:'int>0',b:'这是个float',c:'这是个str'):
    pass
# Python括号内忽略换行，换个行，可读性更强点
def my_func(a:'这是个int',
            b:'这是个float',
            c:'这是个str'
           ):
    pass
```

##### 带有默认值参数注解

- 注解放在参数后面等号前面

```python
def my_func(a:int,
            b:'int>=0'=0,
            c:str='',
            d:float|None=None
            e:bool=False
           ):
    pass
```

##### Opitional 可选类型

typing包中的`Optional`的作用是可选类型，作用几乎和带默认值的参数等价。不同的是使用`Optional`会告诉你的IDE或者框架：这个参数除了给定的默认值外还可以是`None`。`Optional[X]等价于Union[X,None]`

```python
a:Optional[int]=None  # a可以是int,也可以是NoneType

```



#### 返回值注解

```python
def my_func(a,b)->str|None:
    if a>0:
        return '1'
```

#### lambda函数

```python
lambda x:x**2 # 冒号前的x是参数，后面的是返回值
# 匿名函数可以赋值给一个变量，从而使用该变量调用函数

s=lambda x:x**2
s(3) #9
```

- lamda函数一般作为函数参数来使用，像map、sorted等可以接受函数作为参数

```python
l1=[1,2,3]
list(map(lambda x:x**2,l1))#[1,4,9]
#map函数，第一个参数是函数，接收一个参数x，返回平方项，第二个参数是列表
```

#### 常用函数

##### print

```python
print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)

# sep 对象间分隔符（默认空格）
# end 输出结束符（默认换行符\n）
# file 输出目标文件对象
# flush 是否强制刷新缓冲区
```



#### \_\_name\_\_==‘\_\_main\_\_’主函数

避免出现导包后出现该包测试代码的运行。这个主函数就是方便我们在某个模块进行调试功能，同时不影响它的导入操作。

| py文件         | \_\_name\_\_ |
| -------------- | ------------ |
| 作为脚本运行时 | \_\_main\_\_ |
| 作为模块导入时 | .py前的名称  |

这就是为什么要写

```python
if __name__=="__main__":
    pass
```



### 面向对象

#### 类

```python
class Dog():
    """这是一个狗狗类""" #可以给类添加文档注释，在类定义后面，使用三引号
    pass
class Dog:# 如果没有要继承什么父类，小括号可以省略
    pass
```

##### 类属性

```python
class Dog():
    owner:str="王祥" # 类属性，多个对象也只存这一份
Dog.owner #访问-类属性
#类对象也可直接访问
```

##### 类方法

```python
class Dog:
    owner:str="王祥"
    @classmethod
    def get_owner(cls):   #类方法 cls: class的简写
        print(cls.owner)
Dog.get_owner() #调用-类方法
#类对象也可直接调用
```

类对象可直接访问类属性和调用类方法，依托于向上查找的机制：

当对象.xxx找不到时，就会到这个对象所属的这个类里边去找，类名.xxx。对象若有，则访问对象的而不是类的。

##### 继承  

小括号里的类就是继承的父类

```python
class Shape:
    pass
class Rectangle(Shape): #继承Shape
    pass
```



#### 对象

```python
my_dog=Dog()
your_dog=Dog()
his_dog=Dog()
```

##### 对象方法

必须要有self参数

```python
class Dog():
    def bark(self):
        print('汪汪')
```

###### 初始化方法

初始化方法，在生成实例时执行

```python
class Dog():
    def __init__(self):
        print('生成一只狗狗')
```



##### 对象属性

不像其他面向对象语言需要把属性声明出来。python只需要在初始化方法中初始化属性即可。

可以在里面写，也可以在生成对象以后在外面写，这些属性不必声明，只要写出来了就给这个对象了

```python
class Dog:
    def __init__(self,name):
        self.name=name
```



#### self参数

self参数是实例化的对象，就是对象的内存地址。

如果对象方法中没有self参数，那么对象就无法调用自身的方法。

##### 在类中使用属性和方法

```python
class Dog:
    """这是一个狗狗类"""
    def __init__(self,name):
        self.name=name
        print('生成一只狗狗',self)
    def bark(self):
        print('汪汪')
    def bark2(self):
        self.bark()
        self.bark()
    def get_name(self):
        return self.name
```

#### 抽象类

不能够具体实例化，通常用于设计模式中定义一套规范。

比如定义许多抽象方法，子类需要继承我这个抽象类并且要实现我定义的所有的抽象方法。

```python
# 要使用抽象类和抽象方法必须导入ABC和abstractmethod
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod #抽象类方法得使用abstractmethod装饰器
    def area(self): 
        pass
```



### 装饰器





### 路径问题

#### 目录分隔符

在处理文件目录的分隔符时，以Windows路径“D:\demo.txt”有以下解决方案

- 使用r字符串前缀：见第2章2.2.6节，r”D:\demo.txt”

- 使用内置os模块的sep常量：os是python内置的操作系统操作模块，需要使用

  `os.sep`

  ```python
  path=".."+os.sep+"next.txt"
  ```

  

#### 取当前工作路径

- `os.getcwd()`

- ```python
  #Path对象
  from pathlib import Path
  current_path_pathlib=Path.cwd()
  ```




### 容器

#### 元组，列表，字典，集合

|      | 使用符号 | 元素可重复 | 是否有顺序？         | 如何新建         | 支持操作                                                   |
| ---- | -------- | ---------- | -------------------- | ---------------- | ---------------------------------------------------------- |
| 列表 | []       | 可以       | 有，输入序           | L=[]/L=(‘a’,’b’) | 定位查找(L[0])、修改(增append删改)                         |
| 元组 | ()       | 可以       | 有，输入序           | T=()/T=(‘a’,’b’) | 定位查找(T[0])                                             |
| 集合 | {}       | 不可以     | 无，定义后可能会打乱 | S=set()          | 修改、集合操作，不能定位查找(indexing)，只能通过迭代器访问 |
| 字典 | {}       | 不可以     | 无                   | D={}             | 按键值查找、修改                                           |

##### 相同点

- 这四种的元素类型都可以不一样

```python
L=[1,'射']
T=(1,'射')
S={1,'射'}
D={'1':1,1:"射"}
```

- 迭代器遍历

```python
for i in T/L/S:
    print(i)
# 对于字典
# 访问键
for key in D: #等价于for key in D.keys()
	print(key)
# 访问值
for value in D.values():
    print(value)
# 访问键值对
for key,value in D.items():
    print(f"{key}:{value}")
```

- 元素是否存在

```python
element in T/L/S/D
```

- 求元素个数

```python
len(T/L/S/D)
```



##### 不同点

列表和元组的区别：元组一旦定义不可以进行修改(增删改)，元组只能重新创建

元组只有一个元素的正确写法T=(1,)，当错写成T=(1)时，解释器会把()当作运算符而不是元组符号，所以打印T的时，只输出1。

集合与字典的区别：空集合需要用set()来定义，如果直接写{}则是字典。非空集合直接用{}定义

set()也可以用于转换列表和元组到集合

字典dict: 

- 定义

  D={‘model’:’Qwen3’}

- 赋值

  D[key]=value

- 访问

  D[key]
  D.get(key)

#### 切片

```python
#左闭右开
[-2:] # 倒数第二条到最后一条
[:-2] # 第一条到倒数第三条
```



### 文件处理

##### open函数与文件IO操作

###### open函数

内置open函数用于构造用于操作文件的文件对象，使用方法为：

```python
open(file,mode='rt',encoding=None)
# file:文件路径
# mode:默认为'rt'
# encoding: 默认为None，常用值是'utf-8'，记事本等有时默认为'ansi'，Windows默认为GBK,如果是字节流encoding就不需要填写参数
# return: 返回一个用于操作文件file的IO对象 
# 'rt'/'wt'/'at'则返回io.TextIOWrapper对象
# 'wb'/'ab'则返回一个io.BufferedWriter对象
# 'rb'则返回一个io.BufferedReader对象
# 为了方便，将这三种对象的类型统称为File类
```

| mode参数 | 功能描述                                                     |
| -------- | ------------------------------------------------------------ |
| 头缀“r”  | 以只读方式打开已经存在的文件                                 |
| 头缀“w”  | 以可写方式打开文件。若文件不存在，则创建文件                 |
| 头缀“a”  | 以追加写入方式打开一个文件，若文件不存在，则创建文件         |
| 尾缀“b”  | 二进制模式，即传输内容为字节流（bytes），用于图片等二进制文件。什么文件都可以用 |
| 尾缀“t”  | 文本模式，即传输内容为文本（字符串），只用于文本文件         |

“r”“w”“a”为基本模式。“b”、“t”这两种模式需要配合3种基本模式使用。

“rw”、“wt”和“at”用于处理文本文件，例如.txt文本、csv文件等。

“rb”、“wb”和“ab”可以用来处理二进制文件，最常见的就是JPEG、PNG等图片或音频、视频等二进制文件。



File类对象有以下操作方法

- write(self,text[buffer],/)

  - 仅限可写模式和追加模式

  - b就传buffer: bytes

  - t就传text: str
  - 返回字符数或字节数: int

```python
#文件复制/移动文件原理
path=""
file_name="a.jpg"
file=open(path+os.sep+file_name,mode="rb")
buffer=file.read()
file.close()
new_file=open(path+os.sep+"new_"+file_name,mode="wb")
new_file.write(buffer)
new_file.close()
```



- read(self,size=-1,/)

  - 完整读取文件所有内容，仅限只读模式
  - size: int, 要读取的字节数，默认为-1，即读取到EOF（End of File）。
  - return: 读取到的内容，t模式为str，b模式为bytes
- readline(self,size=-1,/)
  - 功能: 用于只读文本模式，读取当前行，文件对象会记录当前位置（即第几行），每读取一次，自动变更至下一行。
  - size: int，要读取的字节数，默认为-1，即读到EOF
  - return: str。str包含换行符

```python
#逐行打印
text=file.readline()
while text # str会进行bool转换，非空字符串即为True，只有一个换行符也是True，不过换行符都是在上一行的末尾出现，开头是不会出现换行符的
	print(text,end="") #由于每行都包含有换行符，因此打印就不必自动在末尾加换行符了
    text=file.readline()
```



- readlines(self)

  - 一次性读完每一行然后存储到列表中
  - return: list, 按顺序存储文本每一行的内容的列表。list中各个str元素包含换行符

- close(self)

  不关闭的话，对应的文件会一直处于占用状态

##### with上下文管理

​	with语句适用于对资源进行访问的场合，用于确保无论使用过程中有没有发生异常、资源使用结束后是否关闭IO流，都会自动执行必要的“清理”操作，释放资源（关闭IO流），比如文件使用后自动关闭、线程中锁的自动获取和释放等。在with引导的代码块执行结束后货中途出现异常，都自动关闭IO流，而不用再自行调用close()方法，**所以使用IO流时，建议都使用with进行上下文管理。**

​	with上下文的格式为：

```python
with open(file[,mode])	as file: # as是为open函数返回的对象取一个别名，即File对象的标识符。本例中为对象file，也可自定义为其他名称。file可以在with引导的子代码块block中使用，当子代码块结束后，会自动调用file.close(),无需开发者再单独关闭IO流，使用上较为方便，因此建议使用。
    block
```



##### csv文件处理

CSV文件格式，全称Comma-Separated Values(逗号分隔值)，是以纯文本形式存储表格数据，包括数字和文本，文件的扩展名是.csv。CSV文件由任意数目的记录组成，记录间以某种换行符分隔，每条记录由字段组成，字段间的分隔符是其他字符或字符串，最常见的是英文逗号“,”。CSV文件可以由Microsoft Office的Excel处理，也可以把Excel文件另存为CSV文件。CSV虽然不像Excel那样功能强大，不支持排版美化和函数功能等。但CSV非常轻量，效率高，非常适合用于存储原始数据。为了方便理解CSV，我们用Excel建立CSV文件。



插件推荐CSV Editor

###### 写入推荐csv模块

用来存储数据，写个爬虫、模拟仿真，用这个模块把数据存起来还是方便的

写入

```python
import csv
with open('filename.csv',mode="wt",newline='',encoding="utf-8") as csvfile #按csv模块的设计,newline=''参数不可遗漏,newline参数用于指定换行符，通常不使用，但在csv初始化中必须赋值为空字符''，否则会出现每次写入都多出一个空白行的情况。csv写入会自动换行，所以要把open里面的newline设置成空字符串
	cw=csv.writer(csvfile) # return: 一个用于操作指定文件的csv.writer对象
    #写单行
    cw.writerow(row) # row是列表或元组
    #写多行
    cw.writerows(rows) # rows是列表或元组的嵌套 如 [(,),(,)]
```

读取

```python
import csv
with open('filename.csv',mode='rt',encoding="utf-8") as file #读取不需要newline参数
	cr=csv.reader(file) #可迭代，可用for in遍历
    data=[] #嵌套列表
    fields=next(cr) # 迭代器实现了__next__方法了就可以使用next直接获取cr的内容并将指针指向下一个
    for row in cr:
        data.append(row)
    print(data)
```



###### 读取推荐pandas库

### 其他



#### pass语句

占位，还没想好代码块怎么写，可以先写个pass上去

应用场景：

1. 

```python
if 条件表达式:
    代码块1
else:
    pass
```

2. 抽象类中的抽象方法





#### 单双引号区别

无区别，合理使用可避免出现多个转义字符





## Pydantic

不同于python类型标注，Pydantic运行时会验证变量类型

‌**库介绍与功能特性**‌：Pydantic 是一个用于数据校验和数据模型管理的 Python 库，其核心理念是“数据校验即数据解析”，主要功能包括：

- ‌**数据校验**‌：自动检查输入数据的类型、格式和约束（如长度、范围等），确保符合模型定义。‌‌2‌‌3
- ‌**数据转换**‌：自动将原始数据（如 JSON、字典）转换为正确的 Python 类型，并支持嵌套模型和复杂结构。‌‌2‌‌
- ‌**模型定义**‌：通过继承 `BaseModel` 类定义数据模型，利用 Python 类型注解声明字段类型，支持默认值、可选字段和自定义验证规则。‌‌1‌‌2
- ‌**错误提示**‌：当数据无效时，提供直观、用户友好的验证错误信息，便于调试。‌‌1‌‌2
- ‌**序列化**‌：支持将模型实例转换为字典、JSON 等格式，方便 API 传输或存储。‌‌

```python
from pydantic import BaseModel
# 让类来继承BaseModel
#pydantic默认是必须赋值的，不然会报错。如果不赋值，法一：给默认值 法二：Optional
from typing import Optional
class Person(BaseModel):
    name:str
    age:int
    address:Optional[str]=None
p=Person(name=123,age=18)
print(p)
```



### Field模块

Field总是与Python的类型注解一起使用，共同定义字段的完整契约。

Field可用于提供有关字段和验证的额外信息，如设置必填项和可选，设置最大值和最小值，字符串长度等限制

关于Field字段参数说明

- `default`：字段的默认值，如不填则默认为None，即没有默认值。如添`...`表示该字段为必填项

- `title`：自定义标题，如果没有默认就是`字段属性的值`
- `description`：定义字段描述内容



## json

- `json.dump(obj, fp)`：将Python对象编码成JSON格式的字符串，并将其写入到一个文件类对象`fp`中。
- `json.dumps(obj)`：将Python对象编码成JSON格式的字符串。

```python
d={
    'a':"1",
    'b':"2",
}

json.dumps(d)
#对于中文会进行URL转码
```



- `json.load(fp)`：从一个文件类对象`fp`中读取JSON格式的数据，并将其解码成Python对象。
- `json.loads(s)`：将JSON格式的字符串`s`解码成Python对象。





## 数据库



### sqlalchemy

类似于`mybatis`

`langchain`数据库相关的应用也是使用的`sqlalchemy`

```python
#LangChainDeprecationWarning: `connection_string` was deprecated in LangChain 0.2.2 and will be removed in 1.0. Use connection instead.

#URL
#dialect+driver://username:password@host:port/database
#dialect 数据库，如：sqlite、mysql、oracle等
#driver 驱动，如pymysql
# sqlite 单文件的轻量级数据库
'sqlite:///chat_history.db'     # 直接访问文件   ///三斜杆表示相对路径（相对于当前工作目录）

# mysql C/S架构，需要独立的服务器进程运行
# 先确保安装了pymysql驱动包及flask-sqlalchemy
'mysql+pymysql://root:123456@localhost/fastapi_db?charset=utf8mb4'

#db2
# 需安装ibm-db,ibm_db_sa
'db2+ibm_db://user:pwd@host:port/database'

```



# Pycharm



## 新建项目，区分系统解释器和虚拟解释器

位置

重点放在项目环境配置

每个项目最好有自己独立的虚拟环境

- 生成新的

  venv（Virtualenv）即虚拟环境，会克隆系统解释器的标准库（仅含非第三方库，是Python程序运行所必要的库），而不克隆第三方库

  项目文件夹中出现.vene目录，则表示这是一个虚拟环境。

  如果用了虚拟环境，系统解释器中的第三方库就不能够用。

  为什么需要这个虚拟环境？让不同的项目使用各自独立的环境，就创建多套虚拟环境。共用一个系统解释器会出现啥问题？

  - **版本冲突**，新的项目用的是最新的版本，如果在系统解释器中全局更新了该库，老的项目要使用旧的版本。一更新，老的项目就跑不起来了。
  - **复杂的依赖关系**，这个库依赖那个库，那个库又依赖其他库，一层层的嵌套下来就会引发更多的版本冲突。

- 选择现有

  系统解释器，就是我们自己安装的那个python。

  特点：全局独一份，只要你用这个解释器，然后他下面的第三方库都能使用

若没有IDE，需要执行以下命令才能新建虚拟环境

`python -m venv .venv`来产生一个虚拟环境，`.venv`就是我们给虚拟环境起的名字，执行完毕后项目里就会多了一个.venv的目录。这个名字可以随便取，但是强烈推荐就叫`.venv`。因为现在的主流IDE，VSCode，Pycharm能够自动识别这个名字会比较方便。

`source .venv/bin/activate`激活环境

主要是修改了Python中的sys.path这个变量，sys.path本身是个列表，虚拟目录会被添加到这个列表。当import库时，就在这个路径列表中逐个检查，把对应的库导入。在没有激活虚拟环境时，sys.path中的列表包含的是Python的全局目录。

## 虚拟环境中下载第三方库

在cmd中用pip下载下来的第三方库，是放到系统解释器中的，不会下到虚拟环境中。因此不要在CMD里面下载。

正确的做法：

在Pycharm中点击视图菜单->工具窗口->终端，不管你是用的系统解释器还是虚拟环境，它都会自动定位到对应的项目根目录，是虚拟环境的会提示(.venv)





## 创建python文件

右键项目根目录->新建->Python文件，命名不一定要取main.py

## 修改python文件名

右键文件->重构->重命名



## 运行

有多个*.py文件，请在对应的文件中右键->运行

或

右键文件->运行

而不要使用右上角菜单栏里的运行





## 调试



### 查调试过程中某个变量

开启debug后，当运行到断点时，可在代码中选中你的变量右击菜单选`对表达式求值`，在弹出的窗口中点击`求值`按钮



# Conda





# Linux命令

 ## - 和 --的区别

可以把-或--后面跟的函数叫做选项，而这个选项后面也可以再跟参数

**-字符（单词的缩写）**

可以多个选项写在同一个横线后面

`tar -xcvf xxx`

在选项需要加参数的时候，参数可以紧跟在选项后面，也可以使用空格分隔

`mysql -u root -p`

`mysql -uroot -p`

**--单词全拼**

只能跟一个选项，该选项需要加参数时，参数可以使用=分隔，也可使用空格分隔

## .与..的区别

`.`代表当前目录

`..`代表上一级目录

## ~

当前登录用户的用户目录

## 软件管理工具

| 操作系统       | 格式 | 工具 | 查找              | 安装                 | 重新安装/修复          | 卸载（不包括配置文件） | 卸载（包括配置文件，不包括依赖） | 卸载（包括配置文件和依赖） | 更新       | 查看已安装的包       |
| -------------- | ---- | ---- | ----------------- | -------------------- | ---------------------- | ---------------------- | -------------------------------- | -------------------------- | ---------- | -------------------- |
| Debian, Ubuntu | .deb | apt  | apt show [软件名] | apt install [软件名] | apt reinstall [软件名] | apt remove [软件名]    | apt purge [软件名]               | apt autoremove [软件名]    | apt update | apt list --installed |
| CentOS         | .rpm | yum  |                   | yum install [软件名] |                        | yum remove [软件名]    |                                  |                            | yum update |                      |

apt-get是早期的apt，现在用apt即可

一次可安装多个软件

`apt install vim net-tools`

删除没有被任何包所使用到的相关依赖

`apt autoremove`

删除.deb安装包

`apt clean`

`apt autoclean`

## 网卡信息查询

需安装net-tools

`apt install net-tools`

`ifconfig`

## ping工具

需安装iputils-ping

`apt install iputils-ping`

`ping www.baidu.com`

## curl

## git

## wget

 Linux系统中的wget是一个下载文件的工具，它用在命令行下。对于Linux用户是必不可少的工具，我们经常要下载一些软件或从远程[服务器](https://cloud.tencent.com/product/cvm?from_column=20065&from=20065)恢复备份到本地服务器。wget支持HTTP，HTTPS和FTP协议，可以使用HTTP代理。所谓的自动下载是指，wget可以在用户退出系统的之后在后台执行。这意味这你可以登录系统，启动一个wget下载任务，然后退出系统，wget将在后台执行直到任务完成，相对于其它大部分浏览器在下载大量数据时需要用户一直的参与，这省去了极大的麻烦。

`wget [URL]`

## ls

列出当前目录下的文件



## 本地和服务器文件传输

使用rz和sz命令需要安装lrzsz程序

`yum install -y lrzsz` 

### rz

Receive Zmodem, rz命令用于从本地上传文件到服务器

XShell中输入命令`rz`弹出打开文件对话框，选择即可上传文件

### sz

Send Zmodem, sz命令用于从服务器上下载文件到本地

`sz [file_name]`



# 爬虫

## Web请求全过程

1. 请求->响应带有数据的HTML内容

![image-20260129092202874](C:/Users/Liangpeng Yan/AppData/Roaming/Typora/typora-user-images/image-20260129092202874.png)

2. 前端JS渲染

   请求->网页结构->请求->数据

主流网页都是这样架构的

前后端分离，分布式，可减少单台服务器压力

![前后端分离分布式](resources/前后端分离分布式.png)

也因为这样，有时候我查看源代码的时候，只发现个壳子，但具体数据在哪找不到.

数据是在网页结构壳子加载完毕后再加载的

## HTTP协议

请求：

```text
请求行->请求方式(get/post) 请求url地址 协议
请求头->放一些服务器要使用的附加信息，如验证信息,是不是浏览器发出的，是电脑设备还是手机设备
#该行空白作分割用，下一行是真正请求的内容
请求体->一般放一些请求参数         # 参数：周杰伦帅不帅
```

响应：

```text
状态行->协议(跟请求行对应) 状态码(200:ok 302:重定向(用户登录) 404:url错误 500:服务器错误)
响应头->放一些客户端要使用的一些附加信息(cookie,验证信息,解密的key(一堆数据是加密的，把密钥埋在响应头里)) 如下次客户发送请求的cookie验证，cookie一般都是从上一次响应里得到的
#该行空白作分割用，下一行是真正响应的内容
响应体->服务器返回的真正客户端要用的内容(HTML,json)等
```

![请求行请求头响应头](resources/请求行请求头响应头.png)

请求头中最常见的一些重要内容（爬虫需要）：

1. User-Agent: 请求载体的身份标识（用啥发送的请求）
2. Referer: 防盗链（这次请求是从哪个页面来的？反爬会用到）
3. cookie: 本地字符串数据信息（用户登录信息，反爬token）

响应头中一些重要的内容：

1. cookie: 本地字符串数据信息（用户登录信息，反爬的token）
2. 各种神奇的莫名奇妙的字符串（这个需要经验了，防止各种攻击和反爬）。如写一堆乱码，不用纠结肯定是有用的，都是为了反爬而设计的。

请求方式：

​	GET: 显示提交。提交的数据放在URL之后，以?分割URL和传输数据，参数之间以&相连，如EditPosts.aspx?name=test1&id=123456。或者放在Cookie传参。get请求数据不会出现在body中。只支持ASCII类型的数据

​	POST: 隐式提交。通过请求体传参。post请求数据类型没有限制，支持二进制数据

爬虫两个重要的点不好解决

二者的区别：参数放哪->显示传参会有安全问题，支持的参数的类型

- Cookie,token验证
- 响应体的内容解密

## 浏览器工具

主要看Elements、Console、Sources、Network，而剩余的Performance、Memory、Application、Security、Lighthouse都是前端需要关注的，这方面与性能有关。

### Elements

这里看到的代码和页面的源代码很可能是不一样的。Elements中的内容是经过JS脚本加载过的的内容。

### Console

可以写Javascript代码，作调试用。

JS逆向会用到

### Source

包括页面涉及到的所有资源（包括源代码）

### Network

抓包工具



#### 过滤条件

XHR：用的最多。数据资源封装对象

## 合法性问题

- 善良的爬虫，不破坏被爬取的网站的资源（正常访问，一般频率不高，不窃取用户隐私）

- 恶意的爬虫，影响网站的正常运营（抢票，秒杀，疯狂solo网站资源造成网站宕机）

步骤



安分守己，时常优化自己的爬虫程序避免干扰到网站的正常运行. 并且在使用爬取到的数据时，发现涉及到用户隐私和商业机密等敏感内容时，一定要及时终止爬取和传播。



- 获取网页内容页面源代码（html,css,js）
- 解析网页内容



## 爬虫的矛与盾

### 反爬机制

- 限制IP
- 设置复杂的验证码

### 反反爬策略



### robots.txt君子协议

规定了网站中哪些数据可以被爬虫爬取，哪些数据不可以被爬取。

这东西没有任何拦截意义

`域名/robots.txt`



## urllib

python内置的一个模块，并不是常用的爬虫工具。

#### urlopen(url,data)

- url
- data: 用于指定发送到服务器的额外数据。‌**当 `data` 为 `None`（默认值）时，请求方式为 GET；当提供了 `data` 参数时，请求方式会自动转换为 POST**‌。`data` 需要是 `bytes` 类型，通常通过 `urllib.parse.urlencode()` 将字典编码为字符串，再使用 `bytes()` 转换为字节流。‌‌
- return: `http.client.HTTPResponse` 对象

```python
from urllib.request import urlopen

url="http://www.baidu.com"
resp=urlopen(url)
#resp.read()#打印后是b'xxxxxx'，以b开头的表明获取的是字节类型内容，需要手动把字节串变成字符串
resp.read().decode("utf-8") # 关于这个是什么编码，直接在网页中搜索charset
```

#### HTTPResponse对象

读取方法如下

- read()
- readline()
- readlines()

由于读取到的原始数据通常是bytes类型，需要对字节流数据使用`decode()`方法进行解码

如何获取正确编码：直接在网页源码中搜索charset

获取响应信息方法如下

- getcode(): 返回HTTP状态码
- geturl(): 返回最终请求的实际url，可用于处理重定向。
- info()/getheaders(): 返回响应头信息

关闭连接

- close()



存储网页

```python
from urllib.request import urlopen
url="http://www.baidu.com"
resp=urlopen(url)
with open("xx.html",mode="wb") as f:
    f.write(resp.read())
```



## requests

```python
pip install requests
```

获取请求头信息

```python
resp.request.headers
```





### resp.get(url)

#### 获取网页源代码

```python
url="http://www.baidu.com"
resp=requests.get(url)
resp.encoding="utf-8" # 设置编码
resp.text # text默认是网页源代码
```

#### 参数

- 直接写到url后, url后加?再接参数
- 或写到param参数中，requests.get(url,params=c) 实际效果也是写到url中的。url后不需要加?

```python
hehe={
    "type":"13",
    "interval_id":"100:90",
    "action":"",
    "start":"0",
    "limit":"20"
}
resp=requests.get(url,params=hehe,headers=headers)
```

关于从浏览器复制参数的问题，可以用Ctrl+Shift+V，选择对应的格式化过的文本

### resp.post

浏览器中，参数放在post的Form Data/payLoad里

python中把参数写在data中



获取到的json格式数据，需要用resp.json()解析，否则就是一些编码

```python
resp=requests.post(url,data=hehe)
print(resp.json()['data']) #resp.json()返回的是字典，可以指定获取某个k-v
```



## 数据解析



### re 正则表达式

Regular Expression

不好写，但执行效率最高

在线测试正则表达式https://tool.oschina.net/regex/

| 元字符 |                                                            |
| ------ | ---------------------------------------------------------- |
| .      | 匹配除换行符以外的任意字符，未来在python的re模块中是一个坑 |
| \w     | 匹配字母或数字或下划线                                     |
| \s     | 匹配任意的空白符                                           |
| \d     | 匹配数字                                                   |
| \n     | 匹配一个换行符                                             |
| \t     | 匹配一个制表符                                             |
| ^      | 匹配字符串的开始。就是是否是从第一个字符开始               |
| $      | 匹配字符串的结尾                                           |
| \W     | 匹配非字母或数字或下划线                                   |
| \D     | 匹配非数字                                                 |
| \S     | 匹配非空白符                                               |
| a\|b   | 匹配字符a或字符b                                           |
| ()     | 匹配括号内的表达式，也表示一个组                           |
| […]    | 匹配字符组中的字符，如[a-zA-Z0-9]                          |
| [^…]   | 匹配除了字符组中字符的所有字符                             |



常用的匹配

```text
^\d{11}$ #手机号码
```





| 量词  |                 |      |
| ----- | --------------- | ---- |
| *     | 重复0次或更多次 |      |
| +     | 重复1次或更多次 |      |
| ？    | 重复0次或1次    |      |
| {n}   | 重复n次         |      |
| {n,}  | 重复n次或更多次 |      |
| {n,m} | 重复n到m次      |      |

.* 贪婪匹配  # *的意思是尽可能多的匹配 而.是除换行符以外的所有字符，就是尽可能多的非换行字符

.*? 惰性匹配 爬虫用的最多的，不取长

### xpath

简洁干练，爬虫框架





## 解析json格式的方法

`resp.json()` 返回的是字典

用[]层层获取

