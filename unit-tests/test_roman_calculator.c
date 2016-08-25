#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

#include <stdlib.h>

START_TEST(add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    ck_assert_ptr_eq(NULL, add(NULL, NULL));
    ck_assert_ptr_eq(NULL, add("I", NULL));
    ck_assert_ptr_eq(NULL, add(NULL, "I"));
    ck_assert_ptr_eq(NULL, add("", ""));
    ck_assert_ptr_eq(NULL, add("I", ""));
    ck_assert_ptr_eq(NULL, add("b", "I"));
    ck_assert_ptr_eq(NULL, add("VX", "I"));
    ck_assert_ptr_eq(NULL, add("V", "CCCC"));
    ck_assert_ptr_eq(NULL, add("V", "IM"));
    ck_assert_ptr_eq(NULL, add("VV", "M"));
}
END_TEST

START_TEST(add_function_will_return_the_addition_of_two_roman_numerals)
{
    char* result = add("I", "I");

    ck_assert_str_eq(result, "II");
    free(result);

    result = add("II", "II");
    ck_assert_str_eq(result, "IV");
    free(result);

    result = add("IX", "I");
    ck_assert_str_eq(result, "X");
    free(result);

    result = add("V", "V");
    ck_assert_str_eq(result, "X");
    free(result);

    result = add("MMMCMXCIX", "I");
    ck_assert_str_eq(result, "MMMM");
    free(result);
}
END_TEST

START_TEST(add_function_will_return_wrapped_around_values_when_result_is_greater_than_65535)
{
    char* result = add("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", "DXXXVII");

    ck_assert_str_eq(result, "I");
    free(result);
}
END_TEST

START_TEST(add_function_will_return_an_empty_string_when_result_wrapps_down_to_0)
{
    char* result = add("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", "DXXXVI");

    ck_assert_str_eq(result, "");
    free(result);
}
END_TEST

START_TEST(substract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    ck_assert_ptr_eq(NULL, substract(NULL, NULL));
    ck_assert_ptr_eq(NULL, substract("I", NULL));
    ck_assert_ptr_eq(NULL, substract(NULL, "I"));
    ck_assert_ptr_eq(NULL, substract("", ""));
    ck_assert_ptr_eq(NULL, substract("I", ""));
    ck_assert_ptr_eq(NULL, substract("b", "I"));
    ck_assert_ptr_eq(NULL, substract("VX", "I"));
    ck_assert_ptr_eq(NULL, substract("CCCC", "V"));
    ck_assert_ptr_eq(NULL, substract("IM", "V"));
    ck_assert_ptr_eq(NULL, substract("M", "VV"));
}
END_TEST

START_TEST(substract_function_will_return_NULL_if_the_first_parameter_is_not_greater_or_equal_than_second_one)
{
    ck_assert_ptr_eq(NULL, substract("I", "II"));
}
END_TEST

START_TEST(substract_function_will_return_the_substraction_of_the_second_parameter_from_the_first_one)
{
    char* result = substract("II", "I");

    ck_assert_str_eq(result, "I");
    free(result);

    result = substract("V", "I");
    ck_assert_str_eq(result, "IV");
    free(result);

    result = substract("MMMM", "I");
    ck_assert_str_eq(result, "MMMCMXCIX");
    free(result);
}
END_TEST

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Roman Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, add_function_will_return_wrapped_around_values_when_result_is_greater_than_65535);
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_result_wrapps_down_to_0);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_if_the_first_parameter_is_not_greater_or_equal_than_second_one);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_the_substraction_of_the_second_parameter_from_the_first_one);
    suite_add_tcase(s, tc_roman_calculator);
}
