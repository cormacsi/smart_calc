#include "../credit_calc.h"
#include "test_me.h"

// These tests verify the identity of the values obtained from the official
// website for calculating the credit: https://calcus.ru/kreditnyj-kalkulyator.
// All of the following values for the tests were obtained on this site.

START_TEST(test_credit_calc_1) {
  long double loan = 1000000.;
  long double rate = 12;
  int months = 5;

  long double result = 206039.80;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_2) {
  long double loan = 1000000.;
  long double rate = 13;
  int months = 10;

  long double result = 106054.62;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_3) {
  long double loan = 1000000.;
  long double rate = 13;
  int months = 120;

  long double result = 14931.07;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_4) {
  long double loan = 200000.;
  long double rate = 12.5;
  int months = 60;

  long double result = 4499.59;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_5) {
  long double loan = 100000.;
  long double rate = 8.9;
  int months = 30;

  long double result = 3730.20;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_6) {
  long double loan = 100.;
  long double rate = 22.1;
  int months = 12;

  long double result = 9.36;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_7) {
  long double loan = 95000.;
  long double rate = 14.3;
  int months = 4;

  long double result = 24461.74;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_8) {
  long double loan = 7500000.;
  long double rate = 12.75;
  int months = 156;

  long double result = 98658.42;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_9) {
  long double loan = 8000000.;
  long double rate = 11.4;
  int months = 192;

  long double result = 90776.;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_10) {
  long double loan = 18000000.;
  long double rate = 7.2;
  int months = 264;

  long double result = 136041.77;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_11) {
  long double loan = 63000.;
  long double rate = 30;
  int months = 1;

  long double result = 64575.;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_12) {
  long double loan = 63000.;
  long double rate = 30;
  int months = 6;

  long double result = 11437.65;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_13) {
  long double loan = 44400000.;
  long double rate = 32;
  int months = 48;

  long double result = 1650724.25;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_14) {
  long double loan = 0.;
  long double rate = 10.;
  int months = 12;

  long double result = 0.;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_15) {
  long double loan = 100.;
  long double rate = 10.;
  int months = 1;

  long double result = 100.83;
  ck_assert_ldouble_eq(credit_calc(loan, rate, months), result);
}
END_TEST

START_TEST(test_credit_calc_16) {
  long double loan = 100000.;
  long double rate = 10.;
  int months = 12;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 9166.67;
  mass[1] = 9097.22;
  mass[2] = 9027.78;
  mass[3] = 8958.33;
  mass[4] = 8888.89;
  mass[5] = 8819.44;
  mass[6] = 8750.00;
  mass[7] = 8680.56;
  mass[8] = 8611.11;
  mass[9] = 8541.67;
  mass[10] = 8472.22;
  mass[11] = 8402.78;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_17) {
  long double loan = 1000000.;
  long double rate = 20.;
  int months = 12;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 100000.00;
  mass[1] = 98611.11;
  mass[2] = 97222.22;
  mass[3] = 95833.33;
  mass[4] = 94444.44;
  mass[5] = 93055.56;
  mass[6] = 91666.67;
  mass[7] = 90277.78;
  mass[8] = 88888.89;
  mass[9] = 87500.00;
  mass[10] = 86111.11;
  mass[11] = 84722.22;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_18) {
  long double loan = 5555555.;
  long double rate = 12.6;
  int months = 12;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 521296.24;
  mass[1] = 516435.13;
  mass[2] = 511574.02;
  mass[3] = 506712.91;
  mass[4] = 501851.80;
  mass[5] = 496990.69;
  mass[6] = 492129.58;
  mass[7] = 487268.47;
  mass[8] = 482407.36;
  mass[9] = 477546.25;
  mass[10] = 472685.14;
  mass[11] = 467824.03;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_19) {
  long double loan = 65555555.;
  long double rate = 14.7;
  int months = 24;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 3534537.01;
  mass[1] = 3501076.36;
  mass[2] = 3467615.71;
  mass[3] = 3434155.06;
  mass[4] = 3400694.42;
  mass[5] = 3367233.77;
  mass[6] = 3333773.12;
  mass[7] = 3300312.47;
  mass[8] = 3266851.82;
  mass[9] = 3233391.18;
  mass[10] = 3199930.53;
  mass[11] = 3166469.88;
  mass[12] = 3133009.23;
  mass[13] = 3099548.58;
  mass[14] = 3066087.94;
  mass[15] = 3032627.29;
  mass[16] = 2999166.64;
  mass[17] = 2965705.99;
  mass[18] = 2932245.35;
  mass[19] = 2898784.70;
  mass[20] = 2865324.05;
  mass[21] = 2831863.40;
  mass[22] = 2798402.75;
  mass[23] = 2764942.11;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_20) {
  long double loan = 800000.;
  long double rate = 35.;
  int months = 6;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 156666.67;
  mass[1] = 152777.78;
  mass[2] = 148888.89;
  mass[3] = 145000.00;
  mass[4] = 141111.11;
  mass[5] = 137222.22;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_21) {
  long double loan = 700000.;
  long double rate = 100.;
  int months = 7;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 158333.33;
  mass[1] = 150000.00;
  mass[2] = 141666.67;
  mass[3] = 133333.33;
  mass[4] = 125000.00;
  mass[5] = 116666.67;
  mass[6] = 108333.33;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    // result = round(result * 100.) / 100.;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_22) {
  long double loan = 40000000.;
  long double rate = 16.7;
  int months = 13;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 3633589.74;
  mass[1] = 3590769.23;
  mass[2] = 3547948.72;
  mass[3] = 3505128.21;
  mass[4] = 3462307.69;
  mass[5] = 3419487.18;
  mass[6] = 3376666.67;
  mass[7] = 3333846.15;
  mass[8] = 3291025.64;
  mass[9] = 3248205.13;
  mass[10] = 3205384.62;
  mass[11] = 3162564.10;
  mass[12] = 3119743.59;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_23) {
  long double loan = 6500000000.;
  long double rate = 5.;
  int months = 6;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 1110416666.67;
  mass[1] = 1105902777.78;
  mass[2] = 1101388888.89;
  mass[3] = 1096875000.00;
  mass[4] = 1092361111.11;
  mass[5] = 1087847222.22;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

START_TEST(test_credit_calc_24) {
  long double loan = 7500000000.;
  long double rate = 11.;
  int months = 240;
  long double MP = loan / months;

  long double mass[2];
  mass[0] = 100000000.00;
  mass[1] = 31536458.33;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    if (i == 0) ck_assert_ldouble_eq_tol(result, mass[0], 10e-3);
    if (i == months - 1) ck_assert_ldouble_eq_tol(result, mass[1], 10e-3);
    loan -= MP;
  }
}
END_TEST

START_TEST(test_credit_calc_25) {
  long double loan = 650000.;
  long double rate = 24.4;
  int months = 3;
  long double MP = loan / months;

  long double *mass = calloc(months, sizeof(long double));
  mass[0] = 229883.33;
  mass[1] = 225477.78;
  mass[2] = 221072.22;

  for (int i = 0; i < months; i++) {
    long double result = differen_calc(loan, rate) + MP;
    ck_assert_ldouble_eq_tol(result, mass[i], 10e-3);
    loan -= MP;
  }
  if (mass) free(mass);
}
END_TEST

Suite *test_credit_calc(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST CREDIT CALC=-\033[0m");
  TCase *tc = tcase_create("s21_test_credit_calc_tc");

  tcase_add_test(tc, test_credit_calc_1);
  tcase_add_test(tc, test_credit_calc_2);
  tcase_add_test(tc, test_credit_calc_3);
  tcase_add_test(tc, test_credit_calc_4);
  tcase_add_test(tc, test_credit_calc_5);
  tcase_add_test(tc, test_credit_calc_6);
  tcase_add_test(tc, test_credit_calc_7);
  tcase_add_test(tc, test_credit_calc_8);
  tcase_add_test(tc, test_credit_calc_9);
  tcase_add_test(tc, test_credit_calc_10);
  tcase_add_test(tc, test_credit_calc_11);
  tcase_add_test(tc, test_credit_calc_12);
  tcase_add_test(tc, test_credit_calc_13);
  tcase_add_test(tc, test_credit_calc_14);
  tcase_add_test(tc, test_credit_calc_15);
  tcase_add_test(tc, test_credit_calc_16);
  tcase_add_test(tc, test_credit_calc_17);
  tcase_add_test(tc, test_credit_calc_18);
  tcase_add_test(tc, test_credit_calc_19);
  tcase_add_test(tc, test_credit_calc_20);
  tcase_add_test(tc, test_credit_calc_21);
  tcase_add_test(tc, test_credit_calc_22);
  tcase_add_test(tc, test_credit_calc_23);
  tcase_add_test(tc, test_credit_calc_24);
  tcase_add_test(tc, test_credit_calc_25);

  suite_add_tcase(s, tc);
  return s;
}
