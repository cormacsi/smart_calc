#include "test_me.h"

START_TEST(test_sort_1) {
  int error = OK;
  char expression[20] = "4+5-3/7*2";
  stack *true_res = NULL;
  struct_token element;  // 4 5 + 3 7 / 2 * -

  element.type = SUB, element.value = 0.;  // -
  push(&true_res, element);

  element.type = MUL, element.value = 0.;  // *
  push(&true_res, element);

  element.type = NUM, element.value = 2.;  // 2
  push(&true_res, element);

  element.type = DIV, element.value = 0.;  // /
  push(&true_res, element);

  element.type = NUM, element.value = 7.;  // 7
  push(&true_res, element);

  element.type = NUM, element.value = 3.;  // 3
  push(&true_res, element);

  element.type = ADD, element.value = 0.;  // +
  push(&true_res, element);

  element.type = NUM, element.value = 5.;  // 5
  push(&true_res, element);

  element.type = NUM, element.value = 4.;  // 4
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_2) {
  int error = OK;
  char expression[10] = "4%3";
  stack *true_res = NULL;
  struct_token element;  // 4 3 mod

  element.type = MOD, element.value = 0.;  // mod
  push(&true_res, element);

  element.type = NUM, element.value = 3.;  // 3
  push(&true_res, element);

  element.type = NUM, element.value = 4.;  // 4
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_3) {
  int error = OK;
  char expression[10] = "4mood3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_sort_4) {
  int error = OK;
  char expression[10] = "4moo3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_sort_5) {
  int error = OK;
  char expression[10] = "4modd3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_sort_6) {
  int error = OK;
  char expression[10] = "4sqr3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_sort_7) {
  int error = OK;
  char expression[30] = "#(25)+sqrt(16)";
  stack *true_res = NULL;
  struct_token element;  // 25 sqrt 16 sqrt +

  element.type = ADD, element.value = 0.;  // +
  push(&true_res, element);

  element.type = SQRT, element.value = 0.;  // sqrt
  push(&true_res, element);

  element.type = NUM, element.value = 16.;  // 16
  push(&true_res, element);

  element.type = SQRT, element.value = 0.;  // sqrt
  push(&true_res, element);

  element.type = NUM, element.value = 25.;  // 25
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_8) {
  int error = OK;
  char expression[30] = "ln(2.69)";
  stack *true_res = NULL;
  struct_token element;  // 2.69 ln

  element.type = LN, element.value = 0.;  // ln
  push(&true_res, element);

  element.type = NUM, element.value = 2.69;  // 2.69
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_9) {
  int error = OK;
  char expression[30] = "log(2.69)";
  stack *true_res = NULL;
  struct_token element;  // 2.69 log

  element.type = LOG, element.value = 0.;  // log
  push(&true_res, element);

  element.type = NUM, element.value = 2.69;  // 2.69
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_10) {
  int error = OK;
  char expression[30] = "sin(1.8)*asin(18)+P";
  stack *true_res = NULL;
  struct_token element;  // 1.8 sin 18 asin * pi +

  element.type = ADD, element.value = 0.;  // +
  push(&true_res, element);

  element.type = NUM, element.value = M_PI;  // PI
  push(&true_res, element);

  element.type = MUL, element.value = 0.;  // *
  push(&true_res, element);

  element.type = ASIN, element.value = 0.;  // asin
  push(&true_res, element);

  element.type = NUM, element.value = 18.;  // 18
  push(&true_res, element);

  element.type = SIN, element.value = 0.;  // sin
  push(&true_res, element);

  element.type = NUM, element.value = 1.8;  // 1.8
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_11) {
  int error = OK;
  char expression[30] = "cos(1.3)-acos(9.5)";
  stack *true_res = NULL;
  struct_token element;  // 1.3 cos 9.5 acos -

  element.type = SUB, element.value = 0.;  // -
  push(&true_res, element);

  element.type = ACOS, element.value = 0.;  // acos
  push(&true_res, element);

  element.type = NUM, element.value = 9.5;  // 9.5
  push(&true_res, element);

  element.type = COS, element.value = 0.;  // cos
  push(&true_res, element);

  element.type = NUM, element.value = 1.3;  // 1.3
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_12) {
  int error = OK;
  char expression[30] = "tan(1.8)+atan(3.56)";
  stack *true_res = NULL;
  struct_token element;  // 1.8 tan + 3.56 atan

  element.type = ADD, element.value = 0.;  // +
  push(&true_res, element);

  element.type = ATAN, element.value = 0.;  // atan
  push(&true_res, element);

  element.type = NUM, element.value = 3.56;  // 3.56
  push(&true_res, element);

  element.type = TAN, element.value = 0.;  // tan
  push(&true_res, element);

  element.type = NUM, element.value = 1.8;  // 1.8
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_13) {
  int error = OK;
  char expression[50] = "#(1.8)^2*3*5/10^1";
  stack *true_res = NULL;
  struct_token element;  // 1.8 sqrt 2 ^ 3 * 5 * 10 / 1 ^

  element.type = DIV, element.value = 0.;  // /
  push(&true_res, element);

  element.type = POW, element.value = 0.;  // ^
  push(&true_res, element);

  element.type = NUM, element.value = 1.;  // 1
  push(&true_res, element);

  element.type = NUM, element.value = 10.;  // 10
  push(&true_res, element);

  element.type = MUL, element.value = 0.;  // *
  push(&true_res, element);

  element.type = NUM, element.value = 5.;  // 5
  push(&true_res, element);

  element.type = MUL, element.value = 0.;  // *
  push(&true_res, element);

  element.type = NUM, element.value = 3.;  // 3
  push(&true_res, element);

  element.type = POW, element.value = 0.;  // pow
  push(&true_res, element);

  element.type = NUM, element.value = 2.;  // 2
  push(&true_res, element);

  element.type = SQRT, element.value = 0.;  // sqrt
  push(&true_res, element);

  element.type = NUM, element.value = 1.8;  // 1.8
  push(&true_res, element);

  stack *output = sort(expression, X_SORT, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_14) {
  int error = OK;
  char expression[50] = "2↑↑↑3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

START_TEST(test_sort_15) {
  int error = OK;
  char expression[10] = "4+x";
  char x_value = 48;
  stack *true_res = NULL;
  struct_token element;  // 4 48 +

  element.type = ADD, element.value = 0.;  // +
  push(&true_res, element);

  element.type = NUM, element.value = 48.;  // 48
  push(&true_res, element);

  element.type = NUM, element.value = 4.;  // 4
  push(&true_res, element);

  stack *output = sort(expression, x_value, &error);
  ck_assert_int_eq(compare_stack(output, true_res), OK);
  ck_assert_int_eq(error, OK);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_sort_16) {
  int error = OK;
  char expression[10] = "4+x";
  long double x_value = 48.;

  stack *output = sort(expression, x_value, &error);
  ck_assert_int_eq(error, OK);

  struct_token element = pop(&output);
  ck_assert_ldouble_eq(element.value, 4.);

  element = pop(&output);
  ck_assert_ldouble_eq(element.value, 48.);

  element = pop(&output);
  ck_assert_int_eq(element.type, ADD);

  if (output) clean_stack(&output);
}
END_TEST

START_TEST(test_sort_17) {
  char *expression = ",2349";
  char exp_result[10] = ",2349";

  ck_assert_int_eq(change_math_symbols(&expression), DOT);
  ck_assert_str_eq(expression, exp_result);
}
END_TEST

START_TEST(test_sort_18) {
  int error = OK;
  char *input = "π+2349+π*π/3-π";
  char *math_str = calloc(30, sizeof(char));
  char *result = "P+2349+P*P/3-P";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_19) {
  int error = OK;
  char *input = "46-5/4,6+2349**2*π/3-943.54**sin(x)";
  char *math_str = calloc(50, sizeof(char));
  char *result = "46-5/4.6+2349^2*P/3-943.54^sin(x)";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_20) {
  int error = OK;
  char *input = "46-5/4.6÷2349**2*P/3-943.54÷6÷sin(4.5)";
  char *math_str = calloc(50, sizeof(char));
  char *result = "46-5/4.6/2349^2*P/3-943.54/6/sin(4.5)";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_21) {
  int error = OK;
  char *input = "46-5/4.6×2349**2*P/3-943.54÷6÷sin(4.5×3)";
  char *math_str = calloc(70, sizeof(char));
  char *result = "46-5/4.6*2349^2*P/3-943.54/6/sin(4.5*3)";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_22) {
  int error = OK;
  char *input = "18-sin(x·5)-√(24)";
  char *math_str = calloc(30, sizeof(char));
  char *result = "18-sin(x*5)-#(24)";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_23) {
  int error = OK;
  char *input = "18-sin(x↑5)-√(24↑3)";
  char *math_str = calloc(30, sizeof(char));
  char *result = "18-sin(x^5)-#(24^3)";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_24) {
  int error = OK;
  char *input = "11+44*****(x↑5)-√(24↑3)%54";
  char *math_str = calloc(40, sizeof(char));
  char *result = "11+44^^*(x^5)-#(24^3)%54";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_25) {
  int error = OK;
  char *input = "";
  char *math_str = calloc(40, sizeof(char));
  char *result = "";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_26) {
  int error = OK;
  char *input = "\n\n\n\n\t.,,,,,,";
  char *math_str = calloc(40, sizeof(char));
  char *result = "\n\n\n\n\t.......";

  create_math_string(input, math_str);
  ck_assert_str_eq(math_str, result);
  ck_assert_int_eq(error, OK);
  if (math_str) free(math_str);
}
END_TEST

START_TEST(test_sort_27) {
  int error = OK;
  char expression[50] = "2↑↑**↑3";

  sort(expression, X_SORT, &error);
  ck_assert_int_eq(error, SORT_ERROR);
}
END_TEST

Suite *test_sort(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST SORT=-\033[0m");
  TCase *tc = tcase_create("s21_test_sort_tc");

  tcase_add_test(tc, test_sort_1);
  tcase_add_test(tc, test_sort_2);
  tcase_add_test(tc, test_sort_3);
  tcase_add_test(tc, test_sort_4);
  tcase_add_test(tc, test_sort_5);
  tcase_add_test(tc, test_sort_6);
  tcase_add_test(tc, test_sort_7);
  tcase_add_test(tc, test_sort_8);
  tcase_add_test(tc, test_sort_9);
  tcase_add_test(tc, test_sort_10);
  tcase_add_test(tc, test_sort_11);
  tcase_add_test(tc, test_sort_12);
  tcase_add_test(tc, test_sort_13);
  tcase_add_test(tc, test_sort_14);
  tcase_add_test(tc, test_sort_15);
  tcase_add_test(tc, test_sort_16);
  tcase_add_test(tc, test_sort_17);
  tcase_add_test(tc, test_sort_18);
  tcase_add_test(tc, test_sort_19);
  tcase_add_test(tc, test_sort_20);
  tcase_add_test(tc, test_sort_21);
  tcase_add_test(tc, test_sort_22);
  tcase_add_test(tc, test_sort_23);
  tcase_add_test(tc, test_sort_24);
  tcase_add_test(tc, test_sort_25);
  tcase_add_test(tc, test_sort_26);
  tcase_add_test(tc, test_sort_27);

  suite_add_tcase(s, tc);
  return s;
}
