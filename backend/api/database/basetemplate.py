from typing import Self
from fastapi.exceptions import HTTPException
from sqlalchemy.orm import Session, Query

class BaseTemplate():

    @classmethod
    def query(cls, db:Session) -> Query:
        return db.query(cls)

    @classmethod
    def get(cls, db:Session, error_msg:str="model not found", **kwargs) ->Self:
        result = db.query(cls).filter_by(**kwargs).first()
        if result == None:
            raise HTTPException(status_code=404, detail=error_msg)
        return result
    
    @classmethod
    def getOrNone(cls, db:Session, **kwargs) -> Self:
        result = db.query(cls).filter_by(**kwargs).first()
        return result
    
    @classmethod
    def getAll(cls, db:Session) -> list[Self]:
        return db.query(cls).all()
    
    @classmethod
    def getAllFilterBy(cls,db:Session, **kwargs) -> list[Self]:
        return db.query(cls).filter_by(**kwargs).all()

    def commit(self, db:Session) -> Self:
        db.commit()
        return self
    
    def save(self, db:Session) -> Self:
        db.add(self)
        # db.refresh(self)
        return self
    
    def saveWithCommit(self, db:Session) -> Self:
        db.add(self)
        db.commit()
        db.refresh(self)
        return self
    
    def delete(self, db:Session) -> Self:
        db.delete(self)
        return self
    
    def deleteWithCommit(self, db:Session) -> Self:
        db.delete(self)
        db.commit()
        return self