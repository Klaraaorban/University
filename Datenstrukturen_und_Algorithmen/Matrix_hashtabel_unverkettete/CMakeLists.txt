cmake_minimum_required(VERSION 3.27)
project(Matrix_hashtabel)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix_hashtabel App.cpp
        Matrix.cpp
        ShortTest.cpp
        ExtendedTest.cpp)
