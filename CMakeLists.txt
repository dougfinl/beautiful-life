cmake_minimum_required(VERSION 3.16)

project(beautiful-life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include(FetchContent)

add_executable(beautiful-life main.cpp lifeuniverse.cpp lifemainwindow.cpp)

target_link_libraries(beautiful-life Qt5::Widgets)