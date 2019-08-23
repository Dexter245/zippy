cmake_minimum_required(VERSION 3.7)
project(zippy)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(zippy
        source/main.cpp include/ZipWriter.h include/ZipFileWriter.h source/ZipWriter.cpp source/ZipFileWriter.cpp include/ZipConst.h)
