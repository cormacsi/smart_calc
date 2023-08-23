#include "test_me.h"

START_TEST(test_calculation_1) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "(-58 + * 10)";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_2) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "(-58 + (6 * 10) 8)";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_3) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "(* 8 / 6) - 5";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_4) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "( * )";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_5) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] = "( 5 // )";
  ck_assert_ldouble_eq(smart_calc(expression, X_TEST, &error), true_result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_6) {
  int error = OK;
  long double true_result = 35.28376126;
  char expression[300] =
      "(-58 + tan(58)*sqrt(58)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-58 + "
      "tan(58)*sqrt(58)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  long double my_result = smart_calc(expression, X_TEST, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_7) {
  int error = OK;
  long double true_result = 35.28376126;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "58.0";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_8) {
  int error = OK;
  long double true_result = 4.;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3,23 mod 32))*8^-3,2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "0.0";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_9) {
  int error = OK;
  long double true_result = 0.;
  char expression[300] =
      "(-x + tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) * (-x + "
      "tan(x)*sqrt(x)/(+1-(sqrt(3.23 mod 32))*8^-3.2)) + 4";
  char x_num[20] = "";
  long double my_result = smart_calc(expression, x_num, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, SIZE_ERROR);
}
END_TEST

START_TEST(test_calculation_10) {
  int error = OK;
  long double true_result = -4.56533953;
  char expression[300] =
      "(3.0 + 4.5 * 2 / Log ( 15.6 - 4.6) ^ 2 ^ 3 + Cos(Atan (0.4)) - sqrt(((6 "
      "^ 2 ^ 3) * 8) ^ 2)  + (- 14) % 6 ) Mod 5";
  long double my_result = smart_calc(expression, X_TEST, &error);
  ck_assert_ldouble_eq_tol(my_result, true_result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_11) {
  int error = OK;
  long double result = 1.57079633;
  stack *output = NULL;  // 1 asin
  struct_token element;

  element.type = ASIN, element.value = 0.;
  push(&output, element);

  element.type = NUM, element.value = 1.;
  push(&output, element);

  ck_assert_ldouble_eq_tol(calculation(&output, &error), result, 1e-6);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
}
END_TEST

START_TEST(test_calculation_12) {
  int error = OK;
  long double result = M_PI / 2.;
  stack *output = NULL;  // 0 acos
  struct_token element;

  element.type = ACOS, element.value = 0.;
  push(&output, element);

  element.type = NUM, element.value = 0.;
  push(&output, element);

  ck_assert_ldouble_eq_tol(calculation(&output, &error), result, 1e-6);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
}
END_TEST

START_TEST(test_calculation_13) {
  int error = OK;
  long double result = -(M_PI / 4.);
  stack *output = NULL;  // 0 atan
  struct_token element;

  element.type = ATAN, element.value = 0.;
  push(&output, element);

  element.type = NUM, element.value = -1.;
  push(&output, element);

  ck_assert_ldouble_eq_tol(calculation(&output, &error), result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_14) {
  int error = OK;
  long double result = 0.;
  stack *output = NULL;  // 0 sin
  struct_token element;

  element.type = SIN, element.value = 0.;
  push(&output, element);

  element.type = NUM, element.value = 2. * M_PI;
  push(&output, element);

  ck_assert_ldouble_eq_tol(calculation(&output, &error), result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_calculation_15) {
  int error = OK;
  long double result = -0.693147;
  stack *output = NULL;  // 0.5 ln
  struct_token element;

  element.type = LN, element.value = 0.;
  push(&output, element);

  element.type = NUM, element.value = 0.5;
  push(&output, element);

  ck_assert_ldouble_eq_tol(calculation(&output, &error), result, 1e-6);
  ck_assert_int_eq(error, OK);
}
END_TEST

Suite *test_calculation(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST CALCULATION=-\033[0m");
  TCase *tc = tcase_create("s21_test_calculation_tc");

  tcase_add_test(tc, test_calculation_1);
  tcase_add_test(tc, test_calculation_2);
  tcase_add_test(tc, test_calculation_3);
  tcase_add_test(tc, test_calculation_4);
  tcase_add_test(tc, test_calculation_5);
  tcase_add_test(tc, test_calculation_6);
  tcase_add_test(tc, test_calculation_7);
  tcase_add_test(tc, test_calculation_8);
  tcase_add_test(tc, test_calculation_9);
  tcase_add_test(tc, test_calculation_10);
  tcase_add_test(tc, test_calculation_11);
  tcase_add_test(tc, test_calculation_12);
  tcase_add_test(tc, test_calculation_13);
  tcase_add_test(tc, test_calculation_14);
  tcase_add_test(tc, test_calculation_15);

  suite_add_tcase(s, tc);
  return s;
}
