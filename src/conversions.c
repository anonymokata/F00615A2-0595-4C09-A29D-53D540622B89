#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
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
