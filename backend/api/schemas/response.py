from typing import Generic, TypeVar
from pydantic import BaseModel

TypeX = TypeVar('TypeX')
class Response(BaseModel, Generic[TypeX]):
    status:int = 200
    message:TypeX|str

class ResponsePagi(BaseModel, Generic[TypeX]):
    status:int = 200
    message:list[TypeX|str]
    total_nb:int
    nb:int