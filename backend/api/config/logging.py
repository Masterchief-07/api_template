import logging
from logging import Logger
from logging.handlers import TimedRotatingFileHandler
import inspect
from pydantic import BaseModel

# file_handler = logging.FileHandler("app.log")
file_handler = TimedRotatingFileHandler(
    filename="./logs/logs.log",
    when="D"
)
file_handler.setLevel(logging.DEBUG)
formatter = logging.Formatter("%(asctime)s - %(caller_path)-35s:%(caller_lineno)d - %(levelname)-8s - %(message)s")
file_handler.setFormatter(formatter)
logger = logging.getLogger("API")
logger.setLevel(logging.DEBUG)
logger.addHandler(file_handler)

def __toLog(logger: Logger, resp:BaseModel | dict, atype:int):
    caller_filename = inspect.stack()[2].filename
    caller_lineno = inspect.stack()[2].lineno
    match atype:
        case 0:
            _log = logger.info
        case 1:
            _log = logger.debug
        case 2:
            _log = logger.exception
        case other:
            raise Exception("an error in the log")
    if type(resp) == BaseModel:
        _log(f"{resp.model_dump()}", extra={
            'caller_path':caller_filename,
            'caller_lineno':caller_lineno,
        })
    else:
        _log(f"{resp}", extra={
            'caller_path':caller_filename,
            'caller_lineno':caller_lineno
        })
    return resp

def logResponse(resp:BaseModel | dict):
    return __toLog(logger, resp, 0)

def logInfo(resp:BaseModel | dict):
    return __toLog(logger, resp, 0)

def logDebug(resp:BaseModel | dict):
    return __toLog(logger, resp, 1)

def logError(resp:BaseModel | dict):
    return __toLog(logger, resp, 2)