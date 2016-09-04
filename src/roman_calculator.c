#include "roman_calculator.h"
#include "validations.h"
#include "conversions.h"

#include <stdlib.h>

static bool function_paramenters_are_valid(const char* numeral1, const char* numeral2, char result[16])
{
    if(is_valid_roman_numeral(numeral1) && is_valid_roman_numeral(numeral2) && (NULL != result))
    {
        return true;
    }
    return false;
}

char* add(const char* numeral1, const char* numeral2, char result[16])
{
    if(function_paramenters_are_valid(numeral1, numeral2, result))
    {
        return uint_to_numeral(numeral_to_uint(numeral1) + numeral_to_uint(numeral2), result);
    }
    return NULL;
}

char* subtract(const char* numeral1, const char* numeral2, char result[16])
{
    if(function_paramenters_are_valid(numeral1, numeral2, result))
    {
        uint16_t value1 = numeral_to_uint(numeral1);
        uint16_t value2 = numeral_to_uint(numeral2);
        if(value1 > value2)
        {
            return uint_to_numeral(value1 - value2, result);
        }
    }
    return NULL;
}
