#pragma once
#include <drogon/drogon.h>

drogon::HttpResponsePtr response(uint status, std::string message){
    Json::Value result;
    result["status"] = status;
    result["message"] = message;
    auto resp=drogon::HttpResponse::newHttpJsonResponse(result);
    resp.get()->setStatusCode((drogon::HttpStatusCode) status);
    return resp;
}
drogon::HttpResponsePtr response(uint status, std::string message, Json::Value data){
    Json::Value result;
    result["status"] = status;
    result["message"] = message;
    result["data"] = data;
    auto resp=drogon::HttpResponse::newHttpJsonResponse(result);
    resp.get()->setStatusCode((drogon::HttpStatusCode) status);
    return resp;
}

