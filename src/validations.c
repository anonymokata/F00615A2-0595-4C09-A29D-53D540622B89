#include "validations.h"

#include <string.h>

bool is_valid_repetition(const NUMERAL_INDEX_TYPE index, const char letter, const char next_letter, uint8_t* repetitions)
{
    if(letter == next_letter)
    {
        (*repetitions)++;
        if((*repetitions) > numeral_info[index].allowed_repetitions)
        {
            return false;
        }
    }
    else
    {
        (*repetitions) = 1;
    }
    return true;
}

bool is_valid_numeral_subtraction(const NUMERAL_INDEX_TYPE index, const NUMERAL_INDEX_TYPE next_index)
{
    if(INVALID_NUMERAL != next_index)
    {
        if(numeral_info[index].value < numeral_info[next_index].value)
        {
            if(is_five_numeral_index(index))
            {
                return false;
            }
            else
            {
                if(1 == numeral_info[index].letter_size)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool is_valid_roman_numeral(const char* numeral)
{
    NUMERAL_INDEX_TYPE index;
    uint8_t letter, repetitions;

    if(NULL == numeral)
    {
        return false;
    }
    uint8_t letters = strlen(numeral);
    if(0 == letters)
    {
        return false;
    }
    for(letter = 0, repetitions = 1; letter < letters; letter += numeral_info[index].letter_size)
    {
        index = numeral_index(&numeral[letter]);
        if( (INVALID_NUMERAL == index) ||
            (!is_valid_repetition(index, numeral[letter], numeral[letter + 1], &repetitions)) ||
            (!is_valid_numeral_subtraction(index, numeral_index(&numeral[letter + 1]))))
        {
            return false;
        }
    }
    return true;
}
