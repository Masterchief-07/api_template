from api.config import Setting
from sqlalchemy import create_engine, select, Select, func, Engine
from sqlalchemy.orm import Session, MappedColumn


engine = create_engine(Setting.DATABASE_URL)


def get_db() -> Session:
    with Session(engine) as db:
        yield db

def count(db:Session, Table)-> int:
    return db.scalar(select(func.count()).select_from(Table))

def pagination(data:Select, page:int=0, nb_per_page:int=10) -> Select:
    return data.offset(page*nb_per_page).limit(nb_per_page)

def order_by(data:Select, Table_components:MappedColumn, descending:bool=True)-> Select:
    if descending:
        return data.order_by(Table_components.desc())
    return data.order_by(Table_components.asc())

       
def init_database(engine:Engine):
    from sqlalchemy_utils import create_database, database_exists
    if not database_exists(engine.url):
        create_database(engine.url) 
    from .base import Base
    Base.metadata.create_all(engine)