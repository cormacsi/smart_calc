/**
 * @file calculation.c
 * @author cormacsi
 * @brief Calculation function and auxiliary functions
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "calculation.h"

/**
 * The calculation is one of the main functions and the last step to determining
 * the final value.
 */
long double calculation(stack **output, int *error) {
  long double result = 0.;
  stack *numbers = NULL;
  while (*output && !(*error)) {
    struct_token operand = pop(output);
    if (operand.type == NUM) {
      push(&numbers, operand);
    } else if (numbers) {
      if (numbers->prev && !leftside(priority(operand.type))) {
        make_operation(operand.type, &numbers);
      } else if (leftside(priority(operand.type))) {
        make_function(operand.type, &numbers);
      } else {
        *error = CALCULATION_ERROR;
      }
    } else {
      *error = CALCULATION_ERROR;
    }
  }
  if (count_tockens(numbers) == 1 && !(*error)) {
    struct_token last_number = pop(&numbers);
    result = last_number.value;
  } else {
    clean_stack(&numbers);
    clean_stack(output);
    *error = CALCULATION_ERROR;
    result = 0.;
  }
  return result;
}

/**
 * Checks whether the input type of operand's priority is left associative.
 */
bool leftside(int oper) { return oper == 0 || oper == 4; }

/**
 * The function takes the type value of the function and performs the
 * calculation.
 */
void make_function(int operand, stack **numbers) {
  struct_token first_num = pop(numbers);
  if (operand == UM) {
    first_num.value *= -1.;
  } else if (operand == SIN) {
    first_num.value = sinl(first_num.value);
  } else if (operand == COS) {
    first_num.value = cosl(first_num.value);
  } else if (operand == TAN) {
    first_num.value = tanl(first_num.value);
  } else if (operand == ASIN) {
    first_num.value = asinl(first_num.value);
  } else if (operand == ACOS) {
    first_num.value = acosl(first_num.value);
  } else if (operand == ATAN) {
    first_num.value = atanl(first_num.value);
  } else if (operand == LN) {  // natural logarithm
    first_num.value = logl(first_num.value);
  } else if (operand == LOG) {  // decimal logarithm
    first_num.value = log10l(first_num.value);
  } else if (operand == SQRT) {
    first_num.value = sqrtl(first_num.value);
  }
  push(numbers, first_num);
}

/**
 * The function takes the type value of the operator and performs the
 * calculation.
 */
void make_operation(int operand, stack **numbers) {
  struct_token first_num = pop(numbers);
  struct_token second_num = pop(numbers);
  if (operand == MUL) {
    second_num.value *= first_num.value;
  } else if (operand == DIV) {
    second_num.value /= first_num.value;
  } else if (operand == SUB) {
    second_num.value -= first_num.value;
  } else if (operand == ADD) {
    second_num.value += first_num.value;
  } else if (operand == POW) {
    second_num.value = pow(second_num.value, first_num.value);
  } else {  // if (operand == MOD)
    second_num.value = fmodl(second_num.value, first_num.value);
  }
  push(numbers, second_num);
}
