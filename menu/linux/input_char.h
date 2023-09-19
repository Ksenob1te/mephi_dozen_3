#ifndef MEPHI_DOZEN_3_INPUT_CHAR_H
#define MEPHI_DOZEN_3_INPUT_CHAR_H

#include "termios.h"
#include "../character.h"
#include "iostream"
#include "cstdlib"
#include <fcntl.h>

#define KEY_UP 65
#define KEY_DOWN 66

Character::Character get_char();
#endif //MEPHI_DOZEN_3_INPUT_CHAR_H
