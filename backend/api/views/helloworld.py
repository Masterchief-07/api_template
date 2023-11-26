from fastapi import APIRouter, HTTPException
import api.services.helloworld as helloservices
from api.schemas.response import Response

hello_route = APIRouter(tags=["hello"])

@hello_route.get("/",
        response_model = Response[dict]
        )
def get_helloworld():
    resp = helloservices.helloword()
    return Response(
        status=200,
        message=resp
    )

@hello_route.get("/{name}",
        response_model = Response[dict]
        )
def get_custom_hello(name:str):
    resp = helloservices.hello(name)
    return Response(
        status=200,
        message=resp,
    )