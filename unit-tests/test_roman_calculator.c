#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

#include <stdlib.h>

START_TEST(add_function_will_return_NULL_when_both_function_parameters_are_NULL)
{
    ck_assert_ptr_eq(NULL, add(NULL, NULL));
}
END_TEST

START_TEST(add_function_will_return_the_not_NULL_parameter_when_the_other_one_is_NULL)
{
    char* result = add(NULL, "I");

    ck_assert_str_eq(result, "I");
    free(result);

    result = add("I", NULL);
    ck_assert_str_eq(result, "I");
    free(result);
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

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Roman Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_both_function_parameters_are_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_not_NULL_parameter_when_the_other_one_is_NULL);
    tcase_add_test(tc_roman_calculator, add_function_will_return_the_addition_of_two_roman_numerals);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_NULL_when_both_function_parameters_are_NULL);
    tcase_add_test(tc_roman_calculator, substract_function_will_return_the_first_parameter_if_the_other_one_is_NULL);
    suite_add_tcase(s, tc_roman_calculator);
}
