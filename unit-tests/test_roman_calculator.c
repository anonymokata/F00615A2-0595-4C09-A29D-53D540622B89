#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

#include <stdlib.h>

START_TEST(add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral)
{
    ck_assert_ptr_eq(NULL, add(NULL, NULL));
    ck_assert_ptr_eq(NULL, add("I", NULL));
    ck_assert_ptr_eq(NULL, add(NULL, "I"));
    ck_assert_ptr_eq(NULL, add("b", "I"));
    ck_assert_ptr_eq(NULL, add("VX", "I"));
    ck_assert_ptr_eq(NULL, add("V", "CCCC"));
    ck_assert_ptr_eq(NULL, add("V", "IM"));
    ck_assert_ptr_eq(NULL, add("VV", "IM"));
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
}
END_TEST

START_TEST(substract_function_will_return_NULL_when_both_function_parameters_are_NULL)
{
    ck_assert_ptr_eq(NULL, substract(NULL, NULL));
}
END_TEST

START_TEST(substract_function_will_return_the_first_parameter_if_the_other_one_is_NULL)
{
    char* result = substract("I", NULL);

    ck_assert_str_eq(result, "I");
    free(result);
}
END_TEST

START_TEST(substract_function_will_return_NULL_if_the_first_parameter_is_NULL)
{
    ck_assert_ptr_eq(NULL, substract(NULL, "I"));
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
}
END_TEST

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Roman Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_a_function_parameter_is_not_a_valid_roman_numeral);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_when_both_function_parameters_are_NULL);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_the_first_parameter_if_the_other_one_is_NULL);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_if_the_first_parameter_is_NULL);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_if_the_first_parameter_is_not_greater_or_equal_than_second_one);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_the_substraction_of_the_second_parameter_from_the_first_one);
    suite_add_tcase(s, tc_roman_calculator);
}
