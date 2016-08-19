#include "conversions.h"

#include <stdlib.h>

uint16_t numeral_value(const char* numeral)
{
    if(NULL != numeral)
    {
        if(*numeral == 'I')
            return 1;
    }
    return 0;
}
