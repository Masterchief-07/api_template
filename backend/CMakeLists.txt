cmake_minimum_required (VERSION 3.20)

project(BACKEND
        VERSION 0.0.1
        LANGUAGES CXX)

# set("DCMAKE_TOOLCHAIN_FILE", "/home/jonathan/vcpkg/scripts/buildsystems/vcpkg.cmake")
include("/home/jonathan/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME} main.cpp)

find_package(Drogon CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon fmt::fmt)