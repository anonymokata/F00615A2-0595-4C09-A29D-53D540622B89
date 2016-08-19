#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
{
    if(NULL != numeral)
    {
        if(*numeral == 'I')
        {
            if(numeral[1] == 'V')
                return 4;
            return 1;
        }
        else
        {
            if(*numeral == 'V')
                return 5;
        }
    }
    return 0;
}
