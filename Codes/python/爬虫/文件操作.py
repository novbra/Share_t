import csv
import os

file=open("a.txt","r",encoding="utf-8")
print(file.read(-1))
file.close()

file=open("b.txt","wt",encoding="utf-8")
file.write("舒服")
file.close()
file=open("b.txt","r",encoding="utf-8")
print(file.read(-1))
file.close()
file=open("b.txt","at",encoding="utf-8")
file.write("1")
file.close()


file=open("按行读取.txt","rt",encoding="utf-8")
l=file.readlines()
print(l)
file.close()


file=open("按行读取.txt","rt",encoding="utf-8")
text=file.readline()
while text:
    print(text,end="")
    text=file.readline()
file.close()

print(bool('\n'))

# 读取图片
file=open("baidu.png","rb")
print(file.read())
file.close()

# 文件复制
path=os.getcwd()
file_name="baidu.png"
file=open(path+os.sep+file_name,mode="rb")
buffer=file.read()
file.close()
new_file=open(path+os.sep+"new_"+file_name,mode="wb")
new_file.write(buffer)
new_file.close()
# with 上下文管理
with open("baidu.txt",mode="wt",encoding="utf-8") as f:
    f.write("a")

# csv文件写入

with open("csvtest.csv",mode="wt",newline="",encoding="utf-8") as f:
    cw=csv.writer(f)
    fields=("uid","name","gender","age")
    cw.writerow(fields)
    line=("001","王祥","女","23")
    cw.writerow(line)
    lines = [("002", "老红花", "女", "23"),("003","王祥","女","23")]
    cw.writerows(lines)

# csv文件读取

with open("csvtest.csv",mode="rt",encoding="utf-8") as f:
    cr=csv.reader(f)
    data=[]
    for row in cr:
        data.append(row)
    print(data)