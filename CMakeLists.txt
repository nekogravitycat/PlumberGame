cmake_minimum_required(VERSION 3.10)
project(MyApp C CXX)

include(cmake/App.cmake)

set(SOURCES "src/Color.h"
            "src/Game.h"
            "src/main.cpp"
            "src/Map.h"
            "src/Navigate.h"
            "src/Pipe.h"
            "src/Position.h")

add_app("${SOURCES}")