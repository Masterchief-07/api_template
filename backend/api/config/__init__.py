from typing import Type
from pydantic_settings import BaseSettings, PydanticBaseSettingsSource

class SETTINGS(BaseSettings):
    DATABASE_URL: str
    REDIS_HOST : str|None = None
    REDIS_PORT : str|None = None
    REDIS_PASSWORD : str|None = None
    JWT_SECRET:str|None = None
    JWT_ALGORITHM: str|None = None

    @classmethod
    def settings_customise_sources(
        cls,
        settings_cls: Type[BaseSettings],
        init_settings: PydanticBaseSettingsSource,
        env_settings: PydanticBaseSettingsSource,
        dotenv_settings: PydanticBaseSettingsSource,
        file_secret_settings: PydanticBaseSettingsSource,
    ) -> tuple[PydanticBaseSettingsSource, ...]:
        return  dotenv_settings, env_settings,  file_secret_settings, init_settings

TESTING = SETTINGS(
    DATABASE_URL="sqlite:///./test.db",
)

Setting : SETTINGS|None = TESTING