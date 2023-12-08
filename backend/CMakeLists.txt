cmake_minimum_required (VERSION 3.20)

project(
        backend
        VERSION 0.0.1
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set("DCMAKE_TOOLCHAIN_FILE", "/home/jonathan/vcpkg/scripts/buildsystems/vcpkg.cmake")
include("/home/jonathan/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(Drogon CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Drogon::Drogon fmt::fmt)