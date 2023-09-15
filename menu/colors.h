#ifndef MEPHI_DOZEN_3_COLORS_H
#define MEPHI_DOZEN_3_COLORS_H
#include "iostream"

namespace Color {
    enum Code {
        DEFAULT     = 0,
        INVERSE     = 7,
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    std::ostream& operator<<(std::ostream& os, Code code);
}

#endif //MEPHI_DOZEN_3_COLORS_H
