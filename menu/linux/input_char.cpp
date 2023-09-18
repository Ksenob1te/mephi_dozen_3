#include "input_char.h"

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

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