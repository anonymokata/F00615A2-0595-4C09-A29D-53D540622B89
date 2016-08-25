#include "conversions.h"

#include <stdlib.h>

const NUMERAL_INFO_TYPE numeral_info[NUMBER_OF_NUMERALS] =
{
    { nINVALID_NUMERAL, 1,  0,      ""      },
    { nIV,              2,  1,      "IV"    },
    { nIX,              2,  1,      "IX"    },
    { nI,               1,  3,      "I"     },
    { nV,               1,  1,      "V"     },
    { nXL,              2,  1,      "XL"    },
    { nXC,              2,  1,      "XC"    },
    { nX,               1,  3,      "X"     },
    { nL,               1,  1,      "L"     },
    { nCD,              2,  1,      "CD"    },
    { nCM,              2,  1,      "CM"    },
    { nC,               1,  3,      "C"     },
    { nD,               1,  1,      "D"     },
    { nM,               1,  255,    "M"     }
};

const uint8_t numeral_info_ordered_index[NUMBER_OF_NUMERALS] = {0, 3, 1, 4, 2, 7, 5, 8, 6, 11, 9, 12, 10, 13};

NUMERAL_INDEX_TYPE numeral_index(const char* numeral)
{
    NUMERAL_INDEX_TYPE index;

    for(index = IV; index < NUMBER_OF_NUMERALS; index++)
    {
        if(0 == strncmp(numeral, numeral_info[index].numeral, numeral_info[index].letter_size))
        {
            return index;
        }
    }
    return INVALID_NUMERAL;
}

uint16_t numeral_value(const char** numeral)
{
    uint8_t index = numeral_index(*numeral);

    *numeral += numeral_info[index].letter_size;
    return numeral_info[index].value;
}

uint16_t numeral_to_uint(const char* numeral)
{
    const char* p = numeral;
    uint16_t acc = 0;

    if(NULL != numeral)
    {
        while(strlen(p))
        {
            acc += numeral_value(&p);
        }
    }
    return acc;
}

bool is_five_numeral_index(NUMERAL_INDEX_TYPE index)
{
    return ((V == index) || (L == index) || (D == index));
}

char* uint_to_numeral(uint16_t value)
{
    uint8_t i, index;
    char* numeral = malloc(80);
    char* end = numeral;

    numeral[0] = 0;
    for(i = NUMBER_OF_NUMERALS - 1; (0 < value) && (0 < i); i--)
    {
        index = numeral_info_ordered_index[i];
        if(0 != (value / numeral_info[index].value))
        {
            strcpy(end, numeral_info[index].numeral);
            end += numeral_info[index].letter_size;
            *end = 0;
            value -= numeral_info[index].value;
            if(!is_five_numeral_index(index))
            {
                i++;
            }
        }
    }
    return numeral;
}

bool is_valid_roman_numeral(const char* numeral)
{
    uint16_t value;
    const char* p = numeral;
    bool valid = false;
       
    if(NULL != numeral)
    {
        valid = true;
        do
        {
            value = numeral_value(&p);
            if(0 == value)
            {
                valid = false;
                break;
            }
        }
        while(strlen(p));
    }
    return valid;
}
