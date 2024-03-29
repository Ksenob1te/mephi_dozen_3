#include "class.h"
#include "iostream"
#include "stdexcept"
#include "limits"

Triple_Signal::Triple_Signal(short state) {if (state >= 0 && state <= 2) this->state = state; else this->state = 2;}
Triple_Signal::Triple_Signal(char state) {
    switch (state) {
        case '0':
            this->state = 0;
            return;
        case '1':
            this->state = 1;
            return;
        case 'X':
            this->state = 2;
            return;
        default:
            this->state = 2;
            return;
    }
}

Triple_Signal* Triple_Signal::operator||(const Triple_Signal &other) const {
    short num_result;
    if (this->state == 1 || other.state == 1)
        num_result = 1;
    else if (this->state == 0 && other.state == 0)
        num_result = 0;
    else
        num_result = 2;

    return new Triple_Signal(num_result);
}

Triple_Signal* Triple_Signal::operator&&(const Triple_Signal &other) const {
    short num_result;
    if (this->state == 0 || other.state == 0)
        num_result = 0;
    else if (this->state == 2 || other.state == 2)
        num_result = 2;
    else
        num_result = 1;

    return new Triple_Signal(num_result);
}

Triple_Signal* Triple_Signal::operator!() const {
    short num_result;
    if (this->state == 2)
        num_result = 2;
    else
        num_result = (short) !this->state;
    return new Triple_Signal(num_result);
}

bool Triple_Signal::operator==(const Triple_Signal &other) const {
    if (this->state == other.state) return true;
    return false;
}

Triple_Signal& Triple_Signal::operator++() {
    if (this->state == 2) return *(this);
    this->state = (short)((this->state + 1) % 2);
    return *this;
}

Triple_Signal Triple_Signal::operator++(int n) {
    Triple_Signal result = *(this);
    if (this->state == 2) return result;
    this->state = (short)((this->state + 1) % 2);
    return result;
}

short Triple_Signal::get_state() const {return this->state;}
char Triple_Signal::get_state_char() const {
    switch (this->state) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return 'X';
        default:
            return '-';
    }
}

void Triple_Signal::set_state(short element) {
    if (element >= 0 && element <= 2)
        this->state = element;
    else this->state = 2;
}

void Triple_Signal::set_state(char element) {
    switch (element) {
        case '0':
            this->state = 0;
            return;
        case '1':
            this->state = 1;
            return;
        default:
            this->state = 2;
            return;
    }
}

void Triple_Signal::cin(std::istream& stream) {
    std::cout << "Type in signal: ";
    char input;
    stream >> input;
    if (stream.eof())
        throw std::runtime_error("Failed to read char: EOF");
    else if (stream.bad())
        throw std::runtime_error("Failed to read char");
    else if (stream.fail())
        throw std::runtime_error("Failed cin stream");
    this->set_state(input);
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Triple_Signal::cout(std::ostream& stream) const {
    stream << "State: ";
    switch (this->state) {
        case 0: stream << 0; break;
        case 1: stream << 1; break;
        case 2: stream << "X"; break;
    }
    stream << std::endl;
}

Triple_Signal::operator std::string() const {
    std::string x = "State: ";
    switch (this->state) {
        case 0:
            x += "0\n";
            break;
        case 1:
            x += "1\n";
            break;
        case 2:
            x += "X\n";
            break;
    }
    return x;
}

Triple_Signal* Triple_Signal::copy() const {
    auto result = new Triple_Signal(this->state);
    return result;
}