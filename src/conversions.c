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
        if(letter == 'I')
            return I;
        if(letter == 'V')
            return V;
        if(letter == 'X')
            return X;
    }
    return INVALID_NUMERAL;
}
