#include <unistd.h>

// 2: red
// 1: white
// 0: black

int8_t parseError(int8_t pre, uint8_t &middle, uint8_t irArray) {
    if (middle = 2) return 0;
    switch (irArray)
    {
    case 0b11011:
    case 0b10001:
        return 0;
        // break;
    case 0b11001:
        return 1;
    case 0b10011:
        return -1;
    case 0b11101:
    case 0b11000:
        return 2;
    case 0b10111:
    case 0b00011:
        return -2;
    case 0b11100:
        return 3;
    case 0b00111:
        return -3;
    case 0b11110:
        return 4;
    case 0b01111:
        return -4;
    case 0b11111:
        if (pre>0) return 5;
        else return -5;
    default:
        return pre;
        break;
    }
}