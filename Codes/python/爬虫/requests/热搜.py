#微博热搜

import requests

url="https://weibo.com/ajax/side/hotSearch"
headers={
    "referer":"https://weibo.com/hot/search",
}
resp=requests.get(url,headers=headers)

print("微博热搜".center(38, '='))
for i in range(0,55):
    real_pos=resp.json()['data']['realtime'][i].get("realpos",0)
    if real_pos>0:
        word=str(resp.json()['data']['realtime'][i]['word'])
        num=resp.json()['data']['realtime'][i]['num']

        print(f"[{real_pos:02d}][{num:09d}]:{word}")
    if real_pos==50:
        break

# 抖音热榜

print("抖音热搜".center(38, '='))
url="https://so-landing.douyin.com/aweme/v1/hot/search/list/?aid=581610&detail_list=1&board_type=0&board_sub_type=&need_board_tab=true&need_covid_tab=false&version_code=32.3.0"
headers={

}
resp=requests.get(url,headers=headers)

for i in range(0,55):
    real_pos=resp.json()['data']['word_list'][i].get("position",0)
    if real_pos>0:
        word=str(resp.json()['data']['word_list'][i]['word'])
        num=resp.json()['data']['word_list'][i]['hot_value']

        print(f"[{real_pos:02d}][{num:09d}]:{word}")
    if real_pos==50:
        break