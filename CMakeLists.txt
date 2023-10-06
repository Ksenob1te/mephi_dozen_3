cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME mephi_dozen_3)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

include_directories("menu")
add_subdirectory("menu")
add_executable(mephi_dozen_3 main.cpp)
add_executable(lab_1 lab_1/data.cpp lab_1/data.h
        lab_1/main.cpp
        lab_1/matrix.cpp
        lab_1/matrix.h)

add_executable(lab_2 lab_2/main.cpp
        lab_2/simple_class/class.h
        lab_2/simple_class/class.cpp
        lab_2/hard_class/class.cpp
        lab_2/hard_class/class.h
        lab_2/menu/methods.cpp
        lab_2/menu/methods.h
        lab_2/menu/hard_manager/manager.cpp
        lab_2/menu/hard_manager/manager.h
        lab_2/menu/hard_manager/operations.cpp
        lab_2/menu/hard_manager/operations.h)
target_link_libraries(lab_2 menu)


