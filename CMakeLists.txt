cmake_minimum_required(VERSION 3.16)

project(beautiful-life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.5.0
)
FetchContent_MakeAvailable(spdlog)

add_executable(beautiful-life main.cpp lifeuniverse.cpp)

target_link_libraries(beautiful-life spdlog)