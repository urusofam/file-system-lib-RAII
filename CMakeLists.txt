cmake_minimum_required(VERSION 3.30)
project(FileHandler CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FileHandlerLib STATIC FileHandler.cpp FileHandler.h)

add_executable(demo main.cpp)

target_link_libraries(demo PRIVATE FileHandlerLib)