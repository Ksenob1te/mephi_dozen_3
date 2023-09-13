cmake_minimum_required(VERSION 3.26)
project(mephi_dozen_3)

set(CMAKE_CXX_STANDARD 20)

#set(CURSES_NEED_NCURSES TRUE)

add_executable(mephi_dozen_3 main.cpp)
add_executable(lab_1 lab_1/data.cpp lab_1/data.h
        lab_1/main.cpp
        lab_1/matrix.cpp
        lab_1/matrix.h)
add_executable(lab_2 lab_2/main.cpp)
add_executable(menu menu/menu.cpp)

#find_package(Curses REQUIRED)
#if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
#    include_directories(${CURSES_INCLUDE_DIR})
#    target_link_libraries (menu ${CURSES_LIBRARIES})
#endif()

