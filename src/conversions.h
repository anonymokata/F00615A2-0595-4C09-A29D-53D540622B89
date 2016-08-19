#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <stdint.h>

typedef enum
{
    INVALID_NUMERAL,
    I,
    IV = 4,
    V = 5,
    IX = 9,
    X = 10,
    XL = 40,
    VL = 45,
    L = 50,
    XC = 90,
    VC = 95,
    C = 100,
    CD = 400,
    LD = 450,
    VD = 495,
    D = 500,
    CM = 900,
    LM = 950,
    VM = 995,
    M = 1000
} NUMERAL_TYPE;

uint16_t numeral_value(const char* numeral);

#endif /* CONVERSIONS_H */
