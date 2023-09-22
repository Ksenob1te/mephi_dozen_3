#include "class.h"
Triple_Signal::Triple_Signal(short state) {if (state >= 0 && state <= 2) this->state = state;}
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
            return;
    }
}

Triple_Signal& Triple_Signal::operator||(const Triple_Signal &other) const {
    short num_result;
    if (this->state == 1 || other.state == 1)
        num_result = 1;
    else if (this->state == 0 || other.state == 0)
        num_result = 0;
    else
        num_result = 2;

    return *(new Triple_Signal(num_result));
}

Triple_Signal& Triple_Signal::operator&&(const Triple_Signal &other) const {
    short num_result;
    if (this->state == 0 || other.state == 0)
        num_result = 0;
    else if (this->state == 2 || other.state == 2)
        num_result = 2;
    else
        num_result = 1;

    return *(new Triple_Signal(num_result));
}

Triple_Signal& Triple_Signal::operator!() const {
    short num_result;
    if (this->state == 2)
        num_result = 2;
    else
        num_result = (short) !this->state;
    return *(new Triple_Signal(num_result));
}

bool Triple_Signal::operator==(const Triple_Signal &other) const {
    if (this->state == other.state) return true;
    return false;
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

void Triple_Signal::set_state(short element) {if (element >= 0 && element <= 2) this->state = element;}
void Triple_Signal::set_state(char element) {
    switch (element) {
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
            return;
    }
}