#include "../src/conversions.h"

#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

START_TEST(prove_check_framework_can_fail)
{
    ck_assert(false);
}
END_TEST

START_TEST(test_roman_numeral_index_type)
{
    ck_assert_int_eq(0, INVALID_NUMERAL);
    ck_assert_int_eq(1, IV);
    ck_assert_int_eq(2, IX);
    ck_assert_int_eq(3, I);
    ck_assert_int_eq(4, V);
    ck_assert_int_eq(5, XL);
    ck_assert_int_eq(6, XC);
    ck_assert_int_eq(7, X);
    ck_assert_int_eq(8, L);
    ck_assert_int_eq(9, CD);
    ck_assert_int_eq(10, CM);
    ck_assert_int_eq(11, C);
    ck_assert_int_eq(12, D);
    ck_assert_int_eq(13, M);
}
END_TEST

START_TEST(test_roman_numeral_value_type)
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

START_TEST(test_roman_numeral_info)
{
    ck_assert_int_eq(nINVALID_NUMERAL, numeral_info[INVALID_NUMERAL].value);
    ck_assert_int_eq(1, numeral_info[INVALID_NUMERAL].letter_size);
    ck_assert_str_eq("", numeral_info[INVALID_NUMERAL].numeral);
    ck_assert_int_eq(nI, numeral_info[I].value);
    ck_assert_int_eq(1, numeral_info[I].letter_size);
    ck_assert_str_eq("I", numeral_info[I].numeral);
    ck_assert_int_eq(nIV, numeral_info[IV].value);
    ck_assert_int_eq(2, numeral_info[IV].letter_size);
    ck_assert_str_eq("IV", numeral_info[IV].numeral);
    ck_assert_int_eq(nV, numeral_info[V].value);
    ck_assert_int_eq(1, numeral_info[V].letter_size);
    ck_assert_str_eq("V", numeral_info[V].numeral);
    ck_assert_int_eq(nIX, numeral_info[IX].value);
    ck_assert_int_eq(2, numeral_info[IX].letter_size);
    ck_assert_str_eq("IX", numeral_info[IX].numeral);
    ck_assert_int_eq(nX, numeral_info[X].value);
    ck_assert_int_eq(1, numeral_info[X].letter_size);
    ck_assert_str_eq("X", numeral_info[X].numeral);
    ck_assert_int_eq(nXL, numeral_info[XL].value);
    ck_assert_int_eq(2, numeral_info[XL].letter_size);
    ck_assert_str_eq("XL", numeral_info[XL].numeral);
    ck_assert_int_eq(nL, numeral_info[L].value);
    ck_assert_int_eq(1, numeral_info[L].letter_size);
    ck_assert_str_eq("L", numeral_info[L].numeral);
    ck_assert_int_eq(nXC, numeral_info[XC].value);
    ck_assert_int_eq(2, numeral_info[XC].letter_size);
    ck_assert_str_eq("XC", numeral_info[XC].numeral);
    ck_assert_int_eq(nC, numeral_info[C].value);
    ck_assert_int_eq(1, numeral_info[C].letter_size);
    ck_assert_str_eq("C", numeral_info[C].numeral);
    ck_assert_int_eq(nCD, numeral_info[CD].value);
    ck_assert_int_eq(2, numeral_info[CD].letter_size);
    ck_assert_str_eq("CD", numeral_info[CD].numeral);
    ck_assert_int_eq(nD, numeral_info[D].value);
    ck_assert_int_eq(1, numeral_info[D].letter_size);
    ck_assert_str_eq("D", numeral_info[D].numeral);
    ck_assert_int_eq(nCM, numeral_info[CM].value);
    ck_assert_int_eq(2, numeral_info[CM].letter_size);
    ck_assert_str_eq("CM", numeral_info[CM].numeral);
    ck_assert_int_eq(nM, numeral_info[M].value);
    ck_assert_int_eq(1, numeral_info[M].letter_size);
    ck_assert_str_eq("M", numeral_info[M].numeral);
}
END_TEST

START_TEST(numeral_index_will_return_expected_indexes)
{
    ck_assert_int_eq(numeral_index(""), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_index("Z"), INVALID_NUMERAL);
    ck_assert_int_eq(numeral_index("I"), I);
    ck_assert_int_eq(numeral_index("IV"), IV);
    ck_assert_int_eq(numeral_index("V"), V);
    ck_assert_int_eq(numeral_index("IX"), IX);
    ck_assert_int_eq(numeral_index("X"), X);
    ck_assert_int_eq(numeral_index("XL"), XL);
    ck_assert_int_eq(numeral_index("L"), L);
    ck_assert_int_eq(numeral_index("XC"), XC);
    ck_assert_int_eq(numeral_index("C"), C);
    ck_assert_int_eq(numeral_index("CD"), CD);
    ck_assert_int_eq(numeral_index("D"), D);
    ck_assert_int_eq(numeral_index("CM"), CM);
    ck_assert_int_eq(numeral_index("M"), M);
}
END_TEST

START_TEST(numeral_value_will_return_expected_values)
{
    const char* p;
    NUMERAL_INDEX_TYPE i;
    
    for(i = INVALID_NUMERAL; i < NUMBER_OF_NUMERALS; i++)
    {
        p = numeral_info[i].numeral;
        ck_assert_int_eq(numeral_value(&p), numeral_info[i].value);
    }
}
END_TEST

START_TEST(numeral_value_will_advance_numeral_pointer_to_indicate_next_numeral)
{
    const char one_letter_numeral[] = "I";
    const char two_letters_numeral[] = "IV";
    const char invalid_numeral[] = "Z";
    const char* p = one_letter_numeral;

    numeral_value(&p);
    ck_assert_int_eq(strlen(p), 0);
    p = two_letters_numeral;
    numeral_value(&p);
    ck_assert_int_eq(strlen(p), 0);
    p = invalid_numeral;
    numeral_value(&p);
    ck_assert_int_eq(strlen(p), 0);
}
END_TEST

START_TEST(numeral_to_uint_will_return_zero_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_to_uint(NULL), 0);
    ck_assert_int_eq(numeral_to_uint(""), 0);
    ck_assert_int_eq(numeral_to_uint("Z"), 0);
}
END_TEST

START_TEST(numeral_to_uint_will_return_expected_unsigned_integers)
{
    ck_assert_int_eq(numeral_to_uint("I"), 1);
    ck_assert_int_eq(numeral_to_uint("III"), 3);
    ck_assert_int_eq(numeral_to_uint("VIII"), 8);
    ck_assert_int_eq(numeral_to_uint("DCCCLXXXVIII"), 888);
    ck_assert_int_eq(numeral_to_uint("MMMM"), 4000);
}
END_TEST

START_TEST(numeral_to_uint_will_wrap_around_numerals_bigger_than_65535)
{
    ck_assert_int_eq(numeral_to_uint("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXVII"), 1);
}
END_TEST

START_TEST(numeral_function_will_return_an_empty_string_for_values_that_do_not_have_a_corresponding_numeral)
{
    ck_assert_str_eq(numeral(2), "");
}
END_TEST

START_TEST(numeral_function_will_return_expected_numerals)
{
    ck_assert_str_eq(numeral(nINVALID_NUMERAL), "");
    ck_assert_str_eq(numeral(nIV), "IV");
    ck_assert_str_eq(numeral(nIX), "IX");
    ck_assert_str_eq(numeral(nI), "I");
    ck_assert_str_eq(numeral(nV), "V");
    ck_assert_str_eq(numeral(nXL), "XL");
    ck_assert_str_eq(numeral(nXC), "XC");
    ck_assert_str_eq(numeral(nX), "X");
    ck_assert_str_eq(numeral(nL), "L");
    ck_assert_str_eq(numeral(nCD), "CD");
    ck_assert_str_eq(numeral(nCM), "CM");
    ck_assert_str_eq(numeral(nC), "C");
    ck_assert_str_eq(numeral(nD), "D");
    ck_assert_str_eq(numeral(nM), "M");
}
END_TEST

START_TEST(uint_to_numeral_function_will_return_a_dynamically_allocated_string)
{
    char* numeral = uint_to_numeral(nINVALID_NUMERAL);

    ck_assert_str_eq(numeral, "");
    free(numeral);
}
END_TEST

START_TEST(uint_to_numeral_function_will_return_expected_combined_numerals)
{
    char* numeral;

    numeral = uint_to_numeral(3);
    ck_assert_str_eq(numeral, "III");
    free(numeral);

    numeral = uint_to_numeral(8);
    ck_assert_str_eq(numeral, "VIII");
    free(numeral);
}
END_TEST

START_TEST(uint_to_numeral_function_will_allocated_a_buffer_big_enough_to_handle_maximum_uint16_t_value)
{
    char* numeral;

    numeral = uint_to_numeral(65535);
    ck_assert_str_eq(numeral, "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXV");
    free(numeral);
}
END_TEST

Suite* roman_calculator_suite()
{
    Suite *s = suite_create("Roman Calculator");

    TCase *tc_conversions = tcase_create("Conversion");
    tcase_add_exit_test(tc_conversions, prove_check_framework_can_fail, EXIT_FAILURE);
    tcase_add_test(tc_conversions, test_roman_numeral_index_type);
    tcase_add_test(tc_conversions, test_roman_numeral_value_type);
    tcase_add_test(tc_conversions, test_roman_numeral_info);
    tcase_add_test(tc_conversions, numeral_index_will_return_expected_indexes);
    tcase_add_test(tc_conversions, numeral_value_will_return_expected_values);
    tcase_add_test(tc_conversions, numeral_value_will_advance_numeral_pointer_to_indicate_next_numeral);
    tcase_add_test(tc_conversions, numeral_to_uint_will_return_zero_when_no_condition_is_met);
    tcase_add_test(tc_conversions, numeral_to_uint_will_return_expected_unsigned_integers);
    tcase_add_test(tc_conversions, numeral_to_uint_will_wrap_around_numerals_bigger_than_65535);
    tcase_add_test(tc_conversions, numeral_function_will_return_an_empty_string_for_values_that_do_not_have_a_corresponding_numeral);
    tcase_add_test(tc_conversions, numeral_function_will_return_expected_numerals);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_return_a_dynamically_allocated_string);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_return_expected_combined_numerals);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_allocated_a_buffer_big_enough_to_handle_maximum_uint16_t_value);
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
