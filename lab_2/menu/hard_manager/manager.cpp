#include "manager.h"
#include "regex"

Menu *init_first;
Menu *init_second;

Menu *pb_first;
Menu *pb_second;

Result::Code exit_sequence() {
    return Result::EXIT;
}

std::string get_array_status(Triple_Array *array) {
    std::string result = "-----------------\n";
    Triple_Signal **all_elements = array->get_array();
    for (int i = 0; i < array->get_size(); i++)
        result += (std::string) *(all_elements[i]);
    result += "-----------------";
    return result;
}

Result::Code int_first_field() {
    Component* result = init_first->get_component(1);
    std::string s = result->get_data();
    if (result->get_data().length() <= 5) {
        if (std::regex_match(s, std::regex("[(-|+)|][0-9]+"))) {
            int r = std::stoi(s);
            delete first_array;
            first_array = new Triple_Array(r);
            return Result::EXIT;
        } else
            ((TextField *) result)->data = "0";
    } else
        ((TextField *) result)->data = "0";
    return Result::SUCCESS;
}

Result::Code string_first_field() {
    Component* result = init_first->get_component(1);
    std::string s = result->get_data();
    if (s.length() > 0) {
        delete first_array;
        first_array = new Triple_Array(s);
        return Result::EXIT;
    } else {
        return Result::SUCCESS;
    }
}

TextField* first_menu_field(int type) {
    TextField *tf1;
    if (type) {
        std::string label = "Type in amount of elements";
        tf1 = new TextField(label);
        tf1->set_enabled(true);
        tf1->on_action(int_first_field);
    } else {
        std::string label = "Type in string";
        tf1 = new TextField(label);
        tf1->set_enabled(true);
        tf1->on_action(string_first_field);
    }
    return tf1;
}

void first_init(int type) {
    init_first = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "[Cancel]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(exit_sequence);

    init_first->add_component(l1);
    init_first->add_component(first_menu_field(type));
    init_first->add_component(b1);

    init_first->menu_handler();
    delete init_first;
    init_first = nullptr;
}

Result::Code first_int_menu() {
    first_init(1);
    return Result::SUCCESS;
}

Result::Code first_string_menu() {
    first_init(0);
    return Result::SUCCESS;
}

Result::Code char_input_first() {
    Component* result = pb_first->get_component(1);
    if (result->get_data().length() == 1) {
        char select = (result->get_data())[0];
        if (first_array == nullptr)
            first_array = new Triple_Array(0);
        first_array->push_back(select);
        return Result::EXIT;
    } else
        ((TextField *) result)->data = "";
    return Result::SUCCESS;
}

Result::Code first_push_back() {
    pb_first = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "Type in element [char]";
    auto tf1 = new TextField(label);
    tf1->set_enabled(true);
    tf1->on_action(char_input_first);

    label = "[Cancel]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(exit_sequence);

    pb_first->add_component(l1);
    pb_first->add_component(tf1);
    pb_first->add_component(b1);

    pb_first->menu_handler();
    delete pb_first;
    pb_first = nullptr;
    return Result::SUCCESS;
}

Result::Code first_pop_back() {
    if (first_array == nullptr)
        return Result::ERROR;
    delete first_array->pop_back();
    return Result::SUCCESS;
}

Result::Code first_menu() {
    auto first_hard_menu = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "[Init by counter]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(first_int_menu);

    label = "[Init by string]";
    auto b2 = new Button(label);
    b2->set_enabled(true);
    b2->on_action(first_string_menu);

    label = "[Push back]";
    auto b4 = new Button(label);
    b4->set_enabled(true);
    b4->on_action(first_push_back);

    label = "[Pop back]";
    auto b5 = new Button(label);
    b5->set_enabled(true);
    b5->on_action(first_pop_back);

    label = "[Exit | Refresh]";
    auto b3 = new Button(label);
    b3->set_enabled(true);
    b3->on_action(exit_sequence);

    first_hard_menu->add_component(l1);
    first_hard_menu->add_component(b1);
    first_hard_menu->add_component(b2);
    first_hard_menu->add_component(b4);
    first_hard_menu->add_component(b5);

    if (first_array) {
        label = get_array_status(first_array);
        auto l2 = new Label(label);
        first_hard_menu->add_component(l2);
    }

    first_hard_menu->add_component(b3);

    first_hard_menu->menu_handler();
    return Result::SUCCESS;
}

// ----------------------------------------------------------

Result::Code int_second_field() {
    Component* result = init_second->get_component(1);
    std::string s = result->get_data();
    if (result->get_data().length() <= 5) {
        if (std::regex_match(s, std::regex("[(-|+)|][0-9]+"))) {
            int r = std::stoi(s);
            delete second_array;
            second_array = new Triple_Array(r);
            return Result::EXIT;
        } else
            ((TextField *) result)->data = "0";
    } else
        ((TextField *) result)->data = "0";
    return Result::SUCCESS;
}

Result::Code string_second_field() {
    Component* result = init_second->get_component(1);
    std::string s = result->get_data();
    if (s.length() > 0) {
        delete second_array;
        second_array = new Triple_Array(s);
        return Result::EXIT;
    } else {
        return Result::SUCCESS;
    }
}

TextField* second_menu_field(int type) {
    TextField *tf1;
    if (type) {
        std::string label = "Type in amount of elements";
        tf1 = new TextField(label);
        tf1->set_enabled(true);
        tf1->on_action(int_second_field);
    } else {
        std::string label = "Type in string";
        tf1 = new TextField(label);
        tf1->set_enabled(true);
        tf1->on_action(string_second_field);
    }
    return tf1;
}

void second_init(int type) {
    init_second = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "[Cancel]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(exit_sequence);

    init_second->add_component(l1);
    init_second->add_component(second_menu_field(type));
    init_second->add_component(b1);

    init_second->menu_handler();
    delete init_second;
    init_second = nullptr;
}

Result::Code second_int_menu() {
    second_init(1);
    return Result::SUCCESS;
}

Result::Code second_string_menu() {
    second_init(0);
    return Result::SUCCESS;
}

Result::Code char_input_second() {
    Component* result = pb_second->get_component(1);
    if (result->get_data().length() == 1) {
        char select = (result->get_data())[0];
        if (second_array == nullptr)
            second_array = new Triple_Array(0);
        second_array->push_back(select);
        return Result::EXIT;
    } else
        ((TextField *) result)->data = "";
    return Result::SUCCESS;
}

Result::Code second_push_back() {
    pb_second = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "Type in element [char]";
    auto tf1 = new TextField(label);
    tf1->set_enabled(true);
    tf1->on_action(char_input_second);

    label = "[Cancel]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(exit_sequence);

    pb_second->add_component(l1);
    pb_second->add_component(tf1);
    pb_second->add_component(b1);

    pb_second->menu_handler();
    delete pb_second;
    pb_second = nullptr;
    return Result::SUCCESS;
}

Result::Code second_pop_back() {
    if (second_array == nullptr)
        return Result::ERROR;
    delete second_array->pop_back();
    return Result::SUCCESS;
}

Result::Code second_menu() {
    auto second_hard_menu = new Menu();

    std::string label = "-----------------";
    auto l1 = new Label(label);

    label = "[Init by counter]";
    auto b1 = new Button(label);
    b1->set_enabled(true);
    b1->on_action(second_int_menu);

    label = "[Init by string]";
    auto b2 = new Button(label);
    b2->set_enabled(true);
    b2->on_action(second_string_menu);

    label = "[Push back]";
    auto b4 = new Button(label);
    b4->set_enabled(true);
    b4->on_action(second_push_back);

    label = "[Pop back]";
    auto b5 = new Button(label);
    b5->set_enabled(true);
    b5->on_action(second_pop_back);

    label = "[Exit | Refresh]";
    auto b3 = new Button(label);
    b3->set_enabled(true);
    b3->on_action(exit_sequence);

    second_hard_menu->add_component(l1);
    second_hard_menu->add_component(b1);
    second_hard_menu->add_component(b2);
    second_hard_menu->add_component(b4);
    second_hard_menu->add_component(b5);

    if (second_array) {
        label = get_array_status(second_array);
        auto l2 = new Label(label);
        second_hard_menu->add_component(l2);
    }

    second_hard_menu->add_component(b3);

    second_hard_menu->menu_handler();
    return Result::SUCCESS;
}


