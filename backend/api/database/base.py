from sqlalchemy import func
from sqlalchemy import CHAR, Column, Date, DateTime, Float, ForeignKeyConstraint, Index, Integer, JSON, String, TIMESTAMP, Table, Text, text, ForeignKey, DECIMAL, BOOLEAN
from sqlalchemy.dialects.mysql import CHAR, INTEGER, TEXT, TINYINT, VARCHAR
from sqlalchemy.orm import DeclarativeBase, Mapped, MappedAsDataclass, mapped_column, relationship
import datetime

class Base(MappedAsDataclass, DeclarativeBase):
    pass