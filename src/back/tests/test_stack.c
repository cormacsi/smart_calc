#include "test_me.h"

START_TEST(test_stack_1) {
  stack *last = NULL;
  ck_assert_int_eq(peek_type(NULL), STACK_ERROR);
  ck_assert_int_eq(peek_type(last), STACK_ERROR);
}
END_TEST

START_TEST(test_stack_2) {
  struct_token element;
  element.type = 0., element.value = 0.;
  push(NULL, element);
}
END_TEST

START_TEST(test_stack_3) {
  stack *last = NULL;
  pop(&last);
  pop(NULL);
}
END_TEST

START_TEST(test_stack_4) {
  stack *result = NULL;
  struct_token element;

  element.type = DIV, element.value = 0.;  // -
  push(&result, element);

  if (result) clean_stack(&result);
}
END_TEST

START_TEST(test_stack_5) {
  stack *result = NULL;
  struct_token element;

  element.type = DIV, element.value = 0.;  // -
  push(&result, element);

  element.type = NUM, element.value = 0.;  // 0
  push(&result, element);

  pop(&result);
  pop(&result);
  pop(&result);
  pop(&result);
  if (result) clean_stack(&result);
}
END_TEST

START_TEST(test_stack_6) {
  struct_token element;
  element.type = DIV, element.value = 0.;
  push(NULL, element);
}
END_TEST

START_TEST(test_stack_7) {
  stack *result = NULL;
  struct_token element;

  element.type = DIV, element.value = 0.;
  push(&result, element);

  int type = peek_type(result);
  ck_assert_int_eq(type, DIV);

  if (result) clean_stack(&result);
}
END_TEST

START_TEST(test_stack_8) {
  stack *result = NULL;

  int type = peek_type(result);
  ck_assert_int_eq(type, STACK_ERROR);

  type = peek_type(NULL);
  ck_assert_int_eq(type, STACK_ERROR);
}
END_TEST

START_TEST(test_stack_9) {
  stack *result = NULL;
  struct_token element;

  for (int i = 0; i < 22; i++) {
    element.type = i, element.value = 0.;
    push(&result, element);
  }

  int sum = count_tockens(result);
  ck_assert_int_eq(sum, 22);

  if (result) clean_stack(&result);
}
END_TEST

START_TEST(test_stack_10) {
  stack *result = NULL;
  struct_token element;

  for (int i = 0; i < 15; i++) {
    element.type = i, element.value = 0.;
    push(&result, element);
  }

  result = next_stack(result);
  ck_assert_int_eq(result->token.type, 13);

  clean_stack(&result);
}
END_TEST

START_TEST(test_stack_11) {
  stack *result = NULL;
  struct_token element;

  for (int i = 0; i < 15; i++) {
    element.type = i, element.value = 0.;
    push(&result, element);
  }

  result = flip_over(result);
  for (int i = 0; i < 15; i++) {
    element = pop(&result);
    ck_assert_int_eq(element.type, i);
  }

  if (result) clean_stack(&result);
}
END_TEST

START_TEST(test_stack_12) {
  stack *one = NULL;
  stack *two = NULL;
  struct_token element;

  for (int i = 0; i < 150; i++) {
    element.type = i, element.value = 0.;
    push(&one, element);
    push(&two, element);
  }

  one = flip_over(one);
  two = flip_over(two);

  for (int i = 0; i < 150; i++) {
    struct_token element_one = pop(&one);
    struct_token element_two = pop(&two);
    ck_assert_int_eq(element_one.type, element_two.type);
  }

  if (one) clean_stack(&one);
  if (two) clean_stack(&two);
}
END_TEST

START_TEST(test_stack_13) {
  stack *one = NULL;
  stack *two = NULL;
  struct_token element;

  for (int i = 0; i < 15; i++) {
    element.type = i, element.value = 0.;
    push(&one, element);
    push(&two, element);
  }

  one = flip_over(one);
  two = flip_over(two);

  ck_assert_int_eq(compare_stack(one, two), OK);

  for (int i = 0; i < 7; i++) {
    struct_token element_one = pop(&one);
    struct_token element_two = pop(&two);
    ck_assert_int_eq(element_one.type, element_two.type);
  }
  pop(&one);
  ck_assert_int_eq(compare_stack(one, two), STACK_ERROR);

  if (one) clean_stack(&one);
  if (two) clean_stack(&two);
}
END_TEST

START_TEST(test_stack_14) {
  int error = OK;
  char expression[260] = "4+5-3/7*2";
  stack *true_res = NULL;
  struct_token element;  // 4 5 + 3 7 / 2 * -

  element.type = DIV, element.value = 0.;  // -
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
  ck_assert_int_eq(compare_stack(output, true_res), ERROR);
  ck_assert_int_eq(error, OK);

  output = flip_over(output);
  pop(&output);
  element.type = ADD, element.value = 0.;  // /
  push(&output, element);
  output = flip_over(output);
  ck_assert_int_eq(compare_stack(output, true_res), ERROR);

  true_res = flip_over(true_res);
  pop(&true_res);
  pop(&true_res);
  pop(&true_res);
  true_res = flip_over(true_res);
  ck_assert_int_eq(compare_stack(output, true_res), STACK_ERROR);

  if (output) clean_stack(&output);
  if (true_res) clean_stack(&true_res);
}
END_TEST

START_TEST(test_stack_15) {
  stack *one = NULL;
  stack *two = NULL;
  struct_token element;

  for (int i = 0; i < 15; i++) {
    element.type = i, element.value = 0.;
    push(&one, element);
    if (i == 0) element.value = 6.;
    push(&two, element);
  }

  ck_assert_int_eq(compare_stack(one, two), ERROR);

  if (one) clean_stack(&one);
  if (two) clean_stack(&two);
}
END_TEST

START_TEST(test_stack_16) {
  stack *one = NULL;
  stack *two = NULL;
  struct_token element;

  for (int i = 0; i < 15; i++) {
    element.type = i, element.value = 0.;
    if (i != 1) push(&one, element);
    push(&two, element);
  }

  ck_assert_int_eq(compare_stack(one, two), STACK_ERROR);

  if (one) clean_stack(&one);
  if (two) clean_stack(&two);
}
END_TEST

Suite *test_stack(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST STACK=-\033[0m");
  TCase *tc = tcase_create("s21_test_stack_tc");

  tcase_add_test(tc, test_stack_1);
  tcase_add_test(tc, test_stack_2);
  tcase_add_test(tc, test_stack_3);
  tcase_add_test(tc, test_stack_4);
  tcase_add_test(tc, test_stack_5);
  tcase_add_test(tc, test_stack_6);
  tcase_add_test(tc, test_stack_7);
  tcase_add_test(tc, test_stack_8);
  tcase_add_test(tc, test_stack_9);
  tcase_add_test(tc, test_stack_10);
  tcase_add_test(tc, test_stack_11);
  tcase_add_test(tc, test_stack_12);
  tcase_add_test(tc, test_stack_13);
  tcase_add_test(tc, test_stack_14);
  tcase_add_test(tc, test_stack_15);
  tcase_add_test(tc, test_stack_16);

  suite_add_tcase(s, tc);
  return s;
}
