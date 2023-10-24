#include "iostream"
#include "menu.h"

Result::Code exit_sequence() {
    return Result::EXIT;
}

Menu *selector_menu_element;
Menu * selector_menu() {
    Menu *menu = new Menu();
    std::string label = "Field 1";
    auto *b2 = new TextField(label);
    b2->set_enabled(true);

    label = "Field 2";
    auto *b3 = new TextField(label);
    b3->set_enabled(true);

    label = "------Params------";
    auto *l0 = new Label(label);

    label = "------------------";
    auto *l1 = new Label(label);

    label = "Exit";
    auto *b4 = new Button(label);
    b4->set_enabled(true);
    b4->on_action(exit_sequence);

    menu->add_component(l0);
    menu->add_component(b2);
    menu->add_component(b3);
    menu->add_component(l1);
    menu->add_component(b4);
    return menu;
}

Result::Code selector_menu_start() {
    Result::Code result = selector_menu_element->menu_handler();
    return result;
}

Menu * data_menu() {
    Menu *menu = new Menu();
    Menu *result = selector_menu_element;

    std::string label = "------Params------";
    auto *l0 = new Label(label);

    label = "Field 1";
    label = "Field 1: " + result->get_data_textfield(label);
    auto *f1 = new Label(label);
    label = "Field 2";
    label = "Field 2: " + result->get_data_textfield(label);
    auto *f2 = new Label(label);

    label = "------------------";
    auto *l1 = new Label(label);

    label = "Exit";
    auto *b4 = new Button(label);
    b4->set_enabled(true);
    b4->on_action(exit_sequence);

    menu->add_component(l0);
    menu->add_component(f1);
    menu->add_component(f2);
    menu->add_component(l1);
    menu->add_component(b4);
    return menu;
}

Result::Code data_menu_start() {
    Result::Code result = data_menu()->menu_handler();
    return result;
}

Menu * default_menu() {
    Menu *menu = new Menu();
    std::string label = "[Edit params]";
    auto *b1 = new Button(label);
    b1->set_enabled(true);
    selector_menu_element = selector_menu();
    b1->on_action(selector_menu_start);

    label = "Type in";
    auto *b2 = new TextField(label);
    b2->set_enabled(true);

    label = "[Get params]";
    auto *b3 = new Button(label);
    b3->set_enabled(true);
    b3->on_action(data_menu_start);

    label = "------Menu------";
    auto *b4 = new Label(label);

    label = "----------------";
    auto *l1 = new Label(label);

    label = "Exit";
    auto *exit_button = new Button(label);
    exit_button->set_enabled(true);
    exit_button->on_action(exit_sequence);

    menu->add_component(b4);
    menu->add_component(b1);
    menu->add_component(b2);
    menu->add_component(b3);
    menu->add_component(l1);
    menu->add_component(exit_button);

    return menu;
}

int main() {
    Menu *menu = default_menu();
    menu->menu_handler();

    return 0;
}
