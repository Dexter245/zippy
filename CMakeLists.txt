cmake_minimum_required(VERSION 3.7)
project(zippy)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(zippy
        source/main.cpp)
