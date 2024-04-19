cmake_minimum_required(VERSION 3.10)
project(MyApp C CXX)

include(cmake/App.cmake)

set(SOURCES "src/MyApp.h"
            "src/MyApp.cpp"
            "src/main.cpp")

add_app("${SOURCES}")