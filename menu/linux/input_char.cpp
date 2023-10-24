#include "input_char.h"

int kbhit(void)
{
    int ch;
    int oldf;

    oldf = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    fcntl(0, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

struct termios preset_atributes() {
    struct termios oldt, newt;
    tcgetattr(0, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    newt.c_lflag &= ~ECHO;
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &newt);
    return oldt;
}

Character::Character get_char() {
    struct termios oldt = preset_atributes();
    fflush(stdout);
    int c = getchar();
    if (c == 27) {
        if (!kbhit()) {
            tcsetattr(0, TCSANOW, &oldt);
            return Character::Character {.code = Character::ERROR};
        }

        c = (char) getchar();
        if (c != 91) {
            while (kbhit()) getchar();
            tcsetattr(0, TCSANOW, &oldt);
            return Character::Character {.code = Character::ERROR};
        }

        if (!kbhit()) {
            tcsetattr(0, TCSANOW, &oldt);
            return Character::Character {.code = Character::ERROR};
        }
        c = (char) getchar();
        while (kbhit()) getchar();
        tcsetattr(0, TCSANOW, &oldt);
        switch (c) {
            case KEY_UP:
                return Character::Character {.code = Character::ARROW_UP};
            case KEY_DOWN:
                return Character::Character {.code = Character::ARROW_DOWN};
            default:
                return Character::Character {.code = Character::ERROR};
        }
    }
    tcsetattr(0, TCSANOW, &oldt);
    if (c == '\n')
        return Character::Character {.code = Character::ENTER};
    if (c == 0x7f)
        return Character::Character {.code = Character::BACKSPACE};

    return Character::Character {.code = Character::SYMBOL, .data = (char) c};
}