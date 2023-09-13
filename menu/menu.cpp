#include <iostream>
//#include <conio.h>
#include <string>
#include <cstdlib>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

void print_menu(std::string * &commands, int length, int selected) {
    for (int i = 0; i < length; ++i) {
        if (i == selected) std::cout << "\x1B[33m";
        std::cout << commands[i] << std::endl;
        if (i == selected) std::cout << "\033[0m";
    }
}

int main() {
    int selected = 0;
    int numChoices = 2;
    bool selecting = true;
    bool updated = false;



//    std::cout << "A. Option 1\n";
//    std::cout << "B. Option 2\n";

    auto *commands = new std::string[10];
    commands[0] = "1. hello";
    commands[1] = "2. hello2";
    commands[2] = "3. hello3";
    commands[3] = "4. hello4";
    commands[4] = "5. hello5";

    print_menu(commands, 5, 2);
    int x;
    std::cin >> x;
//    char c;
//    while (selecting) {
//        switch ((c = (char) _getch())) {
//            case KEY_UP:
//                if (selected > 0) {
//                    --selected;
//                    updated = true;
//                }
//                break;
//            case KEY_DOWN:
//                if (selected < numChoices - 1) {
//                    ++selected;
//                    updated = true;
//                }
//                break;
//            case KEY_ENTER:
//                selecting = false;
//                break;
//            default: break;
//        }
//        if (updated) {
//            std::cout << "Option " << (selected + 1) << " is selected.\n";
//            updated = false;
//        }
//    }
//    std::cout << "Selected " << (selected + 1) << '\n';
    return 0;

}