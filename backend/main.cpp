#include <drogon/drogon.h>
using namespace drogon;
int main()
{
    app()
        .registerHandler("/hello", [](const HttpRequestPtr& req,
                       std::function<void (const HttpResponsePtr &)> &&callback)
                    {
                        Json::Value json;
                        json["result"]=200;
                        json["message"]=std::string("hello");
                        auto resp=HttpResponse::newHttpJsonResponse(json);
                        callback(resp);
                    },
                    {Get,"helloworld"})
        .registerHandler("/hello/{name}", [](const HttpRequestPtr& req,
                       std::function<void (const HttpResponsePtr &)> &&callback,
                       const std::string &name)
                    {
                        Json::Value json;
                        json["result"]=200;
                        json["message"]=std::string("hello, ") + name;
                        auto resp=HttpResponse::newHttpJsonResponse(json);
                        callback(resp);
                    },
                    {Get,"helloworld"})
        .setLogPath("./")   
        .setLogLevel(trantor::Logger::kWarn)
        .addListener("0.0.0.0", 8001)
        .setThreadNum(16)
        .run();
}