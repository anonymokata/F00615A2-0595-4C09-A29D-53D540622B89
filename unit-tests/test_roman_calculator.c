#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

#include <stdlib.h>

START_TEST(add_function_will_return_NULL_when_any_function_parameter_is_NULL)
{
    char result[16];

    ck_assert_ptr_eq(add(NULL, NULL, NULL), NULL);
    ck_assert_ptr_eq(add("I", "I", NULL), NULL);
    ck_assert_ptr_eq(add("I", NULL, result), NULL);
    ck_assert_ptr_eq(add(NULL, "I", result), NULL);
}
END_TEST

START_TEST(add_function_will_return_a_pointer_to_the_result_variable_when_function_parameters_are_not_NULL)
{
    char result[16];

    ck_assert_ptr_eq(add("I", "I", result), result);
}
END_TEST

START_TEST(add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    char result[16];

    ck_assert_ptr_eq(add("", "", result), NULL);
    ck_assert_ptr_eq(add("I", "", result), NULL);
    ck_assert_ptr_eq(add("", "I", result), NULL);
    ck_assert_ptr_eq(add("b", "I", result), NULL);
    ck_assert_ptr_eq(add("VX", "I", result), NULL);
    ck_assert_ptr_eq(add("V", "CCCC", result), NULL);
    ck_assert_ptr_eq(add("V", "IM", result), NULL);
    ck_assert_ptr_eq(add("VV", "M", result), NULL);
}
END_TEST

START_TEST(add_function_will_return_the_addition_of_two_roman_numerals)
{
    char result[16];

    ck_assert_str_eq(add("I", "I", result), "II");
    ck_assert_str_eq(add("II", "II", result), "IV");
    ck_assert_str_eq(add("IX", "I", result), "X");
    ck_assert_str_eq(add("V", "V", result), "X");
    ck_assert_str_eq(add("MMMCMXCIX", "II", result), "I");
}
END_TEST

START_TEST(add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999)
{
    char result[16] = "invalid";

    ck_assert_str_eq(add("MMMCMXCIX", "II", result), "I");
}
END_TEST

START_TEST(add_function_will_return_an_empty_string_when_result_wrapps_down_to_0)
{
    char result[16] = "invalid";

    ck_assert_str_eq(add("MMMCMXCIX", "I", result), "");
}
END_TEST

START_TEST(subtract_function_will_return_NULL_when_any_function_parameter_is_NULL)
{
    char result[16];

    ck_assert_ptr_eq(subtract(NULL, NULL, NULL), NULL);
    ck_assert_ptr_eq(subtract("I", "I", NULL), NULL);
    ck_assert_ptr_eq(subtract("I", NULL, result), NULL);
    ck_assert_ptr_eq(subtract(NULL, "I", result), NULL);
}
END_TEST

START_TEST(subtract_function_will_return_a_pointer_to_the_result_variable_when_function_parameters_are_not_NULL)
{
    char result[16];

    ck_assert_ptr_eq(subtract("II", "I", result), result);
}
END_TEST

START_TEST(subtract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    char result[16];

    ck_assert_ptr_eq(subtract("", "", result), NULL);
    ck_assert_ptr_eq(subtract("I", "", result), NULL);
    ck_assert_ptr_eq(subtract("b", "I", result), NULL);
    ck_assert_ptr_eq(subtract("VX", "I", result), NULL);
    ck_assert_ptr_eq(subtract("CCCC", "V", result), NULL);
    ck_assert_ptr_eq(subtract("IM", "V", result), NULL);
    ck_assert_ptr_eq(subtract("M", "VV", result), NULL);
}
END_TEST

START_TEST(subtract_function_will_return_NULL_if_the_first_parameter_is_not_greater_than_second_one)
{
    char result[16];

    ck_assert_ptr_eq(NULL, subtract("I", "II", result));
    ck_assert_ptr_eq(NULL, subtract("II", "II", result));
}
END_TEST

START_TEST(subtract_function_will_return_the_subtraction_of_the_second_parameter_from_the_first_one)
{
    char result[16];

    ck_assert_str_eq(subtract("II", "I", result), "I");
    ck_assert_str_eq(subtract("V", "I", result), "IV");
    ck_assert_str_eq(subtract("MMMCMXCIX", "I", result), "MMMCMXCVIII");
}
END_TEST

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_any_function_parameter_is_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_a_pointer_to_the_result_variable_when_function_parameters_are_not_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999);
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_result_wrapps_down_to_0);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_when_any_function_parameter_is_NULL);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_a_pointer_to_the_result_variable_when_function_parameters_are_not_NULL);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_if_the_first_parameter_is_not_greater_than_second_one);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_the_subtraction_of_the_second_parameter_from_the_first_one);
    suite_add_tcase(s, tc_roman_calculator);
}
