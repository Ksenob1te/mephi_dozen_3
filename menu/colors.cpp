#include "colors.h"

namespace Color {
    std::ostream& operator<<(std::ostream& os, Color::Code code) {
        return os << "\033[" << static_cast<int>(code) << "m";
    }
}