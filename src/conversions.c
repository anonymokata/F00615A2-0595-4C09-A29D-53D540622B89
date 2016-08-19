#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
{
    uint16_t* digit = (uint16_t*)numeral;

    if(NULL != numeral)
    {
        if(*digit == ('I' | ('V' << 8)))
            return 4;
        if((*digit & 0xff) == 'I')
            return 1;
        if((*digit & 0xff) == 'V')
            return 5;
    }
    return 0;
}
