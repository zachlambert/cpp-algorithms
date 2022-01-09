cmake_minimum_required(VERSION 3.0)
project(
    "Algorithms"
    VERSION 0.1.0
    DESCRIPTION "A bunch of algorithms implemented in C++"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)
