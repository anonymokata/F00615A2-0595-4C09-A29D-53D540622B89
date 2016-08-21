#include "conversions.h"

#include <stdlib.h>

const NUMERAL_INFO_TYPE numeral_info[NUMBER_OF_NUMERALS] =
{
    { nINVALID_NUMERAL, 1, ""   },
    { nIV,              2, "IV" },
    { nIX,              2, "IX" },
    { nI,               1, "I"  },
    { nV,               1, "V"  },
    { nXL,              2, "XL" },
    { nXC,              2, "XC" },
    { nX,               1, "X"  },
    { nL,               1, "L"  },
    { nCD,              2, "CD" },
    { nCM,              2, "CM" },
    { nC,               1, "C"  },
    { nD,               1, "D"  },
    { nM,               1, "M"  }
};

NUMERAL_INDEX_TYPE numeral_index(const char* numeral)
{
    NUMERAL_INDEX_TYPE index;

    for(index = IV; index < NUMBER_OF_NUMERALS; index++)
    {
        if(numeral[0] == numeral_info[index].numeral[0])
        {
            if(2 == numeral_info[index].letter_size)
            {
                if(numeral[1] == numeral_info[index].numeral[1])
                {
                    return index;
                }
            }
            else
            {
                return index;
            }
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

unsigned int numeral_to_uint(const char* numeral)
{
    const char* p = numeral;
    unsigned int acc = 0;

    if(NULL != numeral)
    {
        while(strlen(p))
        {
            acc += numeral_value(&p);
        }
    }
    return acc;
}

const char* numeral(unsigned int value)
{
    NUMERAL_INDEX_TYPE index;

    for(index = IV; index < NUMBER_OF_NUMERALS; index++)
    {
        if(value == numeral_info[index].value)
        {
            return numeral_info[index].numeral;
        }
    }
    return numeral_info[INVALID_NUMERAL].numeral;
}
