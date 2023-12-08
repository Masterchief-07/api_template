#pragma once
#include <drogon/drogon.h>

namespace backend_template{
using namespace drogon;
class HelloClass:public drogon::HttpController<HelloClass>
{
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(HelloClass::sayHello, "/", Get);
        METHOD_ADD(HelloClass::sayHelloTo, "/{name}", Get);
        METHOD_LIST_END

        void sayHello(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback);
        void sayHelloTo(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    const std::string& name);

};

void HelloClass::sayHello(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback)
            {
                Json::Value json;
                json["result"]=200;
                json["message"]=std::string("hello");
                auto resp=HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            }
void HelloClass::sayHelloTo(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            const std::string& name)
            {
                Json::Value json;
                json["result"]=200;
                json["message"]=std::string("hello ")+name;
                auto resp=HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            }
}