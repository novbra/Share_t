a=1
def my_func1():
    a=2
def my_func2():
    global a
    global b
    a=2
    b=1
my_func1()
print(a)
my_func2()
print(a)
print(b)