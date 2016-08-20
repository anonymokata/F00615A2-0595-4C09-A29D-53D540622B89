#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <stdint.h>
#include <string.h>

typedef enum
{
    INVALID_NUMERAL,
    I,
    IV = 4,
    V = 5,
    IX = 9,
    X = 10,
    XL = 40,
    L = 50,
    XC = 90,
    C = 100,
    CD = 400,
    D = 500,
    CM = 900,
    M = 1000
} NUMERAL_VALUE_TYPE;

typedef enum
{
    cIV = (('I' << 8) | 'V'),
    cIX = (('I' << 8) | 'X'),
    cXL = (('X' << 8) | 'L'),
    cXC = (('X' << 8) | 'C'),
    cCD = (('C' << 8) | 'D'),
    cCM = (('C' << 8) | 'M')
} CHARACTER_PAIR_TYPE;

uint16_t numeral_value(const char* numeral);
unsigned int numeral_to_uint(const char* numeral);

#endif /* CONVERSIONS_H */
