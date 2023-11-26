from fastapi import APIRouter, HTTPException
import api.services.helloworld as helloservices

hello_route = APIRouter(prefix="/hello")

@hello_route.get("/")
def get_helloworld():
    resp = helloservices.helloword()
    return resp

@hello_route.get("/{name}")
def get_custom_hello(name:str):
    resp = helloservices.hello(name)
    return resp