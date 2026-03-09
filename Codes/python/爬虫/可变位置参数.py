def my_func(a,*args,b):
    print(a,args,b)

if __name__ == '__main__':
    my_func(1,2,b=5)