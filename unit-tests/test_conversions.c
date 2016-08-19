#include "../src/conversions.h"

#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

START_TEST(prove_check_framework_can_fail)
{
    ck_assert(false);
}
END_TEST

START_TEST(numeral_value_will_return_zero_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_value(NULL), 0);
    ck_assert_int_eq(numeral_value(""), 0);
    ck_assert_int_eq(numeral_value("Z"), 0);
}
END_TEST

START_TEST(numeral_value_will_return_one_when_letter_is_I)
{
    ck_assert_int_eq(numeral_value("I"), 1);
}
END_TEST

START_TEST(numeral_value_will_return_four_when_letter_is_I_followed_by_V)
{
    ck_assert_int_eq(numeral_value("IV"), 4);
}
END_TEST

Suite* roman_calculator_suite()
{
    Suite *s = suite_create("Roman Calculator");

    TCase *tc_conversions = tcase_create("Conversion");
    tcase_add_exit_test(tc_conversions, prove_check_framework_can_fail, EXIT_FAILURE);
    tcase_add_test(tc_conversions, numeral_value_will_return_zero_when_no_condition_is_met);
    tcase_add_test(tc_conversions, numeral_value_will_return_one_when_letter_is_I);
    tcase_add_test(tc_conversions, numeral_value_will_return_four_when_letter_is_I_followed_by_V);
    suite_add_tcase(s, tc_conversions);
    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = roman_calculator_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
