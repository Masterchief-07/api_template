cmake_minimum_required (VERSION 3.20)

project(
        backend
        VERSION 0.0.1
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wfloat-conversion)

file(COPY config.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Drogon CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Drogon::Drogon fmt::fmt)