#include "input_char.h"

Character::Code get_char(char &c) {
    int element = _getch();
    if (!element || element == 27) {
        while (kbhit()) _getch();
        return Character::ERROR;
    }
    if (element == 13)
        return Character::ENTER;
    if (element != 224) {
        while (kbhit()) _getch();
        if (element == '\n') return Character::ENTER;
        if (element == '\b') return Character::BACKSPACE;
        c = (char) element;
        return Character::SYMBOL;
    } else {
        int ex;
        if (kbhit()) ex = _getch();
        else return Character::ERROR;

        while (kbhit()) _getch();
        switch (ex) {
            case KEY_UP: return Character::ARROW_UP;
            case KEY_DOWN: return Character::ARROW_DOWN;
            case '\n': return Character::ENTER;
            default: return Character::ERROR;
        }
    }
}