/**
 * @file yard.c
 * @author cormacsi
 * @brief Shunting-yard algorithm and auxiliary functions
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "yard.h"

/**
 * One of the main functions in the calculator.
 * Implements the Edsger Dijkstra's method (better known
 * as the shunting-yard algorithm) to convert expressions
 * from infix to Reverse Polish notation.
 */
stack *shunting_yard(stack *input, int *error) {
  stack *output = NULL;
  stack *carrier = NULL;
  int count_br = 0;
  bool unar_flag = 1;
  while (input && !(*error)) {
    if (input->token.type == NUM) {
      push(&output, input->token);
      unar_flag = 0;
    } else if (input->token.type == OP_BR || is_function(input->token.type)) {
      push(&carrier, input->token);
      unar_flag = 1;
      count_br += 1;
    } else if (input->token.type == CL_BR) {
      count_br -= 1;
      while (carrier && not_open_bracket(carrier)) {
        push(&output, pop(&carrier));
      }
      if (peek_type(carrier) == OP_BR) {
        carrier = next_stack(carrier);
      } else if (is_function(peek_type(carrier))) {
        push(&output, pop(&carrier));
      } else {
        *error = YARD_ERROR;
        break;
      }
      unar_flag = 0;
    } else if (is_operation(input->token.type)) {
      if (unar_flag) input->token.type = change_to_unar(input->token.type);
      while (carrier && is_priority(peek_type(carrier), input->token.type)) {
        push(&output, pop(&carrier));
      }
      push(&carrier, input->token);
      unar_flag = 1;
    } else {
      *error = YARD_ERROR;
    }
    if (!(*error)) input = next_stack(input);
  }
  if (count_br != 0) {
    *error = YARD_ERROR;
  } else {
    while (carrier) {
      push(&output, carrier->token);
      carrier = next_stack(carrier);
    }
  }
  if (*error) {
    if (output) clean_stack(&output);
    if (carrier) clean_stack(&carrier);
    if (input) clean_stack(&input);
  }
  return output;
}

/**
 * Return true if the last operation type contains open bracket.
 */
bool not_open_bracket(stack *carrier) {
  return peek_type(carrier) != OP_BR && !is_function(peek_type(carrier));
}

/**
 * Returns true if the input tocken type is an operation.
 */
bool is_operation(int n) { return (n >= 42 && n <= 48) || n == 94; }

/**
 * Returns true if the input tocken type is a function.
 */
bool is_function(int n) { return n > 10 && n < 20; }

/**
 * Gets the addition or subtraction operation type and
 * returns the corresponding unary operation type.
 */
int change_to_unar(int type) {
  if (type == SUB)
    type = UM;
  else if (type == ADD)
    type = UP;
  return type;
}

/**
 * Gets two operation types as an input and checks its priority.
 * Returns true if the carrier has priority.
 */
bool is_priority(int carrier, int input) {
  bool result = false;
  carrier = priority(carrier);
  input = priority(input);
  if (carrier > input)
    result = true;
  else if (input == carrier && !equal_priority(input))
    result = true;
  return result;
}

/**
 * Returns true if the operation type priority is equal.
 */
bool equal_priority(int oper) { return oper == 0 || oper == 3 || oper == 4; }

/**
 * The function gets the value of the operation and returns its priority type.
 */
int priority(int oper) {
  if (oper == OP_BR || is_function(oper))
    oper = 0;
  else if (oper == SUB || oper == ADD)
    oper = 1;
  else if (oper == DIV || oper == MUL || oper == MOD)
    oper = 2;
  else if (oper == POW)
    oper = 3;
  else
    oper = 4;  // if (oper == UM || oper == UP)
  return oper;
}
