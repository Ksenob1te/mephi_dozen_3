#ifndef MEPHI_DOZEN_3_SIMPLE_CLASS_H
#define MEPHI_DOZEN_3_SIMPLE_CLASS_H
#include "string"

class Triple_Signal {
private:
    short state;
public:
    explicit Triple_Signal(short state); // explicit to avoid typecasting
    explicit Triple_Signal(char state);
    explicit operator std::string() const;

    ~Triple_Signal() = default;
    void cin();
    void cout() const;


    [[nodiscard]] short get_state() const; // notify that user should not ignore return value
    [[nodiscard]] char get_state_char() const;
    void set_state(short element);
    void set_state(char state);

    Triple_Signal* operator||(const Triple_Signal&) const;
    Triple_Signal* operator&&(const Triple_Signal&) const;
    Triple_Signal* operator!() const;
    Triple_Signal& operator++();
    Triple_Signal operator++(int);
    [[nodiscard]] Triple_Signal* copy() const;
    void operator--();
    bool operator==(const Triple_Signal& a) const;
};

#endif //MEPHI_DOZEN_3_SIMPLE_CLASS_H
