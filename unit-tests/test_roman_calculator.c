#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

#include <stdlib.h>

START_TEST(add_function_will_return_an_empty_string_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    char result[16] = "invalid";

    strcpy(result, "invalid");
    ck_assert_str_eq("", add("", "", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("I", "", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("", "I", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("b", "I", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("VX", "I", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("V", "CCCC", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("V", "IM", result));
    strcpy(result, "invalid");
    ck_assert_str_eq("", add("VV", "M", result));
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

    result = add("MMMCMXCIX", "II");
    ck_assert_str_eq(result, "I");
    free(result);
}
END_TEST

START_TEST(add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999)
{
    char* result = add("MMMCMXCIX", "II");

    ck_assert_str_eq(result, "I");
    free(result);
}
END_TEST

START_TEST(add_function_will_return_an_empty_string_when_result_wrapps_down_to_0)
{
    char* result = add("MMMCMXCIX", "I");

    ck_assert_str_eq(result, "");
    free(result);
}
END_TEST

START_TEST(subtract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    ck_assert_ptr_eq(NULL, subtract(NULL, NULL));
    ck_assert_ptr_eq(NULL, subtract("I", NULL));
    ck_assert_ptr_eq(NULL, subtract(NULL, "I"));
    ck_assert_ptr_eq(NULL, subtract("", ""));
    ck_assert_ptr_eq(NULL, subtract("I", ""));
    ck_assert_ptr_eq(NULL, subtract("b", "I"));
    ck_assert_ptr_eq(NULL, subtract("VX", "I"));
    ck_assert_ptr_eq(NULL, subtract("CCCC", "V"));
    ck_assert_ptr_eq(NULL, subtract("IM", "V"));
    ck_assert_ptr_eq(NULL, subtract("M", "VV"));
}
END_TEST

START_TEST(subtract_function_will_return_NULL_if_the_first_parameter_is_not_greater_than_second_one)
{
    ck_assert_ptr_eq(NULL, subtract("I", "II"));
    ck_assert_ptr_eq(NULL, subtract("II", "II"));
}
END_TEST

START_TEST(subtract_function_will_return_the_subtraction_of_the_second_parameter_from_the_first_one)
{
    char* result = subtract("II", "I");

    ck_assert_str_eq(result, "I");
    free(result);

    result = subtract("V", "I");
    ck_assert_str_eq(result, "IV");
    free(result);

    result = subtract("MMMCMXCIX", "I");
    ck_assert_str_eq(result, "MMMCMXCVIII");
    free(result);
}
END_TEST

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999);
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_result_wrapps_down_to_0);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_if_the_first_parameter_is_not_greater_than_second_one);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_the_subtraction_of_the_second_parameter_from_the_first_one);
    suite_add_tcase(s, tc_roman_calculator);
}
