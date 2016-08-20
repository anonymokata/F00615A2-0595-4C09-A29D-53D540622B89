#include "../src/conversions.h"

#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

START_TEST(prove_check_framework_can_fail)
{
    ck_assert(false);
}
END_TEST

START_TEST(test_ordered_sequence_of_roman_numerals)
{
    ck_assert_int_eq(0, INVALID_NUMERAL);
    ck_assert_int_eq(1, I);
    ck_assert_int_eq(4, IV);
    ck_assert_int_eq(5, V);
    ck_assert_int_eq(9, IX);
    ck_assert_int_eq(10, X);
    ck_assert_int_eq(40, XL);
    ck_assert_int_eq(50, L);
    ck_assert_int_eq(90, XC);
    ck_assert_int_eq(100, C);
    ck_assert_int_eq(400, CD);
    ck_assert_int_eq(500, D);
    ck_assert_int_eq(900, CM);
    ck_assert_int_eq(1000, M);
}
END_TEST

START_TEST(letter_pair_keeps_original_byte_order)
{
    ck_assert_int_eq(letter_pair("01"), 0x3031);
}
END_TEST

START_TEST(numeral_value_will_return_INVALID_NUMERAL_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_value(NULL), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_value(""), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_value("Z"), INVALID_NUMERAL);
}
END_TEST

START_TEST(numeral_value_will_return_one_when_letter_is_I)
{
    ck_assert_int_eq(numeral_value("I"), I);
}
END_TEST

START_TEST(numeral_value_will_return_four_when_letter_is_I_followed_by_V)
{
    ck_assert_int_eq(numeral_value("IV"), IV);
}
END_TEST

START_TEST(numeral_value_will_return_five_when_letter_is_V)
{
    ck_assert_int_eq(numeral_value("V"), V);
}
END_TEST

START_TEST(numeral_value_will_return_nine_when_letter_is_I_followed_by_X)
{
    ck_assert_int_eq(numeral_value("IX"), IX);
}
END_TEST

START_TEST(numeral_value_will_return_ten_when_letter_is_X)
{
    ck_assert_int_eq(numeral_value("X"), X);
}
END_TEST

START_TEST(numeral_value_will_return_forty_when_letter_is_X_followed_by_L)
{
    ck_assert_int_eq(numeral_value("XL"), XL);
}
END_TEST

START_TEST(numeral_value_will_return_fifty_when_letter_is_L)
{
    ck_assert_int_eq(numeral_value("L"), L);
}
END_TEST

START_TEST(numeral_value_will_return_ninety_when_letter_is_X_followed_by_C)
{
    ck_assert_int_eq(numeral_value("XC"), XC);
}
END_TEST

START_TEST(numeral_value_will_return_one_hundred_when_letter_is_C)
{
    ck_assert_int_eq(numeral_value("C"), C);
}
END_TEST

START_TEST(numeral_value_will_return_four_hundred_when_letter_is_C_followed_by_D)
{
    ck_assert_int_eq(numeral_value("CD"), CD);
}
END_TEST

START_TEST(numeral_value_will_return_five_hundred_when_letter_is_D)
{
    ck_assert_int_eq(numeral_value("D"), D);
}
END_TEST

START_TEST(numeral_value_will_return_nine_hundred_when_letter_is_C_followed_by_M)
{
    ck_assert_int_eq(numeral_value("CM"), CM);
}
END_TEST

START_TEST(numeral_value_will_return_one_thousand_when_letter_is_M)
{
    ck_assert_int_eq(numeral_value("M"), M);
}
END_TEST

Suite* roman_calculator_suite()
{
    Suite *s = suite_create("Roman Calculator");

    TCase *tc_conversions = tcase_create("Conversion");
    tcase_add_exit_test(tc_conversions, prove_check_framework_can_fail, EXIT_FAILURE);
    tcase_add_test(tc_conversions, test_ordered_sequence_of_roman_numerals);
    tcase_add_test(tc_conversions, letter_pair_keeps_original_byte_order);
    tcase_add_test(tc_conversions, numeral_value_will_return_INVALID_NUMERAL_when_no_condition_is_met);
    tcase_add_test(tc_conversions, numeral_value_will_return_one_when_letter_is_I);
    tcase_add_test(tc_conversions, numeral_value_will_return_four_when_letter_is_I_followed_by_V);
    tcase_add_test(tc_conversions, numeral_value_will_return_five_when_letter_is_V);
    tcase_add_test(tc_conversions, numeral_value_will_return_nine_when_letter_is_I_followed_by_X);
    tcase_add_test(tc_conversions, numeral_value_will_return_ten_when_letter_is_X);
    tcase_add_test(tc_conversions, numeral_value_will_return_forty_when_letter_is_X_followed_by_L);
    tcase_add_test(tc_conversions, numeral_value_will_return_fifty_when_letter_is_L);
    tcase_add_test(tc_conversions, numeral_value_will_return_ninety_when_letter_is_X_followed_by_C);
    tcase_add_test(tc_conversions, numeral_value_will_return_one_hundred_when_letter_is_C);
    tcase_add_test(tc_conversions, numeral_value_will_return_four_hundred_when_letter_is_C_followed_by_D);
    tcase_add_test(tc_conversions, numeral_value_will_return_five_hundred_when_letter_is_D);
    tcase_add_test(tc_conversions, numeral_value_will_return_nine_hundred_when_letter_is_C_followed_by_M);
    tcase_add_test(tc_conversions, numeral_value_will_return_one_thousand_when_letter_is_M);
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
