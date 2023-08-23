#include "test_me.h"

START_TEST(test_yard_1) {
  int error = OK;
  stack *yard_test = NULL;
  struct_token element;

  element.type = 96, element.value = 0.;  // error: type 96
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // +
  push(&yard_test, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(error, YARD_ERROR);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_yard_2) {
  int error = OK;
  stack *yard_test = NULL;  // 1 6 * )
  struct_token element;

  element.type = CL_BR, element.value = 0.;  // error:
  push(&yard_test, element);

  element.type = MUL, element.value = 0.;  // error:
  push(&yard_test, element);

  element.type = NUM, element.value = 6.;  // *
  push(&yard_test, element);

  element.type = NUM, element.value = 1.;  // +
  push(&yard_test, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(error, YARD_ERROR);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_yard_3) {
  int error = OK;
  stack *yard_test = NULL;
  struct_token element;

  element.type = NUM, element.value = 5.;  // 5
  push(&yard_test, element);

  element.type = 96, element.value = 0.;  // error: type 96
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // +
  push(&yard_test, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(error, YARD_ERROR);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_yard_4) {
  int error = OK;
  stack *yard_test = NULL;
  struct_token element;

  element.type = NUM, element.value = 5.;  // 5
  push(&yard_test, element);

  element.type = -100, element.value = 0.;  // error: type -100
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // +
  push(&yard_test, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(error, YARD_ERROR);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_yard_5) {
  int error = OK;
  stack *yard_test = NULL;  // (tan(pi / 2 + 1)+ cos(6))
  struct_token element;

  element.type = CL_BR, element.value = 0.;  // )
  push(&yard_test, element);

  element.type = CL_BR, element.value = 0.;  // )
  push(&yard_test, element);

  element.type = NUM, element.value = 6.;  // 6
  push(&yard_test, element);

  element.type = COS, element.value = 0.;  // cos
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // +
  push(&yard_test, element);

  element.type = CL_BR, element.value = 0.;  // )
  push(&yard_test, element);

  element.type = NUM, element.value = 1.;  // 1
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // +
  push(&yard_test, element);

  element.type = NUM, element.value = M_PI / 2.;  // pi / 2
  push(&yard_test, element);

  element.type = TAN, element.value = 0.;  // tan
  push(&yard_test, element);

  element.type = OP_BR, element.value = 0.;  // (
  push(&yard_test, element);

  stack *true_result = NULL;  // pi 1 + tan 6 cos +

  element.type = NUM, element.value = M_PI / 2;  // pi / 2
  push(&true_result, element);

  element.type = NUM, element.value = 1.;  // 1
  push(&true_result, element);

  element.type = ADD, element.value = 0.;  // +
  push(&true_result, element);

  element.type = TAN, element.value = 0.;  // tan
  push(&true_result, element);

  element.type = NUM, element.value = 6.;  // 6
  push(&true_result, element);

  element.type = COS, element.value = 0.;  // cos
  push(&true_result, element);

  element.type = ADD, element.value = 0.;  // +
  push(&true_result, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(compare_stack(result, true_result), 0.);
  ck_assert_int_eq(error, OK);

  if (result) clean_stack(&result);
  if (true_result) clean_stack(&true_result);
}
END_TEST

START_TEST(test_yard_6) {
  int error = OK;
  stack *yard_test = NULL;  // 6 ^ 2 ^ 3 ^ 4
  struct_token element;

  element.type = NUM, element.value = 4.;  // 4
  push(&yard_test, element);

  element.type = POW, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = NUM, element.value = 3.;  // 3
  push(&yard_test, element);

  element.type = POW, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = NUM, element.value = 2.;  // 2
  push(&yard_test, element);

  element.type = POW, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = NUM, element.value = 6.;  // 6
  push(&yard_test, element);

  stack *true_result = NULL;  // 6 2 3 4 ^ ^ ^

  element.type = NUM, element.value = 6.;  // 6
  push(&true_result, element);

  element.type = NUM, element.value = 2.;  // 2
  push(&true_result, element);

  element.type = NUM, element.value = 3.;  // 3
  push(&true_result, element);

  element.type = NUM, element.value = 4.;  // 4
  push(&true_result, element);

  element.type = POW, element.value = 0.;  // pow
  push(&true_result, element);

  element.type = POW, element.value = 0.;  // pow
  push(&true_result, element);

  element.type = POW, element.value = 0.;  // pow
  push(&true_result, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(compare_stack(result, true_result), 0.);
  ck_assert_int_eq(error, OK);

  if (result) clean_stack(&result);
  if (true_result) clean_stack(&true_result);
}
END_TEST

START_TEST(test_yard_7) {
  int error = OK;
  stack *yard_test = NULL;  // 6 + - + 8
  struct_token element;

  element.type = NUM, element.value = 8.;  // 4
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = SUB, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = ADD, element.value = 0.;  // pow
  push(&yard_test, element);

  element.type = NUM, element.value = 6.;  // 6
  push(&yard_test, element);

  stack *true_result = NULL;  // 6 8 + - +

  element.type = NUM, element.value = 6.;  // 6
  push(&true_result, element);

  element.type = NUM, element.value = 8.;  // 8
  push(&true_result, element);

  element.type = UP, element.value = 0.;  // pow
  push(&true_result, element);

  element.type = UM, element.value = 0.;  // pow
  push(&true_result, element);

  element.type = ADD, element.value = 0.;  // +
  push(&true_result, element);

  stack *result = shunting_yard(yard_test, &error);
  ck_assert_int_eq(compare_stack(result, true_result), 0.);
  ck_assert_int_eq(error, OK);

  if (result) clean_stack(&result);
  if (true_result) clean_stack(&true_result);
}
END_TEST

START_TEST(test_yard_8) {
  ck_assert_int_eq(is_priority(OP_BR, TAN), 0);
  ck_assert_int_eq(is_priority(SIN, TAN), 0);
}
END_TEST

START_TEST(test_yard_9) {
  ck_assert_int_eq(is_priority(POW, POW), 0);
  ck_assert_int_eq(is_priority(UM, UP), 0);
}
END_TEST

START_TEST(test_yard_10) {
  ck_assert_int_eq(is_priority(MOD, DIV), 1);
  ck_assert_int_eq(is_priority(DIV, MUL), 1);
}
END_TEST

Suite *test_yard(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST YARD=-\033[0m");
  TCase *tc = tcase_create("s21_test_yard_tc");

  tcase_add_test(tc, test_yard_1);
  tcase_add_test(tc, test_yard_2);
  tcase_add_test(tc, test_yard_3);
  tcase_add_test(tc, test_yard_4);
  tcase_add_test(tc, test_yard_5);
  tcase_add_test(tc, test_yard_6);
  tcase_add_test(tc, test_yard_7);
  tcase_add_test(tc, test_yard_8);
  tcase_add_test(tc, test_yard_9);
  tcase_add_test(tc, test_yard_10);

  suite_add_tcase(s, tc);
  return s;
}
