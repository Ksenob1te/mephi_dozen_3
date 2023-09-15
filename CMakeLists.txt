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


set(MENU_SET menu/colors.h
        menu/menu.cpp
        menu/menu.h
        menu/main.cpp
        menu/colors.cpp
        menu/system.h
        menu/character.h
)

if (WIN32)
    add_executable(menu
            ${MENU_SET}
            menu/windows/input_char.cpp
            menu/windows/input_char.h)
endif (WIN32)

if (UNIX)
    add_executable(menu
            ${MENU_SET}
            menu/linux/input_char.cpp
            menu/linux/input_char.h)
endif (UNIX)