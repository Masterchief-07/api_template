from fastapi import FastAPI

def createAPP() -> FastAPI:
    from api.views import hello_route, healthcheck_router, example_router
    app = FastAPI(
        title = "backend_template",
        description = "template for future projects",
    )

    #adding endpoints
    app.include_router(hello_route, prefix="/api/v1/hello")
    app.include_router(example_router, prefix="/api/v1/example")
    app.include_router(healthcheck_router, prefix="/api/v1/healthcheck")

    #adding middlewares
    from starlette.middleware.errors import ServerErrorMiddleware
    from fastapi.middleware.cors import CORSMiddleware
    # ------add error stack information---------
    app.add_middleware(ServerErrorMiddleware, debug=True)
    # ------get request from any webpage---------
    app.add_middleware(
        CORSMiddleware,
        allow_origins=["*"],
        allow_credentials=True,
        allow_methods=["*"],
        allow_headers=["*"],
    )
    # --------add logger for each an every request--------
    from api.config.req_logging import RouterLoggingMiddleware, request_logger
    app.add_middleware(RouterLoggingMiddleware,
                       logger=request_logger,
                       exclude_path = [
                           "/api/v1/healthcheck/",
                           "/docs",
                           "/openapi.json",
                           "/metrics"
                       ])
    from fastapi import HTTPException, Request
    from fastapi.responses import JSONResponse
    from api.config.logging import logError

    @app.exception_handler(HTTPException)
    def handleHTTPException(req, exc: HTTPException):
        logError(exc.detail)
        return JSONResponse(
            content={"status": -1, "message": f"{exc.detail}"},
            status_code=exc.status_code,
        )

    @app.exception_handler(Exception)
    def handleException(req, exc:Exception):
        logError(exc)
        return JSONResponse(
            content={"status": -1, "message": f"INTERNAL ERROR"},
            status_code=500
        )

    #init database
    from api.database import init_database, engine
    init_database(engine)

    return app
