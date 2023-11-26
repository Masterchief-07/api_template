#where i store Database models
from datetime import datetime
from .base import *
from enum import IntEnum, Enum, StrEnum
from .basetemplate import BaseTemplate
from datetime import datetime as datetime_details

#utils when i want to test them on sqlite
UnsignedInt = Integer()
UnsignedInt = UnsignedInt.with_variant(
    INTEGER(unsigned=True), 'mysql'
)
CustomBoolean = Integer()
CustomBoolean = CustomBoolean.with_variant(
    TINYINT, 'mysql', 'mariadb'
)

class Example(Base, BaseTemplate):
    __tablename__ = "example"
    id:Mapped[int] = mapped_column(UnsignedInt, init=False,autoincrement=True, nullable=False, primary_key=True)
    nom:Mapped[str] = mapped_column(VARCHAR(50), init=True, nullable=False)