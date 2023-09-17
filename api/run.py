from api import createAPP

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("api:createAPP", factory=True, host="0.0.0.0", port=80, reload=True)    