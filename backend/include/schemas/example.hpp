#pragma once
#include <drogon/drogon.h>

struct ExampleSchema {
    std::string name;

    Json::Value to_json();
};

Json::Value ExampleSchema::to_json(){
    Json::Value data;
    data["name"] = name;
    return data;
}

namespace drogon{
    template <>
    inline ExampleSchema fromRequest(const HttpRequest &req){
        auto json = req.getJsonObject();
        ExampleSchema ex;
        if(json)
        {
            ex.name = (*json)["name"].asString();
        }
        return ex;
    }
}