import requests

url="https://api.jijinhao.com/sQuoteCenter/realTime.htm?code=JO_92233&isCalc=true"
headers={
"referer":"https://quote.cngold.org/",
"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/144.0.0.0 Safari/537.36 Edg/144.0.0.0"
}
resp=requests.get(url,headers=headers)
print(resp)
print(resp.text)
