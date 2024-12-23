cmake_minimum_required(VERSION 3.27)
project(Multi_map)

set(CMAKE_CXX_STANDARD 17)

add_executable(Multi_map
        ExtendedTest.h
        ExtendedTest.cpp
        ShortTest.cpp
        MultiMapIterator.cpp
        MultiMap.cpp
        App.cpp)
