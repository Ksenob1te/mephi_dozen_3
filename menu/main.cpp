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
    b1->set_enabled(true);

    label = "Hello2";
    auto *b2 = new TextField(label);
    b2->set_enabled(true);

    label = "Hello3";
    auto *b3 = new Button(label);
    b3->set_enabled(true);

    label = "------Menu------";
    auto *b4 = new Label(label);

    label = "----------------";
    auto *l1 = new Label(label);

    menu->add_component(b4);
    menu->add_component(b1);
    menu->add_component(b2);
    menu->add_component(b3);
    menu->add_component(l1);

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
