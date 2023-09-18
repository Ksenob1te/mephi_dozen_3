#include "colors.h"
#include "iostream"
#include "menu.h"
#include "system.h"

int main() {
    char c;
    std::string final_test;
    while (c != 'Q') {
        Character::Code test = get_char(c);
        if (test == Character::SYMBOL)
            std::cout << "'" << c << "'" << std::endl;
        std::cout << test << std::endl;
    }
    std::cin >> final_test;
    std::cout << final_test;
//    std::string x = "Hello";
//    auto text = new Label();
//    text->set_label(x);
//    x = "Hello2";
//    text->render(true);
//    int wait;
//    cin >> wait;
    return 0;
}
