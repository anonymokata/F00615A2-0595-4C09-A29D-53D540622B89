#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include "conversions.h"

bool is_valid_repetition(const NUMERAL_INDEX_TYPE index, const char letter, const char next_letter, uint8_t* repetitions);
bool is_valid_numeral_subtraction(const NUMERAL_INDEX_TYPE index, const NUMERAL_INDEX_TYPE next_index);
bool is_valid_roman_numeral(const char* numeral);

#endif /* VALIDATIONS_H */
