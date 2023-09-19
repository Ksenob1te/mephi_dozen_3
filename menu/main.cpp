#include "colors.h"
#include "iostream"
#include "menu.h"
#include "system.h"

int main() {
//    std::string final_test;
//    while (1) {
//        Character::Character test = get_char();
//        if (test.code == Character::SYMBOL)
//            std::cout << "'" << test.data << "'" << std::endl;
//        std::cout << test.code << std::endl;
//    }
    Menu *menu = new Menu();
    std::string label = "Hello";
    auto *b1 = new Button(label);

    label = "Hello2";
    auto *b2 = new TextField(label);

    label = "Hello3";
    auto *b3 = new Button(label);

    menu->add_component(b1);
    menu->add_component(b2);
    menu->add_component(b3);

    menu->menu_handler();

//    std::string x = "Hello";
//    auto text = new Label();
//    text->set_label(x);
//    x = "Hello2";
//    text->render(true);
    int wait;
    std::cin >> wait;
    return 0;
}
