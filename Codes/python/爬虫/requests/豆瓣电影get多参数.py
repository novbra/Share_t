import requests


url="https://movie.douban.com/j/chart/top_list?"
headers={
    "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/144.0.0.0 Safari/537.36"
}


params={
    "type":"13",
    "interval_id":"100:90",
    "action":"",
    "start":"0",
    "limit":"20",
}
resp=requests.get(url,headers=headers,params=params)

print(resp.json())