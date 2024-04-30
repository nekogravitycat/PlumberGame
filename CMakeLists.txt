cmake_minimum_required(VERSION 3.10)
project(PlumberGame C CXX)

include(cmake/App.cmake)

set(SOURCES "src/main.cpp"
            "src/main.h"
            "src/Color.cpp"
            "src/Color.h"
            "src/Game.cpp"
            "src/Game.h"
            "src/Map.cpp"
            "src/Map.h"
            "src/Navigate.cpp"
            "src/Navigate.h"
            "src/Pipe.cpp"
            "src/Pipe.h"
            "src/Position.cpp"
            "src/Position.h"
    )

add_app("${SOURCES}")