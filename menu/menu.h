#ifndef MEPHI_DOZEN_3_MENU_H
#define MEPHI_DOZEN_3_MENU_H

#include "system.h"
#include "cstring"
#include "iostream"

namespace Result {
    enum Code {
        EXIT,
        SUCCESS,
        ERROR
    };
}


class Component {
protected:
    Result::Code (*on_action_callback) ();

public:
    bool enabled;
    std::string label;
    explicit Component() : enabled(false), on_action_callback(nullptr) {};
    explicit Component(std::string &str) : label(str), enabled(false), on_action_callback(nullptr) {};
    ~Component() = default;

    virtual std::string get_data() {return "";};
    virtual Result::Code event(Character::Character button) {return Result::ERROR;};
    virtual void render(bool selected) {};
    void set_label(std::string &str);
    void on_action(Result::Code on_action_callback(void));
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
    Result::Code event(Character::Character button) override;
};


class TextField : public Component {
public:
    std::string data;
    bool edit_mode;

    std::string get_data() override {return data;};
    explicit TextField() : Component(), edit_mode(false) {};
    explicit TextField(std::string &str) : Component(str), edit_mode(false) {};
    ~TextField() = default;
    void render(bool selected) override;
    Result::Code event(Character::Character button) override;
};


class Menu {
private:
    Component ** components;
    int current_size, max_size;
    Result::Code emit_type_event(Character::Character key);
    void draw();

public:
    int selected;
    Component* get_component(const std::string& label) const;
    Component* get_component(const int id) const;
    Menu() : current_size(0), max_size(10), components(new Component * [10]()), selected(0) {};
    ~Menu();
    Result::Code menu_handler();
    Menu * add_component(Component *component);
};

#endif //MEPHI_DOZEN_3_MENU_H
