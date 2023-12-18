#include <drogon/drogon.h>
#include <views/hello.hpp>
#include <views/example.hpp>
int main()
{
    drogon::app()
        // .setLogPath("./")   
        // .setLogLevel(trantor::Logger::kWarn)
        .loadConfigFile("config.json")
        .run();
}