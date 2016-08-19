#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

START_TEST(prove_check_framework_can_fail)
{
    ck_assert(false);
}
END_TEST

Suite* roman_calculator_suite()
{
    Suite *s = suite_create("Roman Calculator");

    TCase *tc_conversions = tcase_create("Conversion");
    tcase_add_exit_test(tc_conversions, prove_check_framework_can_fail, EXIT_FAILURE);
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
