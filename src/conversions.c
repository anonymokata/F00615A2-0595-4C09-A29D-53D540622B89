#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
{
    if((NULL != numeral) && strlen(numeral))
    {
        char letter = *numeral;
        uint16_t pair = letter_pair(numeral);

        if(pair == cIV)
            return IV;
        if(pair == cIX)
            return IX;
        if(pair == cXL)
            return XL;
        if(pair == cXC)
            return XC;
        if(pair == cCD)
            return CD;
        if(pair == cCM)
            return CM;
        if(letter == 'I')
            return I;
        if(letter == 'V')
            return V;
        if(letter == 'X')
            return X;
        if(letter == 'L')
            return L;
        if(letter == 'C')
            return C;
        if(letter == 'D')
            return D;
        if(letter == 'M')
            return M;
    }
    return INVALID_NUMERAL;
}
