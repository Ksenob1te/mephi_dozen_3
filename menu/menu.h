#ifndef MEPHI_DOZEN_3_MENU_H
#define MEPHI_DOZEN_3_MENU_H

#include "system.h"
#include "cstring"
#include "iostream"


class Component {
protected:
    std::string label;
    void (*on_action_callback) ();

public:
    bool enabled;
    explicit Component() : enabled(false), on_action_callback(nullptr) {};
    explicit Component(std::string &str) : label(str), enabled(false), on_action_callback(nullptr) {};
    ~Component() = default;

    virtual void event(Character::Character button) {};
    virtual void render(bool selected) {};
    void set_label(std::string &str);
    void on_action(void on_action_callback(void));
    void set_enabled(bool status);
};

class Label : public Component {
public:
    bool enabled = false;
    explicit Label() : Component() {};
    explicit Label(std::string &str) : Component(str) {};
    ~Label() = default;
    void render(bool selected) override;
};

class Button : public Component {
public:
    explicit Button() : Component() {};
    explicit Button(std::string &str) : Component(str) {};
    ~Button() = default;
    void render(bool selected) override;
    void event(Character::Character button) override;
};


class TextField : public Component {
public:
    std::string data;
    bool edit_mode;

    explicit TextField() : Component(), edit_mode(false) {};
    explicit TextField(std::string &str) : Component(str), edit_mode(false) {};
    ~TextField() = default;
    void render(bool selected) override;
    void event(Character::Character button) override;
};


class Menu {
private:
    Component ** components;
    int current_size, max_size;
    void emit_type_event(Character::Character key);
    void draw();

public:
    int selected;
    Menu() : current_size(0), max_size(10), components(new Component * [10]()), selected(0) {};
    ~Menu();
    void menu_handler();
    Menu * add_component(Component *component);
};

#endif //MEPHI_DOZEN_3_MENU_H
