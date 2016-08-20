#include "conversions.h"

#include <stdlib.h>

const NUMERAL_INFO_TYPE numeral_info[NUMBER_OF_NUMERALS] =
{
    { nINVALID_NUMERAL, 0},
    { nI,    1},
    { nIV,   2},
    { nV,    1},
    { nIX,   2},
    { nX,    1},
    { nXL,   2},
    { nL,    1},
    { nXC,   2},
    { nC,    1},
    { nCD,   2},
    { nD,    1},
    { nCM,   2},
    { nM,    1}
};

uint16_t numeral_index(const char* numeral)
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

uint16_t numeral_value(const char* numeral)
{
    return numeral_info[numeral_index(numeral)].value;
}

unsigned int numeral_to_uint(const char* numeral)
{
    return nINVALID_NUMERAL;
}
