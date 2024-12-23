cmake_minimum_required(VERSION 3.27)
project(L4_Orban_Klara)

set(CMAKE_CXX_STANDARD 17)

add_executable(L4_Orban_Klara FruitApp.cpp
        UI/FruitUI.h
        UI/FruitUI.cpp
        Repository/FruitRepo.h
        Repository/FruitRepo.cpp
        Controller/FruitController.h
        Controller/FruitController.cpp
        Domain/Fruit.h
        Domain/Fruit.cpp
        Test/FruitTests.cpp)
