import os
from urllib.request import urlopen

url="http://www.baidu.com"

resp=urlopen(url)

#print(resp.read().decode("utf-8"))
print(resp.getcode())
#print(os.getcwd())
#print(os.sep)


# 存储页面

with open("baidu.html",mode="wb") as f:
    f.write(resp.read())