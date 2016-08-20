#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
{
    if((NULL != numeral) && strlen(numeral))
    {
        if(numeral[0] == 'I')
        {
            if(numeral[1] == 'V')
                return nIV;
            if(numeral[1] == 'X')
                return nIX;
            return nI;
        }
        if(numeral[0] == 'V')
            return nV;
        if(numeral[0] == 'X')
        {
            if(numeral[1] == 'L')
                return nXL;
            if(numeral[1] == 'C')
                return nXC;
            return nX;
        }
        if(numeral[0] == 'L')
            return nL;
        if(numeral[0] == 'C')
        {
            if(numeral[1] == 'D')
                return nCD;
            if(numeral[1] == 'M')
                return nCM;
            return nC;
        }
        if(numeral[0] == 'D')
            return nD;
        if(numeral[0] == 'M')
            return nM;
    }
    return INVALID_NUMERAL;
}

unsigned int numeral_to_uint(const char* numeral)
{
    return nINVALID_NUMERAL;
}
