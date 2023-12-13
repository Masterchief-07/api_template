from typing import Generic, TypeVar
from pydantic import BaseModel

TypeX = TypeVar('TypeX')
class Response(BaseModel, Generic[TypeX]):
    status:int = 200
    message:str
    data:TypeX|None = None

class ResponsePagi(BaseModel, Generic[TypeX]):
    status:int = 200
    message:str
    data:TypeX|None = None
    total_nb:int
    nb:int