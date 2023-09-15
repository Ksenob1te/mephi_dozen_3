#ifndef MEPHI_DOZEN_3_INPUT_CHAR_H
#define MEPHI_DOZEN_3_INPUT_CHAR_H

#include "termios.h"
#include "../character.h"
#include "iostream"
#include "cstdlib"

#define KEY_UP 65
#define KEY_DOWN 66

Character::Code get_char(char &c);
#endif //MEPHI_DOZEN_3_INPUT_CHAR_H
