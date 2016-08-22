#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <stdint.h>
#include <string.h>

typedef enum
{
    INVALID_NUMERAL,
    IV,
    IX,
    I,
    V,
    XL,
    XC,
    X,
    L,
    CD,
    CM,
    C,
    D,
    M,
    NUMBER_OF_NUMERALS
} NUMERAL_INDEX_TYPE;

typedef enum
{
    nINVALID_NUMERAL,
    nI,
    nIV = 4,
    nV = 5,
    nIX = 9,
    nX = 10,
    nXL = 40,
    nL = 50,
    nXC = 90,
    nC = 100,
    nCD = 400,
    nD = 500,
    nCM = 900,
    nM = 1000
} NUMERAL_VALUE_TYPE;

typedef struct
{
    const NUMERAL_VALUE_TYPE value;
    const unsigned char letter_size;
    const char numeral[];
} NUMERAL_INFO_TYPE;

NUMERAL_INDEX_TYPE numeral_index(const char* numeral);
uint16_t numeral_value(const char** numeral);
uint16_t numeral_to_uint(const char* numeral);
char* uint_to_numeral(uint16_t value);

extern const NUMERAL_INFO_TYPE numeral_info[NUMBER_OF_NUMERALS];
const uint8_t numeral_info_ordered_index[NUMBER_OF_NUMERALS];

#endif /* CONVERSIONS_H */
