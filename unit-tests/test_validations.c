#include "test_validations.h"
#include "../src/validations.h"

#include <stdlib.h>
#include <check.h>

START_TEST(is_valid_roman_numeral_function_will_return_false_for_unknown_numerals)
{
    ck_assert(!is_valid_roman_numeral(NULL));
    ck_assert(!is_valid_roman_numeral(""));
    ck_assert(!is_valid_roman_numeral("K"));
    ck_assert(!is_valid_roman_numeral("VZ"));
    ck_assert(!is_valid_roman_numeral("i"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_repeated_more_than_three_times)
{
    ck_assert(!is_valid_roman_numeral("IIII"));
    ck_assert(!is_valid_roman_numeral("XXXX"));
    ck_assert(!is_valid_roman_numeral("CCCC"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_V_L_or_D_are_repeated)
{
    ck_assert(!is_valid_roman_numeral("VV"));
    ck_assert(!is_valid_roman_numeral("LL"));
    ck_assert(!is_valid_roman_numeral("DD"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numeral_M_is_repeated_more_than_three_times)
{
    ck_assert(!is_valid_roman_numeral("MMMM"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_true_if_numerals_I_X_or_C_are_repeated_less_than_4_times)
{
    ck_assert(is_valid_roman_numeral("II"));
    ck_assert(is_valid_roman_numeral("III"));
    ck_assert(is_valid_roman_numeral("XXX"));
    ck_assert(is_valid_roman_numeral("CCC"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_V_L_or_D_are_used_for_subtraction)
{
    ck_assert(!is_valid_roman_numeral("VX"));
    ck_assert(!is_valid_roman_numeral("LC"));
    ck_assert(!is_valid_roman_numeral("DM"));

    ck_assert(is_valid_roman_numeral("V"));
    ck_assert(is_valid_roman_numeral("VII"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_subtraction_is_forbidden)
{
    ck_assert(!is_valid_roman_numeral("IL"));
    ck_assert(!is_valid_roman_numeral("IC"));
    ck_assert(!is_valid_roman_numeral("ID"));
    ck_assert(!is_valid_roman_numeral("IM"));
    ck_assert(!is_valid_roman_numeral("XD"));
    ck_assert(!is_valid_roman_numeral("XM"));

    ck_assert(is_valid_roman_numeral("IV"));
    ck_assert(is_valid_roman_numeral("IX"));
    ck_assert(is_valid_roman_numeral("XL"));
    ck_assert(is_valid_roman_numeral("XC"));
    ck_assert(is_valid_roman_numeral("CD"));
    ck_assert(is_valid_roman_numeral("CM"));
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_used_more_than_once_for_subtraction)
{
    ck_assert(!is_valid_roman_numeral("IIV"));
    ck_assert(!is_valid_roman_numeral("IIIX"));
    ck_assert(!is_valid_roman_numeral("XXL"));
    ck_assert(!is_valid_roman_numeral("XXXC"));
    ck_assert(!is_valid_roman_numeral("CCD"));
    ck_assert(!is_valid_roman_numeral("CCCM"));
}
END_TEST

void add_validations_test_case(Suite *s)
{
    TCase *tc_validations = tcase_create("Validations");
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_for_unknown_numerals);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_repeated_more_than_three_times);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numerals_V_L_or_D_are_repeated);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numeral_M_is_repeated_more_than_three_times);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_true_if_numerals_I_X_or_C_are_repeated_less_than_4_times);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numerals_V_L_or_D_are_used_for_subtraction);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_subtraction_is_forbidden);
    tcase_add_test(tc_validations, is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_used_more_than_once_for_subtraction);
    suite_add_tcase(s, tc_validations);
}
