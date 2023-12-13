from api.database import Session, get_db, Example
from api.schemas import example as example_schema
from api.schemas.response import Response
from fastapi import Body, Query, Path, Form, Depends

def getAnExample(
        id:int = Path(ge=1),
        db:Session = Depends(get_db)
) -> Response[Example]:
    example = Example.get(db, error_msg=f"Example id {id} is not found",
                          id = id)
    return Response(
        status=200,
        message="an example",
        data=example
    )

def getExamples(
        db:Session = Depends(get_db)
) -> Response[list[Example]]:
    examples = Example.getAll(db)
    return Response(
        status=200,
        message="all example",
        data=examples
    )

def postExample(
        data:example_schema.Example = Body(),
        db:Session = Depends(get_db)
) -> Response[Example]:
    example = Example(**data.model_dump()).saveWithCommit(db)
    return Response(
        status=201,
        message="example created",
        data=example
    )

def patchExample(
        id:int = Path(ge=1),
        data:example_schema.Example = Body(),
        db:Session = Depends(get_db)
) -> Response[Example]:
    example = Example.get(db, error_msg=f"Example id {id} is not found",
                          id = id)
    example.name = data.name
    example.saveWithCommit(db)
    return Response(
        status=200,
        message="example patched",
        data=example
    )

def deleteExample(
        id:int = Path(ge=1),
        db:Session = Depends(get_db),
) -> Response[str]:
    example = Example.get(db, error_msg=f"Example id {id} is not found",
                          id = id)
    example.deleteWithCommit(db)
    return Response(
        status=200,
        message="example deleted",
    )


