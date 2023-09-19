#include "colors.h"
#include "menu.h"

void Component :: set_label(std::string &str)   { this->label = str; }
void Component :: set_enabled(bool status)      { this->enabled = status; }
void Component :: on_action(void (*func)())     { this->on_action_callback = func; }

void Label :: render(bool selected) {
    if (selected)
        std::cout << Color::INVERSE << this->label << Color::DEFAULT << std::endl;
    else
        std::cout << Color::FG_YELLOW << this->label << Color::DEFAULT << std::endl;
}

void Button :: render(bool selected) {
    if (selected)
        std::cout << Color::INVERSE << this->label << Color::DEFAULT << std::endl;
    else
        std::cout << this->label << std::endl;
}

void Button :: event(Character::Character button) {
    if (button.code == Character::ENTER) {
        if (this->on_action_callback != nullptr) this->on_action_callback();
    }
}

void TextField :: render(bool selected) {
    if (selected) {
        std::cout << Color::INVERSE << this->label;
        if (this->edit_mode)
            std::cout << ": " << this->data << Color::DEFAULT << std::endl;
        else
            std::cout << Color::DEFAULT << ": " << this->data << std::endl;
    }
    else
        std::cout << this->label << ": " << this->data << std::endl;
}

void TextField :: event(Character::Character button) {
    if (button.code == Character::ENTER) {
        if (!this->edit_mode)
            this->edit_mode = true;
        else {
            if (this->on_action_callback != nullptr) this->on_action_callback();
            this->edit_mode = false;
        }
    }
    if (button.code == Character::SYMBOL)
        this->data.push_back(button.data);
    if (button.code == Character::BACKSPACE)
        if (this->data.length() != 0)
            this->data.pop_back();
}

Component ** resize(Component **array, int old_size, int new_size) {
    auto expanded_array = new Component *[new_size];
    for (int i = 0; i < old_size; ++i)
        expanded_array[i] = array[i];
    delete[] array;
    return expanded_array;
}

Menu * Menu :: add_component(Component *component) {
    if (this->current_size + 1 >= this->max_size) {
        this->components = resize(this->components, this->max_size, this->max_size + 10);
        this->max_size += 10;
    }
    this->components[(this->current_size)++] = component;
    return this;
}

void Menu :: draw() {
    if (SYSTEM == 0) std::system("clear");
    if (SYSTEM == 1) std::system("cls");
    for (int i = 0; i < this->current_size; i++) {
        Component *component = this->components[i];
        component->render(i == this->selected);
    }
}

void Menu :: emit_type_event(Character::Character key) {
    if (key.code == Character::ARROW_UP) {
        int prev_selectable = this->selected;
        for (int i = prev_selectable - 1; i >= 0; i--) {
            if ((this->components)[i]->enabled) {prev_selectable = i; break;}
        }
        if (this->selected != prev_selectable)
            this->selected = prev_selectable;
        else
            return;
    }
    else if (key.code == Character::ARROW_DOWN) {
        int next_selectable = this->selected;
        for (int i = next_selectable + 1; i < this->current_size; i++) {
            if ((this->components)[i]->enabled) {next_selectable = i; break;}
        }
        if (this->selected != next_selectable)
            this->selected = next_selectable;
        else
            return;
    }
    else
        this->components[this->selected]->event(key);
    this->draw();
}

void Menu :: menu_handler() {
    for (int i = 0; i < this->current_size; i++)
        if ((this->components)[i]->enabled) {this->selected = i; break;}
    this->draw();
    while (1) {
        Character::Character c = get_char();
        this->emit_type_event(c);
    }
}

