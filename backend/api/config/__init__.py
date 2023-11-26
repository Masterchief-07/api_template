from pydantic_settings import BaseSettings

class SETTINGS(BaseSettings):
    IS_PROD:str
    API_NAME:str
    DATABASE:str
