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

START_TEST(add_function_will_return_an_empty_string_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    char result[16];

    strcpy(result, "invalid");
    add("", "", result);
    ck_assert_str_eq("", result);

    strcpy(result, "invalid");
    add("I", "", result);
    ck_assert_str_eq("", result);
    
    strcpy(result, "invalid");
    add("", "I", result);
    ck_assert_str_eq("", result);
    
    strcpy(result, "invalid");
    add("b", "I", result);
    ck_assert_str_eq("", result);

    strcpy(result, "invalid");
    add("VX", "I", result);
    ck_assert_str_eq("", result);
    
    strcpy(result, "invalid");
    add("V", "CCCC", result);
    ck_assert_str_eq("", result);
    
    strcpy(result, "invalid");
    add("V", "IM", result);
    ck_assert_str_eq("", result);
    
    strcpy(result, "invalid");
    add("VV", "M", result);
    ck_assert_str_eq("", result);
}
END_TEST

START_TEST(add_function_will_return_the_addition_of_two_roman_numerals)
{
    char result[16];

    strcpy(result, "invalid");
    add("I", "I", result);
    ck_assert_str_eq(result, "II");

    strcpy(result, "invalid");
    add("II", "II", result);
    ck_assert_str_eq(result, "IV");

    strcpy(result, "invalid");
    add("IX", "I", result);
    ck_assert_str_eq(result, "X");

    strcpy(result, "invalid");
    add("V", "V", result);
    ck_assert_str_eq(result, "X");

    strcpy(result, "invalid");
    add("MMMCMXCIX", "II", result);
    ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999)
{
    char result[16] = "invalid";

    add("MMMCMXCIX", "II", result);
    ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(add_function_will_return_an_empty_string_when_result_wrapps_down_to_0)
{
    char result[16] = "invalid";

    add("MMMCMXCIX", "I", result);
    ck_assert_str_eq(result, "");
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
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_any_function_parameter_is_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_a_pointer_to_the_result_variable_when_function_parameters_are_not_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, add_function_will_return_wrapped_around_values_when_result_is_greater_than_3999);
    tcase_add_test(tc_roman_calculator, add_function_will_return_an_empty_string_when_result_wrapps_down_to_0);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_NULL_if_the_first_parameter_is_not_greater_than_second_one);
    tcase_add_test(tc_roman_calculator, subtract_function_will_return_the_subtraction_of_the_second_parameter_from_the_first_one);
    suite_add_tcase(s, tc_roman_calculator);
}
