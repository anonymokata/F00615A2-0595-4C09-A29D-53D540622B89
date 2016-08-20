#include "../src/conversions.h"

#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

START_TEST(prove_check_framework_can_fail)
{
    ck_assert(false);
}
END_TEST

START_TEST(test_roman_numeral_indexes)
{
    ck_assert_int_eq(0, INVALID_NUMERAL);
    ck_assert_int_eq(1, I);
    ck_assert_int_eq(2, IV);
    ck_assert_int_eq(3, V);
    ck_assert_int_eq(4, IX);
    ck_assert_int_eq(5, X);
    ck_assert_int_eq(6, XL);
    ck_assert_int_eq(7, L);
    ck_assert_int_eq(8, XC);
    ck_assert_int_eq(9, C);
    ck_assert_int_eq(10, CD);
    ck_assert_int_eq(11, D);
    ck_assert_int_eq(12, CM);
    ck_assert_int_eq(13, M);
}
END_TEST

START_TEST(test_roman_numeral_values)
{
    ck_assert_int_eq(0, nINVALID_NUMERAL);
    ck_assert_int_eq(1, nI);
    ck_assert_int_eq(4, nIV);
    ck_assert_int_eq(5, nV);
    ck_assert_int_eq(9, nIX);
    ck_assert_int_eq(10, nX);
    ck_assert_int_eq(40, nXL);
    ck_assert_int_eq(50, nL);
    ck_assert_int_eq(90, nXC);
    ck_assert_int_eq(100, nC);
    ck_assert_int_eq(400, nCD);
    ck_assert_int_eq(500, nD);
    ck_assert_int_eq(900, nCM);
    ck_assert_int_eq(1000, nM);
}
END_TEST

START_TEST(numeral_value_will_return_nINVALID_NUMERAL_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_value(NULL), nINVALID_NUMERAL);
    ck_assert_int_eq(numeral_value(""), nINVALID_NUMERAL);
    ck_assert_int_eq(numeral_value("Z"), nINVALID_NUMERAL);
}
END_TEST

START_TEST(numeral_value_will_return_one_when_letter_is_I)
{
    ck_assert_int_eq(numeral_value("I"), nI);
}
END_TEST

START_TEST(numeral_value_will_return_four_when_letter_is_I_followed_by_V)
{
    ck_assert_int_eq(numeral_value("IV"), nIV);
}
END_TEST

START_TEST(numeral_value_will_return_five_when_letter_is_V)
{
    ck_assert_int_eq(numeral_value("V"), nV);
}
END_TEST

START_TEST(numeral_value_will_return_nine_when_letter_is_I_followed_by_X)
{
    ck_assert_int_eq(numeral_value("IX"), nIX);
}
END_TEST

START_TEST(numeral_value_will_return_ten_when_letter_is_X)
{
    ck_assert_int_eq(numeral_value("X"), nX);
}
END_TEST

START_TEST(numeral_value_will_return_forty_when_letter_is_X_followed_by_L)
{
    ck_assert_int_eq(numeral_value("XL"), nXL);
}
END_TEST

START_TEST(numeral_value_will_return_fifty_when_letter_is_L)
{
    ck_assert_int_eq(numeral_value("L"), nL);
}
END_TEST

START_TEST(numeral_value_will_return_ninety_when_letter_is_X_followed_by_C)
{
    ck_assert_int_eq(numeral_value("XC"), nXC);
}
END_TEST

START_TEST(numeral_value_will_return_one_hundred_when_letter_is_C)
{
    ck_assert_int_eq(numeral_value("C"), nC);
}
END_TEST

START_TEST(numeral_value_will_return_four_hundred_when_letter_is_C_followed_by_D)
{
    ck_assert_int_eq(numeral_value("CD"), nCD);
}
END_TEST

START_TEST(numeral_value_will_return_five_hundred_when_letter_is_D)
{
    ck_assert_int_eq(numeral_value("D"), nD);
}
END_TEST

START_TEST(numeral_value_will_return_nine_hundred_when_letter_is_C_followed_by_M)
{
    ck_assert_int_eq(numeral_value("CM"), nCM);
}
END_TEST

START_TEST(numeral_value_will_return_one_thousand_when_letter_is_M)
{
    ck_assert_int_eq(numeral_value("M"), nM);
}
END_TEST

START_TEST(numeral_to_uint_will_return_INVALID_NUMERAL_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_to_uint(NULL), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_to_uint(""), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_to_uint("Z"), INVALID_NUMERAL);
}
END_TEST

Suite* roman_calculator_suite()
{
    Suite *s = suite_create("Roman Calculator");

    TCase *tc_conversions = tcase_create("Conversion");
    tcase_add_exit_test(tc_conversions, prove_check_framework_can_fail, EXIT_FAILURE);
    tcase_add_test(tc_conversions, test_roman_numeral_indexes);
    tcase_add_test(tc_conversions, test_roman_numeral_values);
    tcase_add_test(tc_conversions, numeral_value_will_return_nINVALID_NUMERAL_when_no_condition_is_met);
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
    tcase_add_test(tc_conversions, numeral_to_uint_will_return_INVALID_NUMERAL_when_no_condition_is_met);
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
