#ifndef MEPHI_DOZEN_3_MANAGER_H
#define MEPHI_DOZEN_3_MANAGER_H
#include "menu.h"
#include "../../hard_class/class.h"

extern Triple_Array* first_array;
extern Triple_Array* second_array;

std::string get_array_status(Triple_Array *array);
Result::Code exit_sequence();
Result::Code first_menu();
Result::Code second_menu();

#endif //MEPHI_DOZEN_3_MANAGER_H
