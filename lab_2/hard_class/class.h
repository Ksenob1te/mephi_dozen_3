#ifndef MEPHI_DOZEN_3_HARD_CLASS_H
#define MEPHI_DOZEN_3_HARD_CLASS_H
#include "../simple_class/class.h"
#include "cstdlib"
#include <string>

class Triple_Array {
private:
    Triple_Signal **array;
    int element_count;
    int element_limit;

public:
    explicit Triple_Array(int count);
    explicit Triple_Array(const std::string& s);
    ~Triple_Array();

    void set_element_by_id(char element, int id);
    void set_element_by_id(short element, int id);

    void push_back(char element);
    void push_back(short element);

    Triple_Signal* pop_back();

    Triple_Signal** get_array();
    [[nodiscard]] int get_size() const;
    [[nodiscard]] int get_limit() const;


    Triple_Array* operator|(const Triple_Array&) const;
    Triple_Array* operator&(const Triple_Array&) const;
    Triple_Array* operator~() const;
    Triple_Signal* operator[](int index) const;
    bool operator==(const Triple_Array&) const;
    [[nodiscard]] bool definite() const;
};

#endif //MEPHI_DOZEN_3_HARD_CLASS_H
