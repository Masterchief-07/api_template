#include <drogon/drogon.h>
#include <views/hello.hpp>
#include <views/example.hpp>
using namespace drogon;
int main()
{
    app()
        // .setLogPath("./")   
        // .setLogLevel(trantor::Logger::kWarn)
        .loadConfigFile("config.json")
        .run();
}