import requests

url="https://fanyi.baidu.com/sug"
# 反爬属性有
# User-Agent 默认为python-requests/x.xx.x 显然不是正常的浏览器，需要伪装
headers={
    # 添加一个请求头信息.UA
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/144.0.0.0 Safari/537.36"
}
data={
    "kw":input('请输入单词'),
}
resp=requests.post(url,headers=headers,data=data)
print(resp.json()['data'])