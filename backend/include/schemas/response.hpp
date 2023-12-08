#pragma once
#include <drogon/drogon.h>

drogon::HttpResponsePtr response(int status, std::string message){
    Json::Value result;
    result["status"] = status;
    result["message"] = message;
    auto resp=drogon::HttpResponse::newHttpJsonResponse(result);
    return resp;
}
drogon::HttpResponsePtr response(int status, std::string message, Json::Value data){
    Json::Value result;
    result["status"] = status;
    result["message"] = message;
    result["data"] = data;
    auto resp=drogon::HttpResponse::newHttpJsonResponse(result);
    return resp;
}

