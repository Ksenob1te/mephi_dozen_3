cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME mephi_dozen_3)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

add_executable(mephi_dozen_3 main.cpp)
add_executable(lab_1 lab_1/data.cpp lab_1/data.h
        lab_1/main.cpp
        lab_1/matrix.cpp
        lab_1/matrix.h)
add_executable(lab_2 lab_2/main.cpp)
add_executable(menu menu/colors.h
        menu/menu.cpp
        menu/menu.h
        menu/main.cpp
        menu/colors.cpp)
