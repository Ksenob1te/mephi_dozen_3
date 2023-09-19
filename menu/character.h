#ifndef MEPHI_DOZEN_3_CHARACTER_H
#define MEPHI_DOZEN_3_CHARACTER_H

namespace Character {
    enum Code {
        ENTER,
        BACKSPACE,
        ARROW_UP,
        ARROW_DOWN,
        SYMBOL,
        ERROR
    };
    typedef struct Character {
        Code code;
        char data;
    } Character;
}

#endif //MEPHI_DOZEN_3_CHARACTER_H
