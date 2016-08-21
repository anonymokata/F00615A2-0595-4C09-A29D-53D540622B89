#include "test_roman_calculator.h"
#include "../src/roman_calculator.h"

START_TEST(add_function_will_return_NULL_when_function_parameters_are_invalid)
{
    ck_assert_ptr_eq(NULL, add(NULL, "I"));
}
END_TEST

void add_roman_calculator_test_case(Suite *s)
{
    TCase *tc_roman_calculator = tcase_create("Roman Calculator");
    tcase_add_test(tc_roman_calculator, add_function_will_return_NULL_when_function_parameters_are_invalid);
    suite_add_tcase(s, tc_roman_calculator);
}
