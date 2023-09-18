#ifndef MEPHI_DOZEN_3_SYSTEM_H
#define MEPHI_DOZEN_3_SYSTEM_H

#if defined(__linux__) // Or #if __linux__
#define SYSTEM 0
#include "linux/input_char.h"
#include <fcntl.h>
#elif _WIN32
#define SYSTEM 1
#include "windows/input_char.h"
#else
#define SYSTEM -1
#endif

#endif //MEPHI_DOZEN_3_SYSTEM_H
