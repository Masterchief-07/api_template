cmake_minimum_required (VERSION 3.20)

project(BACKEND
        VERSION 0.0.1
        LANGUAGES CXX)

include(dependencies/CPM.cmake)
CPMAddPackage(
  NAME asiocmake
  GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
  GIT_TAG "main"
)
CPMAddPackage(
  NAME crow
  GIT_REPOSITORY "https://github.com/CrowCpp/Crow.git"
  GIT_TAG "v1.0+5"
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Crow::Crow)