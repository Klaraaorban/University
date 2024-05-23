cmake_minimum_required(VERSION 3.27)
project(test1)

set(CMAKE_CXX_STANDARD 17)

add_executable(test1 main.cpp
        Graph.cpp
        Graph.h
        Graph2.h
        Graph2.cpp)
