#include "roman_calculator.h"
#include "conversions.h"

#include <stdlib.h>

char* add(const char* numeral1, const char* numeral2)
{
    char* result = NULL;

    if((NULL != numeral1) || (NULL != numeral2))
    {
        result = uint_to_numeral(numeral_to_uint(numeral1) + numeral_to_uint(numeral2));
    }
    return result;
}

char* substract(const char* numeral1, const char* numeral2)
{
    if((NULL != numeral1) && (NULL == numeral2))
    {
        return strdup(numeral1);
    }
    return NULL;
}
