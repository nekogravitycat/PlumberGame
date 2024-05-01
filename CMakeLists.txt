cmake_minimum_required(VERSION 3.16)
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

# SFML
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})