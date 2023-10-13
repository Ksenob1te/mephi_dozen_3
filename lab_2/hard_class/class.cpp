#include "class.h"
#include "stdexcept"
#include "climits"

Triple_Signal ** resize(Triple_Signal **array, int old_size, int new_size) {
    auto expanded_array = new Triple_Signal *[new_size];
    for (int i = 0; i < old_size; ++i)
        expanded_array[i] = array[i];
    delete[] array;
    return expanded_array;
}

Triple_Array::Triple_Array(int count) {
    this->array = new Triple_Signal *[count];
    this->element_count = count;
    this->element_limit = count;
    for (int i = 0; i < count; i++) {
        this->array[i] = new Triple_Signal((short) 2);
    }
}

Triple_Array::Triple_Array(const std::string& s) {
    if (s.length() > INT_MAX) throw std::length_error("string length exceeds int value");
    this->array = new Triple_Signal *[s.length()];
    this->element_count = (int) s.length();
    this->element_limit = (int) s.length();
    for (int i = 0; i < s.length(); i++) {
        this->array[i] = new Triple_Signal((char) s[i]);
    }
}

Triple_Array::~Triple_Array() {
    delete[] this->array;
}

Triple_Array* Triple_Array::operator|(const Triple_Array &other) const {
    int new_size = std::max(this->element_count, other.element_count);
    auto result = new Triple_Array(new_size);
    for (int i = 0; i < new_size; i++) {
        if (i < this->element_count && i < other.element_count) {
            result->array[i] = *(this->array[i]) || *(other.array[i]);
        } else if   ((i < this->element_count && this->array[i]->get_state() == 1) ||
                    (i < other.element_count && other.array[i]->get_state() == 1))
            result->array[i]->set_state((short) 1);
    }
    return result;
}

Triple_Array* Triple_Array::operator&(const Triple_Array &other) const {
    int new_size = std::max(this->element_count, other.element_count);
    auto result = new Triple_Array(new_size);
    for (int i = 0; i < new_size; i++) {
        if (i < this->element_count && i < other.element_count) {
            result->array[i] = *(this->array[i]) && *(other.array[i]);
        } else if   ((i < this->element_count && this->array[i]->get_state() == 0) ||
                     (i < other.element_count && other.array[i]->get_state() == 0))
            result->array[i]->set_state((short) 0);
    }
    return result;
}

Triple_Array* Triple_Array::operator~() const {
    int new_size = this->element_count;
    auto result = new Triple_Array(new_size);
    for (int i = 0; i < new_size; i++)
        result->array[i] = !*(this->array[i]);
    return result;
}

bool Triple_Array::operator==(const Triple_Array &other) const {
    if (this->element_count != other.element_count) return false;
    for (int i = 0; i < this->element_count; i++)
        if (this->array[i] != other.array[i]) return false;
    return true;
}

Triple_Signal *Triple_Array::operator[](int index) const {
    if (index < 0 || index >= this->element_count)
        throw std::out_of_range("id is out of elements range");
    return this->array[index];
}

bool Triple_Array::definite() const {
    for (int i = 0; i < this->element_count; i++)
        if (this->array[i]->get_state() == 2) return false;
    return true;
}

void Triple_Array::set_element_by_id(char element, int id) {
    if (this->element_count <= id) throw std::out_of_range("id is out of elements range");
    this->array[id]->set_state(element);
}

void Triple_Array::set_element_by_id(short element, int id) {
    if (this->element_count <= id) throw std::out_of_range("id is out of elements range");
    this->array[id]->set_state(element);
}

void Triple_Array::push_back(char element) {
    if (this->element_count >= this->element_limit) {
        this->array = resize(this->array, this->element_count, this->element_limit * 2 + 1);
        this->element_limit = this->element_limit * 2 + 1;
    }
    this->array[this->element_count] = new Triple_Signal(element);
    this->element_count += 1;
}

void Triple_Array::push_back(short element) {
    if (this->element_count >= this->element_limit) {
        this->array = resize(this->array, this->element_count, this->element_limit * 2 + 1);
        this->element_limit = this->element_limit * 2 + 1;
    }
    this->array[this->element_count] = new Triple_Signal(element);
    this->element_count += 1;
}

Triple_Signal* Triple_Array::pop_back() {
    return this->array[--this->element_count];
}

Triple_Signal** Triple_Array::get_array() {if (this->get_size()) return this->array; else return nullptr;}
int Triple_Array::get_size() const { return this->element_count; }
int Triple_Array::get_limit() const { return this->element_limit; }

