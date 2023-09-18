#include "input_char.h"

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(0, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newt);
    oldf = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(0, TCSANOW, &oldt);
    fcntl(0, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

Character::Code get_char(char &c) {
    fflush(stdout);
    c = (char) getchar();
    if (c == 27) {
        if (!kbhit()) return Character::ERROR;

        c = (char) getchar();
        if (c != 91) return Character::ERROR;

        if (!kbhit()) return Character::ERROR;
        c = (char) getchar();
        while (kbhit()) getchar();
        switch (c) {
            case KEY_UP:
                return Character::ARROW_UP;
            case KEY_DOWN:
                return Character::ARROW_DOWN;
            default:
                return Character::ERROR;
        }
    }
    if (c == '\n')
        return Character::ENTER;
    if (c == 0x7f)
        return Character::BACKSPACE;

    return Character::SYMBOL;
}