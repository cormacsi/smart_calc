#include "test_me.h"

// asin(x+45)+cos(x)/tan(x)-acos(x-0.122)*asin(x)-atan(x)-sqrt(4)+ln(x)+log(x)+
// ln(123^x)

START_TEST(test_main_1) {
  int error = OK;
  char expression[260] = "";
  smart_calc(expression, X_TEST, &error);
  ck_assert_int_eq(error, SIZE_ERROR);
}
END_TEST

START_TEST(test_main_2) {
  int error = OK;
  char expression[400] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  smart_calc(expression, X_TEST, &error);
  ck_assert_int_eq(error, SIZE_ERROR);
}
END_TEST

START_TEST(test_main_3) {
  int error = OK;
  char expression[300] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+11";
  smart_calc(expression, X_TEST, &error);
  ck_assert_int_eq(error, SIZE_ERROR);
}
END_TEST

START_TEST(test_main_4) {
  int error = OK;
  long double true_result = 128.;
  char expression[300] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1\
+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_5) {
  int error = OK;
  char expression[10] = "3+5 h";
  smart_calc(expression, X_TEST, &error);
  ck_assert_int_eq(error, INPUT_ERROR);
}
END_TEST

START_TEST(test_main_6) {
  int error = OK;
  char expression[20] = "3+5 $ 7 * 8";
  smart_calc(expression, X_TEST, &error);
  ck_assert_int_eq(error, INPUT_ERROR);
}
END_TEST

START_TEST(test_main_7) {
  int error = OK;
  long double true_result = 8.;
  char expression[10] = "3+5";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_8) {
  int error = OK;
  long double true_result = 15.;
  char expression[40] = "3 + 5 ^ 2 * 3 / 6 - 0.5 mod 2";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_9) {
  int error = OK;
  long double true_result = 15.;
  char expression[50] =
      "3 +   5 ^   2 * 3 /    \t 6 - 0.5    \t\t mod 5\n\n\n\n";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_10) {
  int error = OK;
  long double true_result = 9.;
  char expression[50] = "33 \n\n\n\t\v\f\r mod 4\n\n\n\n\n\n   + 8.\t\v\f\r";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_11) {
  int error = OK;
  long double true_result = 0.;
  char expression[30] = "8 * (33 + (- 6) ";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_12) {
  int error = OK;
  long double true_result = 0.;
  char expression[10] = "())";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_13) {
  int error = OK;
  long double true_result = 343000.;
  char expression[30] = "(5^2+3^2+6^2)^3";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_14) {
  int error = OK;
  long double true_result = 8615125.;
  char expression[30] = "(5^2+x^2+6^2)^3";
  char x_str[20] = "7+5-(6*4)";
  ck_assert_ldouble_eq(smart_calc(expression, x_str, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_15) {
  int error = OK;
  long double true_result = 8615125.;
  char expression[30] = "(5^2+x^2+6^2)^3";
  char x_str[20] = "7+5-(6*4)";
  ck_assert_ldouble_eq(smart_calc(expression, x_str, &error), true_result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_16) {
  int error = OK;
  long double true_result = 0.;
  char expression[30] = "(5^2+x^2+6^2)^3";
  char x_str[20] = "7+5-(6*x)";
  ck_assert_ldouble_eq(smart_calc(expression, x_str, &error), true_result);
  ck_assert_int_eq(error, INPUT_ERROR);
}
END_TEST

START_TEST(test_main_17) {
  int error = OK;
  long double true_result = -5.017595073;
  char expression[50] = "sin (x) * 5 - 4 ^ 3 *   (cos(46^2)^4)";
  char x_str[20] = "7+5-cos(6)";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_18) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 - 4 ^ 3 *   (cos(46^2)^4)";
  char x_str[20] = "7+5-cos(6))";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_19) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 ÷÷ 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_20) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 √√ 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_main_21) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 ×× 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_22) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 ·× 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_23) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 ↑√↑↑√↑ 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_main_24) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 √↑ 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_main_25) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 ↑√↑↑√↑ 4 ^ 3";
  char x_str[20] = "7";
  ck_assert_ldouble_eq_tol(smart_calc(expression, x_str, &error), true_result,
                           1e-6);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_main_26) {
  int error = OK;
  long double true_result = 0.;
  char expression[50] = "sin (x) * 5 - 4 ^ 3 *(cos(46^2)^4)";
  char x_str[30] = "7+5-cos((6*4)";
  ck_assert_ldouble_eq(smart_calc(expression, x_str, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_27) {
  int error = OK;
  long double true_result = 0.;
  char expression[20] = "sin ((4) ";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_28) {
  int error = OK;
  long double true_result = 0.;
  char expression[20] = "sin (5 ";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_29) {
  int error = OK;
  long double true_result = 0.;
  char expression[30] = "(sin ((6)+ 4) ";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_30) {
  int error = OK;
  long double true_result = 0.;
  char expression[40] = "cos((sin ((9) +tan((7))))";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_31) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "\n\n";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_32) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = " ";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_33) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "+";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_34) {
  int error = OK;
  long double true_result = 580851.781645;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "5 + 6";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_35) {
  int error = OK;
  long double true_result = 4.;
  char expression[300] = "tan(8) + - x";
  char x_num[20] = "tan(8) + - 4";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_36) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "tan(8) + - x";
  char x_num[20] = "tan(8) + - / 4";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_37) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "tan(8) + - x";
  char x_num[20] = "tan((8) + 4";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_main_38) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "tan(8) + - x";
  char x_num[20] = "tan 8) + 4";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_main_39) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "  ";
  char x_num[20] = "";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_main_40) {
  int error = OK;
  long double true_result = 144634.73598295316;
  char expression[300] = "144634.73598295316";
  long double my_result = smart_calc(expression, X_TEST, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_41) {
  int error = OK;
  long double true_result = 11.78699185;
  char expression[300] = "7.32457185 + 4.46242";
  char x_num[20] = "";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_42) {
  int error = OK;
  long double true_result = 7.3;
  char expression[300] = "7.3";
  char x_num[20] = "";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_main_43) {
  int error = OK;
  long double true_result = 2.4;
  char expression[300] = "5.6-3.2";
  char x_num[20] = "";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

Suite *test_smart_calc(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST SMART CALC=-\033[0m");
  TCase *tc = tcase_create("s21_test_smart_calc_tc");

  tcase_add_test(tc, test_main_1);
  tcase_add_test(tc, test_main_2);
  tcase_add_test(tc, test_main_3);
  tcase_add_test(tc, test_main_4);
  tcase_add_test(tc, test_main_5);
  tcase_add_test(tc, test_main_6);
  tcase_add_test(tc, test_main_7);
  tcase_add_test(tc, test_main_8);
  tcase_add_test(tc, test_main_9);
  tcase_add_test(tc, test_main_10);
  tcase_add_test(tc, test_main_11);
  tcase_add_test(tc, test_main_12);
  tcase_add_test(tc, test_main_13);
  tcase_add_test(tc, test_main_14);
  tcase_add_test(tc, test_main_15);
  tcase_add_test(tc, test_main_16);
  tcase_add_test(tc, test_main_17);
  tcase_add_test(tc, test_main_18);
  tcase_add_test(tc, test_main_19);
  tcase_add_test(tc, test_main_20);
  tcase_add_test(tc, test_main_21);
  tcase_add_test(tc, test_main_22);
  tcase_add_test(tc, test_main_23);
  tcase_add_test(tc, test_main_24);
  tcase_add_test(tc, test_main_25);
  tcase_add_test(tc, test_main_26);
  tcase_add_test(tc, test_main_27);
  tcase_add_test(tc, test_main_28);
  tcase_add_test(tc, test_main_29);
  tcase_add_test(tc, test_main_30);
  tcase_add_test(tc, test_main_31);
  tcase_add_test(tc, test_main_32);
  tcase_add_test(tc, test_main_33);
  tcase_add_test(tc, test_main_34);
  tcase_add_test(tc, test_main_35);
  tcase_add_test(tc, test_main_36);
  tcase_add_test(tc, test_main_37);
  tcase_add_test(tc, test_main_38);
  tcase_add_test(tc, test_main_39);
  tcase_add_test(tc, test_main_40);
  tcase_add_test(tc, test_main_41);
  tcase_add_test(tc, test_main_42);
  tcase_add_test(tc, test_main_43);

  suite_add_tcase(s, tc);
  return s;
}
