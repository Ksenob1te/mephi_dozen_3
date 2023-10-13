#include "methods.h"
#include "hard_manager/manager.h"
#include "hard_manager/operations.h"

Menu* hard_menu;
Triple_Array* first_array;
Triple_Array* second_array;

void create_hard_menu() {
    hard_menu = new Menu();
    first_array = nullptr;
    second_array = nullptr;

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "[First array manager]";
    auto bfa = new Button(label);
    bfa->on_action(first_menu);
    bfa->set_enabled(true);

    label = "[Second array manager]";
    auto bsa = new Button(label);
    bsa->on_action(second_menu);
    bsa->set_enabled(true);

    label = "[Do | operation]";
    auto b1 = new Button(label);
    b1->on_action(do_or_operation);
    b1->set_enabled(true);

    label = "[Do & operation]";
    auto b2 = new Button(label);
    b2->on_action(do_and_operation);
    b2->set_enabled(true);

    label = "[Do ~ operation]";
    auto b3 = new Button(label);
    b3->on_action(do_negative_operation);
    b3->set_enabled(true);

    label = "[Do == operation]";
    auto b4 = new Button(label);
    b4->on_action(do_equal_operation);
    b4->set_enabled(true);

    label = "[Do define operation]";
    auto b5 = new Button(label);
    b5->on_action(do_define_operation);
    b5->set_enabled(true);

    label = "[Exit]";
    auto b6 = new Button(label);
    b6->on_action(exit_sequence);
    b6->set_enabled(true);

    hard_menu->add_component(l1);
    hard_menu->add_component(bfa);
    hard_menu->add_component(bsa);
    hard_menu->add_component(l1);
    hard_menu->add_component(b1);
    hard_menu->add_component(b2);
    hard_menu->add_component(b3);
    hard_menu->add_component(b4);
    hard_menu->add_component(b5);
    hard_menu->add_component(b6);
}

void manage_hard_menu() {
    hard_menu->menu_handler();
    delete hard_menu;
    hard_menu = nullptr;
    delete first_array;
    first_array = nullptr;
    delete second_array;
    second_array = nullptr;
}

