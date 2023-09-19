#include "input_char.h"

Character::Character get_char() {
    int element = _getch();
    if (!element || element == 27) {
        while (kbhit()) _getch();
        return Character::Character {.code = Character::ERROR};
    }
    if (element == 13)
        return Character::Character {.code = Character::ENTER};
    if (element != 224) {
        while (kbhit()) _getch();
        if (element == '\n') return Character::Character {.code = Character::ENTER};
        if (element == '\b') return Character::Character {.code = Character::BACKSPACE};
        return Character::Character {.code = Character::SYMBOL, .data = (char) element};
    } else {
        int ex;
        if (kbhit()) ex = _getch();
        else return Character::Character {.code = Character::BACKSPACE};

        while (kbhit()) _getch();
        switch (ex) {
            case KEY_UP: return Character::Character {.code = Character::ARROW_UP};
            case KEY_DOWN: return Character::Character {.code = Character::ARROW_DOWN};
            case '\n': return Character::Character {.code = Character::ENTER};
            default: return Character::Character {.code = Character::ERROR};
        }
    }
}