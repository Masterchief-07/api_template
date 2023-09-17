from fastapi import FastAPI

def createAPP() -> FastAPI:
    from api.views import hello_route
    app = FastAPI()
    app.include_router(hello_route)
    return app

# app = createAPP()