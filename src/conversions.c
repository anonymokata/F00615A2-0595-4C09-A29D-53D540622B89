#include "conversions.h"

#include <stdlib.h>

const NUMERAL_INFO_TYPE numeral_info[NUMBER_OF_NUMERALS] =
{
    { nINVALID_NUMERAL, 1, ""   },
    { nI,               1, "I"  },
    { nIV,              2, "IV" },
    { nV,               1, "V"  },
    { nIX,              2, "IX" },
    { nX,               1, "X"  },
    { nXL,              2, "XL" },
    { nL,               1, "L"  },
    { nXC,              2, "XC" },
    { nC,               1, "C"  },
    { nCD,              2, "CD" },
    { nD,               1, "D"  },
    { nCM,              2, "CM" },
    { nM,               1, "M"  }
};

uint8_t numeral_index(const char* numeral)
{
    if((NULL != numeral) && strlen(numeral))
    {
        if(numeral[0] == 'I')
        {
            if(numeral[1] == 'V')
                return IV;
            if(numeral[1] == 'X')
                return IX;
            return I;
        }
        if(numeral[0] == 'V')
            return V;
        if(numeral[0] == 'X')
        {
            if(numeral[1] == 'L')
                return XL;
            if(numeral[1] == 'C')
                return XC;
            return X;
        }
        if(numeral[0] == 'L')
            return L;
        if(numeral[0] == 'C')
        {
            if(numeral[1] == 'D')
                return CD;
            if(numeral[1] == 'M')
                return CM;
            return C;
        }
        if(numeral[0] == 'D')
            return D;
        if(numeral[0] == 'M')
            return M;
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
