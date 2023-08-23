#include "../deposit_calc.h"
#include "test_me.h"

// #include <time.h>

START_TEST(test_deposit_calc_1) {
  deposit calc;
  calc.amount = 100000.;
  calc.pay_type = 1;
  calc.total_month = 12;
  calc.interest = 13;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  // time_t now;
  // time(&now);
  // struct tm *local = localtime(&now);

  // t_date current;
  // current.date = local->tm_mday;
  // current.month = local->tm_mon + 1;
  // current.year = local->tm_year + 1900;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 13024.60;
  r_test.t_amount = 0.;
  r_test.d_amount = 100000.;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-1);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_2) {
  deposit calc;
  calc.amount = 90000.;
  calc.pay_type = 2;
  calc.total_month = 8;
  calc.interest = 15.6;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 9825.19;
  r_test.t_amount = 0.;
  r_test.d_amount = 99825.19;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_3) {
  deposit calc;
  calc.amount = 800000.;
  calc.pay_type = 0;
  calc.total_month = 8;
  calc.interest = 22.2;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 127944.68;
  r_test.t_amount = 6882.81;
  r_test.d_amount = 927944.68;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_4) {
  deposit calc;
  calc.amount = 700000.;
  calc.pay_type = 2;
  calc.total_month = 8;
  calc.interest = 7.4;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 35386.68;
  r_test.t_amount = 0.;
  r_test.d_amount = 735386.68;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_5) {
  deposit calc;
  calc.amount = 7000000.;
  calc.pay_type = 0;
  calc.total_month = 10 * 12;  // 10 years
  calc.interest = 17.4;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 32864885.77;
  r_test.t_amount = 4165185.15;
  r_test.d_amount = 39864885.77;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_6) {
  deposit calc;
  calc.amount = 12000000.;
  calc.pay_type = 0;
  calc.total_month = 20 * 12;  // 20 years
  calc.interest = 5.6;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 24775093.47;
  r_test.t_amount = 3016012.15;
  r_test.d_amount = 36775093.47;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_7) {
  deposit calc;
  calc.amount = 9000000.;
  calc.pay_type = 0;
  calc.total_month = 25 * 12;  // 20 years
  calc.interest = 11.;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 131754724.80;
  r_test.t_amount = 16874614.22;
  r_test.d_amount = 140754724.80;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_8) {
  deposit calc;
  calc.amount = 5550000.;
  calc.pay_type = 2;
  calc.total_month = 7;
  calc.interest = 6.;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 198206.48;
  r_test.t_amount = 16016.84;
  r_test.d_amount = 5748206.48;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_9) {
  deposit calc;
  calc.amount = 9000000.;
  calc.pay_type = 2;
  calc.total_month = 8;
  calc.interest = 13.;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 1;
  calc.rep_amount = 100000.;
  calc.wit_type = 0;
  calc.wit_amount = 0;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 812553.42;
  r_test.t_amount = 95881.94;
  r_test.d_amount = 9800000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_10) {
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 2;
  calc.total_month = 8;
  calc.interest = 16.5;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 1;
  calc.wit_amount = 50000.;

  t_date current;
  current.date = 22;
  current.month = 4;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 1083710.96;
  r_test.t_amount = 131132.42;
  r_test.d_amount = 9600000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_11) {
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 3;
  calc.total_month = 8;
  calc.interest = 16.5;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 2;
  calc.wit_amount = 50000.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 1095153.68;
  r_test.t_amount = 132619.98;
  r_test.d_amount = 9900000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-1);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-1);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-1);
}
END_TEST

START_TEST(test_deposit_calc_12) {
  // tests for coverage
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 4;
  calc.total_month = 6;
  calc.interest = 14.5;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 721038.25;
  r_test.t_amount = 83984.97;
  r_test.d_amount = 10000000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_13) {
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 5;
  calc.total_month = 12 * 12;
  calc.interest = 10.5;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 12600094.28;
  r_test.t_amount = 1521012.25;
  r_test.d_amount = 10000000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_14) {
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 5;
  calc.total_month = 12 * 12;
  calc.interest = 10.5;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 4;
  calc.rep_amount = 100000.;
  calc.wit_type = 0;
  calc.wit_amount = 0;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 13290947.16;
  r_test.t_amount = 1610823.13;
  r_test.d_amount = 11200000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_15) {
  deposit calc;
  calc.amount = 10000000.;
  calc.pay_type = 5;
  calc.total_month = 11;
  calc.interest = 9.5;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 869535.52;
  r_test.t_amount = 103289.62;
  r_test.d_amount = 10869535.52;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_16) {
  deposit calc;
  calc.amount = 600000.;
  calc.pay_type = 5;
  calc.total_month = 11;
  calc.interest = 7.8;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 20000.;
  calc.wit_type = 0;
  calc.wit_amount = 30000.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 42836.07;
  r_test.t_amount = 0.00;
  r_test.d_amount = 642836.07;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_17) {
  deposit calc;
  calc.amount = 600000.;
  calc.pay_type = 5;
  calc.total_month = 11;
  calc.interest = 7.8;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 7070990.;
  calc.wit_type = 0;
  calc.wit_amount = 215132.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 42836.07;
  r_test.t_amount = 0.00;
  r_test.d_amount = 642836.07;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_18) {
  deposit calc;
  calc.amount = 1500000.;
  calc.pay_type = 0;
  calc.total_month = 2 * 12;
  calc.interest = 7.;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 325.;
  calc.wit_type = 0;
  calc.wit_amount = 5352.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2024;

  s_result r_test;
  r_test.accrued = 225388.50;
  r_test.t_amount = 9757.49;
  r_test.d_amount = 1725388.50;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_19) {
  deposit calc;
  calc.amount = 1500000.;
  calc.pay_type = 1;
  calc.total_month = 10;
  calc.interest = 5.;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2023;

  s_result r_test;
  r_test.accrued = 63727.72;
  r_test.t_amount = 0.0;
  r_test.d_amount = 1563727.72;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_20) {
  deposit calc;
  calc.amount = 1500000.;
  calc.pay_type = 5;
  calc.total_month = 18;
  calc.interest = 25.;
  calc.tax = 13;
  calc.cap = 1;
  calc.rep_type = 3;
  calc.rep_amount = 200000.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 1;
  current.year = 2000;

  s_result r_test;
  r_test.accrued = 611301.37;
  r_test.t_amount = 59969.17;
  r_test.d_amount = 2711301.37;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

START_TEST(test_deposit_calc_21) {
  deposit calc;
  calc.amount = 1600000.;
  calc.pay_type = 6;
  calc.total_month = 9;
  calc.interest = 25.;
  calc.tax = 13;
  calc.cap = 0;
  calc.rep_type = 0;
  calc.rep_amount = 0.;
  calc.wit_type = 0;
  calc.wit_amount = 0.;

  t_date current;
  current.date = 1;
  current.month = 2;
  current.year = 2100;

  s_result r_test;
  r_test.accrued = 299178.08;
  r_test.t_amount = 29143.15;
  r_test.d_amount = 1600000.00;

  s_result result = deposit_calculator(calc, current);
  ck_assert_ldouble_eq_tol(result.accrued, r_test.accrued, 1e-2);
  ck_assert_ldouble_eq_tol(result.d_amount, r_test.d_amount, 1e-2);
  ck_assert_ldouble_eq_tol(result.t_amount, r_test.t_amount, 1e-2);
}
END_TEST

Suite *test_deposit_calc(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST DEPOSIT CALC=-\033[0m");
  TCase *tc = tcase_create("s21_test_deposit_calc_tc");

  tcase_add_test(tc, test_deposit_calc_1);
  tcase_add_test(tc, test_deposit_calc_2);
  tcase_add_test(tc, test_deposit_calc_3);
  tcase_add_test(tc, test_deposit_calc_4);
  tcase_add_test(tc, test_deposit_calc_5);
  tcase_add_test(tc, test_deposit_calc_6);
  tcase_add_test(tc, test_deposit_calc_7);
  tcase_add_test(tc, test_deposit_calc_8);
  tcase_add_test(tc, test_deposit_calc_9);
  tcase_add_test(tc, test_deposit_calc_10);
  tcase_add_test(tc, test_deposit_calc_11);
  tcase_add_test(tc, test_deposit_calc_12);
  tcase_add_test(tc, test_deposit_calc_13);
  tcase_add_test(tc, test_deposit_calc_14);
  tcase_add_test(tc, test_deposit_calc_15);
  tcase_add_test(tc, test_deposit_calc_16);
  tcase_add_test(tc, test_deposit_calc_17);
  tcase_add_test(tc, test_deposit_calc_18);
  tcase_add_test(tc, test_deposit_calc_19);
  tcase_add_test(tc, test_deposit_calc_20);
  tcase_add_test(tc, test_deposit_calc_21);

  suite_add_tcase(s, tc);
  return s;
}
