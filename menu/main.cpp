#include "colors.h"
#include "iostream"
#include "menu.h"
#include "system.h"

int main() {
#if SYSTEM == 0
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    t.c_cc[VMIN] = 1;
    t.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &t);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
#endif

    char c;
    while (1) {
        Character::Code test = get_char(c);
        if (test == Character::SYMBOL)
            std::cout << "'" << c << "'" << std::endl;
        std::cout << test << std::endl;
    }
//    std::string x = "Hello";
//    auto text = new Label();
//    text->set_label(x);
//    x = "Hello2";
//    text->render(true);
//    int wait;
//    cin >> wait;
    return 0;
}
