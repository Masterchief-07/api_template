#include <drogon/drogon.h>
#include <views/hello.hpp>
#include <views/example.hpp>
using namespace drogon;
int main()
{
    app()
        // .setLogPath("./")   
        // .setLogLevel(trantor::Logger::kWarn)
        .addListener("0.0.0.0", 8001)
        .setThreadNum(16)
        .run();
}