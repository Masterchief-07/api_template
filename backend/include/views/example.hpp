#pragma once

#include<fmt/core.h>
#include <drogon/HttpController.h>
#include <schemas/response.hpp>
#include <schemas/example.hpp>

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
                auto resp = response(
                    200,
                    fmt::format("all examples")
                );
                callback(resp);
            }
void Examples::getAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id)
            {
                auto resp = response(
                    200,
                    fmt::format("{} examples", id)
                );
                callback(resp);
            }
void Examples::postAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            ExampleSchema &&ex)
            {
                auto resp = response(
                    201,
                    fmt::format("example created"),
                    ex.to_json()
                );
                callback(resp);
            }
void Examples::patchAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id, ExampleSchema &&ex)
            {
                auto resp = response(
                    200,
                    fmt::format("example id {} modified", id),
                    ex.to_json()
                );
                callback(resp);
            }
void Examples::deleteAnExample(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            int id)
            {
                auto resp = response(
                    200,
                    fmt::format("example id {} deleted", id)
                );
                callback(resp);
            }