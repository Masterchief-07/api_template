from api import createAPP

app = createAPP()

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("run:app", host="0.0.0.0", port=80, reload=True)    