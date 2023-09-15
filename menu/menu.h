#ifndef MEPHI_DOZEN_3_MENU_H
#define MEPHI_DOZEN_3_MENU_H

#include "cstring"
#include "iostream"


#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 


class Component {
protected:
    bool enabled;
    std::string label;

    explicit Component() : enabled(false) {};
    explicit Component(std::string &str) : label(str), enabled(false) {};
    ~Component() = default;

    virtual void event(char button) {};
    virtual void render(bool selected) {};
public:
    void set_label(std::string &str);
    void set_enabled(bool status);
};

class Label : public Component {
private:
    bool enabled = false;
public:
    explicit Label() : Component() {};
    explicit Label(std::string &str) : Component(str) {};
    ~Label() = default;
    void render(bool selected) override;
};

class Button : public Component {
private:
    void (*on_action_callback) ();

public:
    explicit Button() : Component(), on_action_callback(nullptr) {};
    explicit Button(std::string &str) : Component(str), on_action_callback(nullptr) {};
    ~Button() = default;
    void render(bool selected) override;
    void event(char button) override;
    void on_action(void on_action_callback(void));
};


class TextField : public Component {
public:
    std::string data;

    explicit TextField() : Component() {};
    explicit TextField(std::string &str) : Component(str) {};
    ~TextField() = default;
    void render(bool selected) override;
    void event(char button);
};


class Menu {
private:
    Button *components;
    void emit_type_event(char key);
    void draw();

public:
    int selected;
    void menu_handler();
    Menu * add_component(void (*func) (), std::string label);
};

#endif //MEPHI_DOZEN_3_MENU_H
