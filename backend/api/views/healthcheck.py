from fastapi import APIRouter

healthcheck_router = APIRouter(tags=['HEALTHCHECK'])

@healthcheck_router.get("/")
def check():
    return "OK"