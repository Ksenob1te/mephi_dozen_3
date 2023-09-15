#include "input_char.h"

Character::Code get_char(char &c) {
    int element = getch();
    if (!element) return Character::ERROR;
    if (element == 13) {
        return Character::ENTER;
    } else if (element != 224) {
        if (element == '\n') return Character::ENTER;
        if (element == '\b') return Character::BACKSPACE;
        c = (char) element;
        return Character::SYMBOL;
    } else {
        int ex = getch();
        switch (ex) {
            case KEY_UP: return Character::ARROW_UP;
            case KEY_DOWN: return Character::ARROW_DOWN;
            case '\n': return Character::ENTER;
            default: return Character::ERROR;
        }
    }
}