#include "test_roman_calculator.h"
#include "../src/conversions.h"

#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

const char* third_party_numeral[1000] =
{
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C",
    "CI", "CII", "CIII", "CIV", "CV", "CVI", "CVII", "CVIII", "CIX", "CX",
    "CXI", "CXII", "CXIII", "CXIV", "CXV", "CXVI", "CXVII", "CXVIII", "CXIX", "CXX",
    "CXXI", "CXXII", "CXXIII", "CXXIV", "CXXV", "CXXVI", "CXXVII", "CXXVIII", "CXXIX", "CXXX",
    "CXXXI", "CXXXII", "CXXXIII", "CXXXIV", "CXXXV", "CXXXVI", "CXXXVII", "CXXXVIII", "CXXXIX", "CXL",
    "CXLI", "CXLII", "CXLIII", "CXLIV", "CXLV", "CXLVI", "CXLVII", "CXLVIII", "CXLIX", "CL",
    "CLI", "CLII", "CLIII", "CLIV", "CLV", "CLVI", "CLVII", "CLVIII", "CLIX", "CLX",
    "CLXI", "CLXII", "CLXIII", "CLXIV", "CLXV", "CLXVI", "CLXVII", "CLXVIII", "CLXIX", "CLXX",
    "CLXXI", "CLXXII", "CLXXIII", "CLXXIV", "CLXXV", "CLXXVI", "CLXXVII", "CLXXVIII", "CLXXIX", "CLXXX",
    "CLXXXI", "CLXXXII", "CLXXXIII", "CLXXXIV", "CLXXXV", "CLXXXVI", "CLXXXVII", "CLXXXVIII", "CLXXXIX", "CXC",
    "CXCI", "CXCII", "CXCIII", "CXCIV", "CXCV", "CXCVI", "CXCVII", "CXCVIII", "CXCIX", "CC",
    "CCI", "CCII", "CCIII", "CCIV", "CCV", "CCVI", "CCVII", "CCVIII", "CCIX", "CCX",
    "CCXI", "CCXII", "CCXIII", "CCXIV", "CCXV", "CCXVI", "CCXVII", "CCXVIII", "CCXIX", "CCXX",
    "CCXXI", "CCXXII", "CCXXIII", "CCXXIV", "CCXXV", "CCXXVI", "CCXXVII", "CCXXVIII", "CCXXIX", "CCXXX",
    "CCXXXI", "CCXXXII", "CCXXXIII", "CCXXXIV", "CCXXXV", "CCXXXVI", "CCXXXVII", "CCXXXVIII", "CCXXXIX", "CCXL",
    "CCXLI", "CCXLII", "CCXLIII", "CCXLIV", "CCXLV", "CCXLVI", "CCXLVII", "CCXLVIII", "CCXLIX", "CCL",
    "CCLI", "CCLII", "CCLIII", "CCLIV", "CCLV", "CCLVI", "CCLVII", "CCLVIII", "CCLIX", "CCLX",
    "CCLXI", "CCLXII", "CCLXIII", "CCLXIV", "CCLXV", "CCLXVI", "CCLXVII", "CCLXVIII", "CCLXIX", "CCLXX",
    "CCLXXI", "CCLXXII", "CCLXXIII", "CCLXXIV", "CCLXXV", "CCLXXVI", "CCLXXVII", "CCLXXVIII", "CCLXXIX", "CCLXXX",
    "CCLXXXI", "CCLXXXII", "CCLXXXIII", "CCLXXXIV", "CCLXXXV", "CCLXXXVI", "CCLXXXVII", "CCLXXXVIII", "CCLXXXIX", "CCXC",
    "CCXCI", "CCXCII", "CCXCIII", "CCXCIV", "CCXCV", "CCXCVI", "CCXCVII", "CCXCVIII", "CCXCIX", "CCC",
    "CCCI", "CCCII", "CCCIII", "CCCIV", "CCCV", "CCCVI", "CCCVII", "CCCVIII", "CCCIX", "CCCX",
    "CCCXI", "CCCXII", "CCCXIII", "CCCXIV", "CCCXV", "CCCXVI", "CCCXVII", "CCCXVIII", "CCCXIX", "CCCXX",
    "CCCXXI", "CCCXXII", "CCCXXIII", "CCCXXIV", "CCCXXV", "CCCXXVI", "CCCXXVII", "CCCXXVIII", "CCCXXIX", "CCCXXX",
    "CCCXXXI", "CCCXXXII", "CCCXXXIII", "CCCXXXIV", "CCCXXXV", "CCCXXXVI", "CCCXXXVII", "CCCXXXVIII", "CCCXXXIX", "CCCXL",
    "CCCXLI", "CCCXLII", "CCCXLIII", "CCCXLIV", "CCCXLV", "CCCXLVI", "CCCXLVII", "CCCXLVIII", "CCCXLIX", "CCCL",
    "CCCLI", "CCCLII", "CCCLIII", "CCCLIV", "CCCLV", "CCCLVI", "CCCLVII", "CCCLVIII", "CCCLIX", "CCCLX",
    "CCCLXI", "CCCLXII", "CCCLXIII", "CCCLXIV", "CCCLXV", "CCCLXVI", "CCCLXVII", "CCCLXVIII", "CCCLXIX", "CCCLXX",
    "CCCLXXI", "CCCLXXII", "CCCLXXIII", "CCCLXXIV", "CCCLXXV", "CCCLXXVI", "CCCLXXVII", "CCCLXXVIII", "CCCLXXIX", "CCCLXXX",
    "CCCLXXXI", "CCCLXXXII", "CCCLXXXIII", "CCCLXXXIV", "CCCLXXXV", "CCCLXXXVI", "CCCLXXXVII", "CCCLXXXVIII", "CCCLXXXIX", "CCCXC",
    "CCCXCI", "CCCXCII", "CCCXCIII", "CCCXCIV", "CCCXCV", "CCCXCVI", "CCCXCVII", "CCCXCVIII", "CCCXCIX", "CD",
    "CDI", "CDII", "CDIII", "CDIV", "CDV", "CDVI", "CDVII", "CDVIII", "CDIX", "CDX",
    "CDXI", "CDXII", "CDXIII", "CDXIV", "CDXV", "CDXVI", "CDXVII", "CDXVIII", "CDXIX", "CDXX",
    "CDXXI", "CDXXII", "CDXXIII", "CDXXIV", "CDXXV", "CDXXVI", "CDXXVII", "CDXXVIII", "CDXXIX", "CDXXX",
    "CDXXXI", "CDXXXII", "CDXXXIII", "CDXXXIV", "CDXXXV", "CDXXXVI", "CDXXXVII", "CDXXXVIII", "CDXXXIX", "CDXL",
    "CDXLI", "CDXLII", "CDXLIII", "CDXLIV", "CDXLV", "CDXLVI", "CDXLVII", "CDXLVIII", "CDXLIX", "CDL",
    "CDLI", "CDLII", "CDLIII", "CDLIV", "CDLV", "CDLVI", "CDLVII", "CDLVIII", "CDLIX", "CDLX",
    "CDLXI", "CDLXII", "CDLXIII", "CDLXIV", "CDLXV", "CDLXVI", "CDLXVII", "CDLXVIII", "CDLXIX", "CDLXX",
    "CDLXXI", "CDLXXII", "CDLXXIII", "CDLXXIV", "CDLXXV", "CDLXXVI", "CDLXXVII", "CDLXXVIII", "CDLXXIX", "CDLXXX",
    "CDLXXXI", "CDLXXXII", "CDLXXXIII", "CDLXXXIV", "CDLXXXV", "CDLXXXVI", "CDLXXXVII", "CDLXXXVIII", "CDLXXXIX", "CDXC",
    "CDXCI", "CDXCII", "CDXCIII", "CDXCIV", "CDXCV", "CDXCVI", "CDXCVII", "CDXCVIII", "CDXCIX", "D",
    "DI", "DII", "DIII", "DIV", "DV", "DVI", "DVII", "DVIII",
    "DIX", "DX", "DXI", "DXII", "DXIII", "DXIV", "DXV", "DXVI", "DXVII", "DXVIII", "DXIX", "DXX",
    "DXXI", "DXXII", "DXXIII", "DXXIV", "DXXV", "DXXVI", "DXXVII", "DXXVIII", "DXXIX", "DXXX",
    "DXXXI", "DXXXII", "DXXXIII", "DXXXIV", "DXXXV", "DXXXVI", "DXXXVII", "DXXXVIII", "DXXXIX", "DXL",
    "DXLI", "DXLII", "DXLIII", "DXLIV", "DXLV", "DXLVI", "DXLVII", "DXLVIII", "DXLIX", "DL",
    "DLI", "DLII", "DLIII", "DLIV", "DLV", "DLVI", "DLVII", "DLVIII", "DLIX", "DLX",
    "DLXI", "DLXII", "DLXIII", "DLXIV", "DLXV", "DLXVI", "DLXVII", "DLXVIII", "DLXIX", "DLXX",
    "DLXXI", "DLXXII", "DLXXIII", "DLXXIV", "DLXXV", "DLXXVI", "DLXXVII", "DLXXVIII", "DLXXIX", "DLXXX",
    "DLXXXI", "DLXXXII", "DLXXXIII", "DLXXXIV", "DLXXXV", "DLXXXVI", "DLXXXVII", "DLXXXVIII", "DLXXXIX", "DXC",
    "DXCI", "DXCII", "DXCIII", "DXCIV", "DXCV", "DXCVI", "DXCVII", "DXCVIII", "DXCIX", "DC",
    "DCI", "DCII", "DCIII", "DCIV", "DCV", "DCVI", "DCVII", "DCVIII", "DCIX", "DCX",
    "DCXI", "DCXII", "DCXIII", "DCXIV", "DCXV", "DCXVI", "DCXVII", "DCXVIII", "DCXIX", "DCXX",
    "DCXXI", "DCXXII", "DCXXIII", "DCXXIV", "DCXXV", "DCXXVI", "DCXXVII", "DCXXVIII", "DCXXIX", "DCXXX",
    "DCXXXI", "DCXXXII", "DCXXXIII", "DCXXXIV", "DCXXXV", "DCXXXVI", "DCXXXVII", "DCXXXVIII", "DCXXXIX", "DCXL",
    "DCXLI", "DCXLII", "DCXLIII", "DCXLIV", "DCXLV", "DCXLVI", "DCXLVII", "DCXLVIII", "DCXLIX", "DCL",
    "DCLI", "DCLII", "DCLIII", "DCLIV", "DCLV", "DCLVI", "DCLVII", "DCLVIII", "DCLIX", "DCLX",
    "DCLXI", "DCLXII", "DCLXIII", "DCLXIV", "DCLXV", "DCLXVI", "DCLXVII", "DCLXVIII", "DCLXIX", "DCLXX",
    "DCLXXI", "DCLXXII", "DCLXXIII", "DCLXXIV", "DCLXXV", "DCLXXVI", "DCLXXVII", "DCLXXVIII", "DCLXXIX", "DCLXXX",
    "DCLXXXI", "DCLXXXII", "DCLXXXIII", "DCLXXXIV", "DCLXXXV", "DCLXXXVI", "DCLXXXVII", "DCLXXXVIII", "DCLXXXIX", "DCXC",
    "DCXCI", "DCXCII", "DCXCIII", "DCXCIV", "DCXCV", "DCXCVI", "DCXCVII", "DCXCVIII", "DCXCIX", "DCC",
    "DCCI", "DCCII", "DCCIII", "DCCIV", "DCCV", "DCCVI", "DCCVII", "DCCVIII", "DCCIX", "DCCX",
    "DCCXI", "DCCXII", "DCCXIII", "DCCXIV", "DCCXV", "DCCXVI", "DCCXVII", "DCCXVIII", "DCCXIX", "DCCXX",
    "DCCXXI", "DCCXXII", "DCCXXIII", "DCCXXIV", "DCCXXV", "DCCXXVI", "DCCXXVII", "DCCXXVIII", "DCCXXIX", "DCCXXX",
    "DCCXXXI", "DCCXXXII", "DCCXXXIII", "DCCXXXIV", "DCCXXXV", "DCCXXXVI", "DCCXXXVII", "DCCXXXVIII", "DCCXXXIX", "DCCXL",
    "DCCXLI", "DCCXLII", "DCCXLIII", "DCCXLIV", "DCCXLV", "DCCXLVI", "DCCXLVII", "DCCXLVIII", "DCCXLIX", "DCCL",
    "DCCLI", "DCCLII", "DCCLIII", "DCCLIV", "DCCLV", "DCCLVI", "DCCLVII", "DCCLVIII", "DCCLIX", "DCCLX",
    "DCCLXI", "DCCLXII", "DCCLXIII", "DCCLXIV", "DCCLXV", "DCCLXVI", "DCCLXVII", "DCCLXVIII", "DCCLXIX", "DCCLXX",
    "DCCLXXI", "DCCLXXII", "DCCLXXIII", "DCCLXXIV", "DCCLXXV", "DCCLXXVI", "DCCLXXVII", "DCCLXXVIII", "DCCLXXIX", "DCCLXXX",
    "DCCLXXXI", "DCCLXXXII", "DCCLXXXIII", "DCCLXXXIV", "DCCLXXXV", "DCCLXXXVI", "DCCLXXXVII", "DCCLXXXVIII", "DCCLXXXIX", "DCCXC",
    "DCCXCI", "DCCXCII", "DCCXCIII", "DCCXCIV", "DCCXCV", "DCCXCVI", "DCCXCVII", "DCCXCVIII", "DCCXCIX", "DCCC",
    "DCCCI", "DCCCII", "DCCCIII", "DCCCIV", "DCCCV", "DCCCVI", "DCCCVII", "DCCCVIII", "DCCCIX", "DCCCX",
    "DCCCXI", "DCCCXII", "DCCCXIII", "DCCCXIV", "DCCCXV", "DCCCXVI", "DCCCXVII", "DCCCXVIII", "DCCCXIX", "DCCCXX",
    "DCCCXXI", "DCCCXXII", "DCCCXXIII", "DCCCXXIV", "DCCCXXV", "DCCCXXVI", "DCCCXXVII", "DCCCXXVIII", "DCCCXXIX", "DCCCXXX",
    "DCCCXXXI", "DCCCXXXII", "DCCCXXXIII", "DCCCXXXIV", "DCCCXXXV", "DCCCXXXVI", "DCCCXXXVII", "DCCCXXXVIII", "DCCCXXXIX", "DCCCXL",
    "DCCCXLI", "DCCCXLII", "DCCCXLIII", "DCCCXLIV", "DCCCXLV", "DCCCXLVI", "DCCCXLVII", "DCCCXLVIII", "DCCCXLIX", "DCCCL",
    "DCCCLI", "DCCCLII", "DCCCLIII", "DCCCLIV", "DCCCLV", "DCCCLVI", "DCCCLVII", "DCCCLVIII", "DCCCLIX", "DCCCLX",
    "DCCCLXI", "DCCCLXII", "DCCCLXIII", "DCCCLXIV", "DCCCLXV", "DCCCLXVI", "DCCCLXVII", "DCCCLXVIII", "DCCCLXIX", "DCCCLXX",
    "DCCCLXXI", "DCCCLXXII", "DCCCLXXIII", "DCCCLXXIV", "DCCCLXXV", "DCCCLXXVI", "DCCCLXXVII", "DCCCLXXVIII", "DCCCLXXIX", "DCCCLXXX",
    "DCCCLXXXI", "DCCCLXXXII", "DCCCLXXXIII", "DCCCLXXXIV", "DCCCLXXXV", "DCCCLXXXVI", "DCCCLXXXVII", "DCCCLXXXVIII", "DCCCLXXXIX", "DCCCXC",
    "DCCCXCI", "DCCCXCII", "DCCCXCIII", "DCCCXCIV", "DCCCXCV", "DCCCXCVI", "DCCCXCVII", "DCCCXCVIII", "DCCCXCIX", "CM",
    "CMI", "CMII", "CMIII", "CMIV", "CMV", "CMVI", "CMVII", "CMVIII", "CMIX", "CMX",
    "CMXI", "CMXII", "CMXIII", "CMXIV", "CMXV", "CMXVI", "CMXVII", "CMXVIII", "CMXIX", "CMXX",
    "CMXXI", "CMXXII", "CMXXIII", "CMXXIV", "CMXXV", "CMXXVI", "CMXXVII", "CMXXVIII", "CMXXIX", "CMXXX",
    "CMXXXI", "CMXXXII", "CMXXXIII", "CMXXXIV", "CMXXXV", "CMXXXVI", "CMXXXVII", "CMXXXVIII", "CMXXXIX", "CMXL",
    "CMXLI", "CMXLII", "CMXLIII", "CMXLIV", "CMXLV", "CMXLVI", "CMXLVII", "CMXLVIII", "CMXLIX", "CML",
    "CMLI", "CMLII", "CMLIII", "CMLIV", "CMLV", "CMLVI", "CMLVII", "CMLVIII", "CMLIX", "CMLX",
    "CMLXI", "CMLXII", "CMLXIII", "CMLXIV", "CMLXV", "CMLXVI", "CMLXVII", "CMLXVIII", "CMLXIX", "CMLXX",
    "CMLXXI", "CMLXXII", "CMLXXIII", "CMLXXIV", "CMLXXV", "CMLXXVI", "CMLXXVII", "CMLXXVIII", "CMLXXIX", "CMLXXX",
    "CMLXXXI", "CMLXXXII", "CMLXXXIII", "CMLXXXIV", "CMLXXXV", "CMLXXXVI", "CMLXXXVII", "CMLXXXVIII", "CMLXXXIX", "CMXC",
    "CMXCI", "CMXCII", "CMXCIII", "CMXCIV", "CMXCV", "CMXCVI", "CMXCVII", "CMXCVIII", "CMXCIX", "M"
};

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
    ck_assert_int_eq(0, numeral_info[INVALID_NUMERAL].allowed_repetitions);
    ck_assert_str_eq("", numeral_info[INVALID_NUMERAL].numeral);

    ck_assert_int_eq(nI, numeral_info[I].value);
    ck_assert_int_eq(1, numeral_info[I].letter_size);
    ck_assert_int_eq(3, numeral_info[I].allowed_repetitions);
    ck_assert_str_eq("I", numeral_info[I].numeral);

    ck_assert_int_eq(nIV, numeral_info[IV].value);
    ck_assert_int_eq(2, numeral_info[IV].letter_size);
    ck_assert_int_eq(1, numeral_info[IV].allowed_repetitions);
    ck_assert_str_eq("IV", numeral_info[IV].numeral);

    ck_assert_int_eq(nV, numeral_info[V].value);
    ck_assert_int_eq(1, numeral_info[V].letter_size);
    ck_assert_int_eq(1, numeral_info[V].allowed_repetitions);
    ck_assert_str_eq("V", numeral_info[V].numeral);

    ck_assert_int_eq(nIX, numeral_info[IX].value);
    ck_assert_int_eq(2, numeral_info[IX].letter_size);
    ck_assert_int_eq(1, numeral_info[IX].allowed_repetitions);
    ck_assert_str_eq("IX", numeral_info[IX].numeral);
    
    ck_assert_int_eq(nX, numeral_info[X].value);
    ck_assert_int_eq(1, numeral_info[X].letter_size);
    ck_assert_int_eq(3, numeral_info[X].allowed_repetitions);
    ck_assert_str_eq("X", numeral_info[X].numeral);
    
    ck_assert_int_eq(nXL, numeral_info[XL].value);
    ck_assert_int_eq(2, numeral_info[XL].letter_size);
    ck_assert_int_eq(1, numeral_info[XL].allowed_repetitions);
    ck_assert_str_eq("XL", numeral_info[XL].numeral);
    
    ck_assert_int_eq(nL, numeral_info[L].value);
    ck_assert_int_eq(1, numeral_info[L].letter_size);
    ck_assert_int_eq(1, numeral_info[L].allowed_repetitions);
    ck_assert_str_eq("L", numeral_info[L].numeral);
    
    ck_assert_int_eq(nXC, numeral_info[XC].value);
    ck_assert_int_eq(2, numeral_info[XC].letter_size);
    ck_assert_int_eq(1, numeral_info[XC].allowed_repetitions);
    ck_assert_str_eq("XC", numeral_info[XC].numeral);
    
    ck_assert_int_eq(nC, numeral_info[C].value);
    ck_assert_int_eq(1, numeral_info[C].letter_size);
    ck_assert_int_eq(3, numeral_info[C].allowed_repetitions);
    ck_assert_str_eq("C", numeral_info[C].numeral);
    
    ck_assert_int_eq(nCD, numeral_info[CD].value);
    ck_assert_int_eq(2, numeral_info[CD].letter_size);
    ck_assert_int_eq(1, numeral_info[CD].allowed_repetitions);
    ck_assert_str_eq("CD", numeral_info[CD].numeral);
    
    ck_assert_int_eq(nD, numeral_info[D].value);
    ck_assert_int_eq(1, numeral_info[D].letter_size);
    ck_assert_int_eq(1, numeral_info[D].allowed_repetitions);
    ck_assert_str_eq("D", numeral_info[D].numeral);
    
    ck_assert_int_eq(nCM, numeral_info[CM].value);
    ck_assert_int_eq(2, numeral_info[CM].letter_size);
    ck_assert_int_eq(1, numeral_info[CM].allowed_repetitions);
    ck_assert_str_eq("CM", numeral_info[CM].numeral);
    
    ck_assert_int_eq(nM, numeral_info[M].value);
    ck_assert_int_eq(1, numeral_info[M].letter_size);
    ck_assert_int_eq(255, numeral_info[M].allowed_repetitions);
    ck_assert_str_eq("M", numeral_info[M].numeral);
}
END_TEST

START_TEST(test_numeral_info_ordered_indexes)
{
    uint8_t i;
    
    for(i = 0; i < NUMBER_OF_NUMERALS - 1; i++)
    {
        ck_assert_int_lt(numeral_info[numeral_info_ordered_index[i]].value, numeral_info[numeral_info_ordered_index[i + 1]].value);
    }
}
END_TEST

START_TEST(numeral_index_function_will_return_expected_indexes)
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

START_TEST(numeral_value_function_will_return_expected_values)
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

START_TEST(numeral_value_function_will_advance_numeral_pointer_to_indicate_next_numeral)
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

START_TEST(numeral_to_uint_function_will_return_zero_when_no_condition_is_met)
{
    ck_assert_int_eq(numeral_to_uint(NULL), 0);
    ck_assert_int_eq(numeral_to_uint(""), 0);
    ck_assert_int_eq(numeral_to_uint("Z"), 0);
}
END_TEST

START_TEST(numeral_to_uint_function_will_return_expected_unsigned_integers)
{
    ck_assert_int_eq(numeral_to_uint("I"), 1);
    ck_assert_int_eq(numeral_to_uint("III"), 3);
    ck_assert_int_eq(numeral_to_uint("VIII"), 8);
    ck_assert_int_eq(numeral_to_uint("DCCCLXXXVIII"), 888);
    ck_assert_int_eq(numeral_to_uint("MMMM"), 4000);
}
END_TEST

START_TEST(numeral_to_uint_function_will_wrap_around_the_value_of_numerals_bigger_than_65535)
{
    ck_assert_int_eq(numeral_to_uint("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXXXVII"), 1);
}
END_TEST

START_TEST(test_core_numeral_to_uint_conversions)
{
    uint16_t i;
    
    for(i = 0; i < 1000; i++)
    {
        ck_assert_int_eq(numeral_to_uint(third_party_numeral[i]), i + 1);
    }
}
END_TEST

START_TEST(is_five_numeral_index_function_will_return_true_for_V_L_and_D_numerals_and_false_otherwise)
{
    ck_assert(is_five_numeral_index(V));
    ck_assert(is_five_numeral_index(L));
    ck_assert(is_five_numeral_index(D));

    ck_assert(!is_five_numeral_index(INVALID_NUMERAL));
    ck_assert(!is_five_numeral_index(IV));
    ck_assert(!is_five_numeral_index(IX));
    ck_assert(!is_five_numeral_index(I));
    ck_assert(!is_five_numeral_index(XL));
    ck_assert(!is_five_numeral_index(XC));
    ck_assert(!is_five_numeral_index(X));
    ck_assert(!is_five_numeral_index(CD));
    ck_assert(!is_five_numeral_index(CM));
    ck_assert(!is_five_numeral_index(C));
    ck_assert(!is_five_numeral_index(M));
}
END_TEST

START_TEST(uint_to_numeral_function_will_return_a_dynamically_allocated_string)
{
    char* numeral = uint_to_numeral(nINVALID_NUMERAL);

    ck_assert_str_eq(numeral, "");
    free(numeral);

    numeral = uint_to_numeral(4);
    ck_assert_str_eq(numeral, "IV");
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

START_TEST(test_core_uint_to_numeral_conversions)
{
    char* numeral;
    uint16_t i;

    for(i = 0; i < 1000; i++)
    {
        numeral = uint_to_numeral(i + 1);
        ck_assert_str_eq(numeral, third_party_numeral[i]);
        free(numeral);
    }
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_for_unknown_numerals)
{
    ck_assert_uint_eq(is_valid_roman_numeral(NULL), 0);
    ck_assert_uint_eq(is_valid_roman_numeral(""), 0);
    ck_assert_uint_eq(is_valid_roman_numeral("K"), 0);
    ck_assert_uint_eq(is_valid_roman_numeral("VZ"), 0);
    ck_assert_uint_eq(is_valid_roman_numeral("i"), 0);
}
END_TEST

START_TEST(is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_repeated_more_than_three_times)
{
    ck_assert_uint_eq(is_valid_roman_numeral("IIII"), 0);
    ck_assert_uint_eq(is_valid_roman_numeral("XXXX"), 0);
    ck_assert_uint_eq(is_valid_roman_numeral("CCCC"), 0);
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
    tcase_add_test(tc_conversions, test_numeral_info_ordered_indexes);
    tcase_add_test(tc_conversions, numeral_index_function_will_return_expected_indexes);
    tcase_add_test(tc_conversions, numeral_value_function_will_return_expected_values);
    tcase_add_test(tc_conversions, numeral_value_function_will_advance_numeral_pointer_to_indicate_next_numeral);
    tcase_add_test(tc_conversions, numeral_to_uint_function_will_return_zero_when_no_condition_is_met);
    tcase_add_test(tc_conversions, numeral_to_uint_function_will_return_expected_unsigned_integers);
    tcase_add_test(tc_conversions, numeral_to_uint_function_will_wrap_around_the_value_of_numerals_bigger_than_65535);
    tcase_add_test(tc_conversions, test_core_numeral_to_uint_conversions);
    tcase_add_test(tc_conversions, is_five_numeral_index_function_will_return_true_for_V_L_and_D_numerals_and_false_otherwise);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_return_a_dynamically_allocated_string);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_return_expected_combined_numerals);
    tcase_add_test(tc_conversions, uint_to_numeral_function_will_allocated_a_buffer_big_enough_to_handle_maximum_uint16_t_value);
    tcase_add_test(tc_conversions, test_core_uint_to_numeral_conversions);
    tcase_add_test(tc_conversions, is_valid_roman_numeral_function_will_return_false_for_unknown_numerals);
    tcase_add_test(tc_conversions, is_valid_roman_numeral_function_will_return_false_if_numerals_I_X_or_C_are_repeated_more_than_three_times);
    suite_add_tcase(s, tc_conversions);
    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = roman_calculator_suite();
    add_roman_calculator_test_case(s);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
