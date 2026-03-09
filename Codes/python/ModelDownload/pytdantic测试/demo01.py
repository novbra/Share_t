#from dataclasses import dataclass
from pydantic import BaseModel
#@dataclass
class Person(BaseModel):
    name:str
    age:int
p=Person(name=123,age=18)
print(p)