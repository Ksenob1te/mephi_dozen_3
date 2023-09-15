#include "colors.h"
#include "menu.h"


void Component :: set_label(std::string &str) { this->label = str; }
void Component :: set_enabled(bool status) { this->enabled = status; }

void Label :: render(bool selected) {
    if (selected)
        std::cout << Color::INVERSE << this->label << Color::DEFAULT << std::endl;
    else
        std::cout << this->label << std::endl;
}

void Button :: render(bool selected) {
    if (selected)
        std::cout << Color::INVERSE << this->label << Color::DEFAULT << std::endl;
    else
        std::cout << this->label << std::endl;
}

void Button ::event(char button) {

}





