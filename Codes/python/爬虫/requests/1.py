import requests

content=input('请输入你要检索的内容:')
url=f"http://www.baidu.com/s?wd={content}"
# 反爬属性有
# User-Agent 默认为python-requests/x.xx.x 显然不是正常的浏览器，需要伪装
headers={
    # 添加一个请求头信息.UA
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/144.0.0.0 Safari/537.36"
}

resp=requests.get(url,headers=headers)
#resp=requests.get(url)
#print(resp.text)
print(resp.request.headers)