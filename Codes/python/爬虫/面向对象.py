class Dog:
    """这是一个狗狗类"""
    def __init__(self,name):
        self.name=name
        print('生成一只狗狗',self)
    def bark(self):
        print('汪汪')
    def bark2(self):
        self.bark()
        self.bark()
    def get_name(self):
        return self.name

class Cat():
    """这是一个猫猫类"""
    pass

my_dog = Dog('王祥')
print(my_dog)
my_cat = Cat()
my_dog.bark()
print(my_dog.name)
print(my_dog.get_name())
my_dog.bark2()