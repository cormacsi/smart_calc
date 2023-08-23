#include "test_me.h"

START_TEST(test_only_graph_1) {
  int error = OK;
  char expression[50] = "sin(4)+sin(10*4)";
  long double result = -0.0116893;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_only_graph_2) {
  int error = OK;
  char expression[50] = "";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_only_graph_3) {
  int error = OK;
  char expression[50] = "4.13456";
  long double result = 4.13456;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_only_graph_4) {
  int error = OK;
  char expression[50] = "2*cos(4)+cos(2*4)-2*sin(4)^3";
  long double result = -0.5858699;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_only_graph_5) {
  int error = OK;
  char expression[50] = "3^3-6*3^2+4*3+12";
  long double result = -3.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_only_graph_6) {
  int error = OK;
  char expression[50] = "sin(8*5/3-4)*7.3+14^(-0.2)";
  long double result = 1.25651038191;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_only_graph_7) {
  int error = OK;
  char expression[50] = "sin(8*/5/3-4)*7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_only_graph_8) {
  int error = OK;
  char expression[50] = "sin(8/5/3-4)*log7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_only_graph_9) {
  int error = OK;
  char expression[50] = "sin(8/5/3-4)*log(π)-7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, SORT_ERROR);  // π is not availiable in this function
}
END_TEST

START_TEST(test_only_graph_10) {
  int error = OK;
  char expression[50] = "sin(8/5/3-4)*log((9-7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

START_TEST(test_only_graph_11) {
  int error = OK;
  char expression[50] = "sin(8/5/3-4)*loog(9)-7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_only_graph_12) {
  int error = OK;
  char expression[50] = "sin(8/5/3-4)*log(9-7.3+14^(-0.2)";
  long double result = 0.;

  long double test_res = graph_only(expression, X_SORT, &error);
  ck_assert_ldouble_eq_tol(test_res, result, 1e-7);
  ck_assert_int_eq(error, YARD_ERROR);
}
END_TEST

Suite *test_only_graph(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST ONLY GRAPH=-\033[0m");
  TCase *tc = tcase_create("s21_test_only_graph_tc");

  tcase_add_test(tc, test_only_graph_1);
  tcase_add_test(tc, test_only_graph_2);
  tcase_add_test(tc, test_only_graph_3);
  tcase_add_test(tc, test_only_graph_4);
  tcase_add_test(tc, test_only_graph_5);
  tcase_add_test(tc, test_only_graph_6);
  tcase_add_test(tc, test_only_graph_7);
  tcase_add_test(tc, test_only_graph_8);
  tcase_add_test(tc, test_only_graph_9);
  tcase_add_test(tc, test_only_graph_10);
  tcase_add_test(tc, test_only_graph_11);
  tcase_add_test(tc, test_only_graph_12);

  suite_add_tcase(s, tc);
  return s;
}
