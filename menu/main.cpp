//#include "colors.h"
//#include "iostream"
//#include "menu.h"

//using namespace std;
//int main() {
//    std::string x = "Hello";
//    auto text = new Label();
//    text->set_label(x);
//    x = "Hello2";
//    text->render(true);
//    int wait;
//    cin >> wait;
//    return 0;
//}

#include <cstdlib>
#include <cstdio>
#include "iostream"
#include <unistd.h>
#include <termios.h>

int main(void) {
    char c;
    static struct termios oldtio, newtio;
    tcgetattr(0, &oldtio);
    newtio = oldtio;
    newtio.c_lflag &= ~ICANON;
    newtio.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &newtio);

    printf("Give text:\n");
    fflush(stdout);
    while (1) {
        c = getchar();

        // is this an escape sequence?
        if (c == 27) {
            std::cout << c << " ";
            // "throw away" next two characters which specify escape sequence
            c = getchar();
            std::cout << c << " ";
            c = getchar();
            std::cout << c << std::endl;
            continue;
        }

        // if backspace
        if (c == 0x7f) {
            // go one char left
            printf("\b");
            // overwrite the char with whitespace
            printf(" ");
            // go back to "now removed char position"
            printf("\b");
            continue;
        }

        if (c == 'q') {
            break;
        }
        printf("%c", c);
    }
    printf("\n");
    tcsetattr(0, TCSANOW, &oldtio);

    return 0;
}