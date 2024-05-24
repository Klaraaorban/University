cmake_minimum_required(VERSION 3.27)
project(L3_Orban_Klara)

set(CMAKE_CXX_STANDARD 17)

add_executable(L3_Orban_Klara main.cpp
        DSM.h
        DSM.cpp
        DSM_test.cpp)
