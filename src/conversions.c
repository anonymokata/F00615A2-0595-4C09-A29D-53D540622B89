#include "conversions.h"

#include <stdlib.h>
#include <string.h>

uint16_t letter_pair(const char* letter)
{
    return ((letter[0] << 8) | letter[1]);
}

uint16_t numeral_value(const char* numeral)
{
    if((NULL != numeral) && strlen(numeral))
    {
        char letter = *numeral;
        uint16_t pair = letter_pair(numeral);

        if(pair == letter_pair("IV"))
            return IV;
        if(pair == letter_pair("IX"))
            return IX;
        if(letter == 'I')
            return I;
        if(letter == 'V')
            return V;
    }
    return INVALID_NUMERAL;
}
