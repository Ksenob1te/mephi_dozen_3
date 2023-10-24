cmake_minimum_required(VERSION 3.26)

set(MENU_SET colors.h
        menu.cpp
        menu.h
#        menu/main.cpp
        colors.cpp
        system.h
        character.h
)

if (WIN32)
    add_library(menu STATIC
            ${MENU_SET}
            windows/input_char.cpp
            windows/input_char.h)
endif (WIN32)

if (UNIX)
    add_library(menu STATIC
            ${MENU_SET}
            linux/input_char.cpp
            linux/input_char.h)
endif (UNIX)

