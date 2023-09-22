#include <menu.h>
#include "simple_class/class.h"

Menu *menu;
Triple_Signal *first;
Triple_Signal *second;


Result::Code check_input_first() {
    Component* result = menu->get_component(1);
    if (result->get_data().length() == 1) {
        char select = (result->get_data())[0];
        first->set_state(select);
        if (first->get_state() != 2)
            ((TextField *) result)->data = first->get_state_char();
        else
            first->set_state('X');
    } else {
        first->set_state('X');
        ((TextField *) result)->data = "X";
    }
    return Result::SUCCESS;
}

Result::Code check_input_second() {
    Component* result = menu->get_component(2);
    if (result->get_data().length() == 1) {
        char select = (result->get_data())[0];
        second->set_state(select);
        if (second->get_state() != 2)
            ((TextField *) result)->data = second->get_state_char();
        else
            second->set_state('X');
    } else {
        second->set_state('X');
        ((TextField *) result)->data = "X";
    }
    return Result::SUCCESS;
}

Result::Code do_or_operation() {
    Component* result = menu->get_component(9);
    if (!result) return Result::ERROR;


    Triple_Signal operation_result = *first || *second;

    std::string label = "Operation result: ";
    label.push_back(operation_result.get_state_char());
    result->set_label(label);

    return Result::SUCCESS;
}

Result::Code do_and_operation() {
    Component* result = menu->get_component(9);
    if (!result) return Result::ERROR;


    Triple_Signal operation_result = *first && *second;

    std::string label = "Operation result: ";
    label.push_back(operation_result.get_state_char());
    result->set_label(label);

    return Result::SUCCESS;
}

Result::Code do_negative_operation() {
    Component* result = menu->get_component(9);
    if (!result) return Result::ERROR;

    Triple_Signal operation_result = !(*first);

    std::string label = "Operation result: ";
    label.push_back(operation_result.get_state_char());
    result->set_label(label);

    return Result::SUCCESS;
}

Result::Code do_equal_operation() {
    Component* result = menu->get_component(9);
    if (!result) return Result::ERROR;

    bool operation_result = (*first == *second);

    std::string label = "Operation result: ";
    if (operation_result)
        label.push_back('1');
    else
        label.push_back('0');

    result->set_label(label);

    return Result::SUCCESS;
}

Result::Code exit_sequence() {
    return Result::EXIT;
}


void create_menu() {
    menu = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "First state";
    auto tf1 = new TextField(label);
    tf1->data = std::to_string(first->get_state());
    tf1->on_action(check_input_first);
    tf1->set_enabled(true);

    label = "Second state";
    auto tf2 = new TextField(label);
    tf2->data = std::to_string(second->get_state());
    tf2->on_action(check_input_second);
    tf2->set_enabled(true);

    label = "[Do || operation]";
    auto b1 = new Button(label);
    b1->on_action(do_or_operation);
    b1->set_enabled(true);

    label = "[Do && operation]";
    auto b2 = new Button(label);
    b2->on_action(do_and_operation);
    b2->set_enabled(true);

    label = "[Do ! operation]";
    auto b3 = new Button(label);
    b3->on_action(do_negative_operation);
    b3->set_enabled(true);

    label = "[Do == operation]";
    auto b4 = new Button(label);
    b4->on_action(do_equal_operation);
    b4->set_enabled(true);

    label = "Operation result: NONE";
    auto l2 = new Label(label);

    label = "[Exit]";
    auto b5 = new Button(label);
    b5->on_action(exit_sequence);
    b5->set_enabled(true);

    menu->add_component(l1);
    menu->add_component(tf1);
    menu->add_component(tf2);
    menu->add_component(l1);
    menu->add_component(b1);
    menu->add_component(b2);
    menu->add_component(b3);
    menu->add_component(b4);
    menu->add_component(l1);
    menu->add_component(l2);
    menu->add_component(b5);
}

int main() {
    first = new Triple_Signal((short) 0);
    second = new Triple_Signal((short) 0);
    create_menu();
    menu->menu_handler();
}