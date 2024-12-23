cmake_minimum_required(VERSION 3.28)
project(SortedMap_bst)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortedMap_bst main.cpp
        SMIterator.h
        SortedMap.cpp
        SMIterator.cpp
        ExtendedTest.cpp
        ShortTest.cpp)
