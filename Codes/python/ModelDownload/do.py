L=[1,2,3,4,5]
T=(1,'a',2,'3')
S= {1, 'a', 2, '3'}
D={'a':1, 'b':2, 'c':3}
for i in L:
    print(i)

for i in T:
    print(i)
for i in S:
    print(i)

for key,value in D.items():
    print(f"{key}:{value}")