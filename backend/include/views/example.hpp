#pragma once

#include<fmt/core.h>
#include <drogon/HttpController.h>
#include <schemas/response.hpp>
#include <schemas/example.hpp>
#include <database/example.hpp>

using namespace drogon;
class Examples :public HttpController<Examples>
{
    public:
        METHOD_LIST_BEGIN
        ADD_METHOD_TO(Examples::getExamples, "/example/", Get);
        ADD_METHOD_TO(Examples::getAnExample, "/example/{1}", Get);
        ADD_METHOD_TO(Examples::postAnExample, "/example/", Post);
        ADD_METHOD_TO(Examples::patchAnExample, "/example/{1}", Patch);
        ADD_METHOD_TO(Examples::deleteAnExample, "/example/{1}", Delete);
        METHOD_LIST_END

        void getExamples(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback);
        void getAnExample(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int id);
        void postAnExample(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    ExampleSchema &&ex);
        void patchAnExample(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int id, ExampleSchema &&ex);
        void deleteAnExample(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int id);

};
void Examples::getExamples(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback)
            {
                auto client = drogon::app().getDbClient();
                auto all_examples = database::Example::getAll(client);
                Json::Value result{};
                for (auto data : all_examples){
                    result.append(data.to_json());
                }
                auto resp = response(
                    200,
                    fmt::format("all examples"),
                    result
                );
                callback(resp);
            }
void Examples::getAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id)
            {
                auto client = drogon::app().getDbClient();
                auto data = database::Example::getById(client, (uint) id);
                if (data.id == 0){
                    auto resp = response(
                        404,
                        fmt::format("example id {} not found", id)
                    );
                    callback(resp);
                }
                else {
                    auto resp = response(
                        200,
                        fmt::format("{} examples", id),
                        data.to_json()
                    );
                    callback(resp);
                }
            }
void Examples::postAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            ExampleSchema &&ex)
            {
                auto client = drogon::app().getDbClient();
                database::Example data{
                    0,
                    ex.name
                };
                if (database::Example::addOne(client, data)) {
                auto resp = response(
                    201,
                    fmt::format("example created"),
                    ex.to_json()
                );
                callback(resp);
                }
                else {
                    auto resp = response(
                    500,
                    fmt::format("INTERNAL SERVER ERROR")
                );
                callback(resp);
                }
            }
void Examples::patchAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id, ExampleSchema &&ex)
            {
                auto client = drogon::app().getDbClient();
                database::Example data{
                    0,
                    ex.name
                };
                if (database::Example::updateOne(client, id, data)) {
                auto resp = response(
                    200,
                    fmt::format("example id {} modified", id),
                    ex.to_json()
                );
                callback(resp);
                }
                else {
                    auto resp = response(
                    404,
                    fmt::format("example id {} not found", id)
                );
                callback(resp);
                }
            }
void Examples::deleteAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id)
            {
                auto client = drogon::app().getDbClient();
                if (database::Example::deleteOne(client, id)) {
                auto resp = response(
                    200,
                    fmt::format("example id {} deleted", id)
                );
                callback(resp);
                }
                else {
                    auto resp = response(
                    404,
                    fmt::format("example id {} not found", id)
                );
                callback(resp);
                }
            }
drogon::orm::Result