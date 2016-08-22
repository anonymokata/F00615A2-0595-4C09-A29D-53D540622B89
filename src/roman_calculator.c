#include "roman_calculator.h"
#include "conversions.h"

#include <stdlib.h>

char* add(const char* numeral1, const char* numeral2)
{
    if((NULL != numeral1) || (NULL != numeral2))
    {
        return uint_to_numeral(numeral_to_uint(numeral1) + numeral_to_uint(numeral2));
    }
    return NULL;
}

char* substract(const char* numeral1, const char* numeral2)
{
    if(NULL != numeral1)
    {
        if(NULL == numeral2)
        {
            return strdup(numeral1);
        }
        uint16_t value1 = numeral_to_uint(numeral1);
        uint16_t value2 = numeral_to_uint(numeral2);
        if(value1 >= value2)
        {
            return uint_to_numeral(value1 - value2);
        }
    }
    return NULL;
}
