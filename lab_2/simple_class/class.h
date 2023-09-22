#ifndef MEPHI_DOZEN_3_CLASS_H
#define MEPHI_DOZEN_3_CLASS_H

class Triple_Signal {
private:
    short state;
public:
    explicit Triple_Signal(short state);
    explicit Triple_Signal(char state);
    ~Triple_Signal() = default;

    short get_state() const;
    char get_state_char() const;
    void set_state(short element);
    void set_state(char state);

    Triple_Signal& operator||(const Triple_Signal&) const;
    Triple_Signal& operator&&(const Triple_Signal&) const;
    Triple_Signal& operator!() const;
    bool operator==(const Triple_Signal& a) const;
};

#endif //MEPHI_DOZEN_3_CLASS_H
