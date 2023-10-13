#include "operations.h"

Result::Code do_or_operation() {
    if (first_array == nullptr) return Result::ERROR;
    if (second_array == nullptr) return Result::ERROR;
    Triple_Array* operation_result = *first_array | *second_array;

    Menu *result = new Menu();
    std::string label = get_array_status(operation_result);
    delete operation_result;
    auto *l1 = new Label(label);

    label = "[Exit]";
    auto *b1 = new Button(label);
    b1->on_action(exit_sequence);
    b1->set_enabled(true);

    result->add_component(l1);
    result->add_component(b1);
    result->menu_handler();
    delete result;
    return Result::SUCCESS;
}

Result::Code do_and_operation() {
    if (first_array == nullptr) return Result::ERROR;
    if (second_array == nullptr) return Result::ERROR;
    Triple_Array* operation_result = *first_array & *second_array;

    Menu *result = new Menu();
    std::string label = get_array_status(operation_result);
    delete operation_result;
    auto *l1 = new Label(label);

    label = "[Exit]";
    auto *b1 = new Button(label);
    b1->on_action(exit_sequence);
    b1->set_enabled(true);

    result->add_component(l1);
    result->add_component(b1);
    result->menu_handler();
    delete result;
    return Result::SUCCESS;
}

Result::Code do_negative_operation() {
    if (first_array == nullptr) return Result::ERROR;
    Triple_Array* operation_result = ~(*first_array);

    Menu *result = new Menu();
    std::string label = get_array_status(operation_result);
    delete operation_result;
    auto *l1 = new Label(label);

    label = "[Exit]";
    auto *b1 = new Button(label);
    b1->on_action(exit_sequence);
    b1->set_enabled(true);

    result->add_component(l1);
    result->add_component(b1);
    result->menu_handler();
    delete result;
    return Result::SUCCESS;
}

Result::Code do_equal_operation() {
    if (first_array == nullptr) return Result::ERROR;
    if (second_array == nullptr) return Result::ERROR;
    bool operation_result = *first_array == *second_array;

    Menu *result = new Menu();
    std::string label = operation_result? "True":"False";
    auto *l1 = new Label(label);

    label = "[Exit]";
    auto *b1 = new Button(label);
    b1->on_action(exit_sequence);
    b1->set_enabled(true);

    result->add_component(l1);
    result->add_component(b1);
    result->menu_handler();
    delete result;
    return Result::SUCCESS;
}

Result::Code do_define_operation() {
    if (first_array == nullptr) return Result::ERROR;
    bool operation_result = first_array->definite();

    Menu *result = new Menu();
    std::string label = operation_result? "True":"False";
    auto *l1 = new Label(label);

    label = "[Exit]";
    auto *b1 = new Button(label);
    b1->on_action(exit_sequence);
    b1->set_enabled(true);

    result->add_component(l1);
    result->add_component(b1);
    result->menu_handler();
    delete result;
    return Result::SUCCESS;
}