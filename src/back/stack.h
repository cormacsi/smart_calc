/**
 * @file stack.h
 * @author cormacsi
 * @brief Header file for stack
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_STACK_H
#define SRC_BACK_STACK_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The maximum size of the input string
 *
 */
#define MAX_SIZE 255

/**
 * @brief The possible error types
 *
 */
enum errors {
  OK,
  ERROR,
  SIZE_ERROR,
  INPUT_ERROR,
  SYMBOL_ERROR,
  SORT_ERROR,
  YARD_ERROR,
  CALCULATION_ERROR,
  STACK_ERROR,
  GRAPH_ERROR
};

/**
 * @brief The types of possible operations
 * including open and close brackets
 */
enum operation {
  OP_BR = 40,
  CL_BR,
  MUL,
  ADD,
  COMA,
  SUB,
  DOT,
  DIV,
  MOD,
  POW = 94
};

/**
 * @brief The types of possible functions
 * including x and unary addition and subtraction operations
 */
enum function {
  X = 9,
  NUM,
  SIN,
  COS,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  UM = 126,
  UP = 22
};

/**
 * @brief The tocken structure
 *
 */
typedef struct token_d {
  int type;
  long double value;
} struct_token;

/**
 * @brief The stack structure
 *
 */
typedef struct stack_d {
  struct_token token;
  struct stack_d *prev;
} stack;

/**
 * @addtogroup Stack
 * @{
 */

/**
 * @brief Pushes the element to the stack
 *
 * @param last A pointer to the last element in the stack
 * @param element The element to add to the stack
 */
void push(stack **last, struct_token element);

/**
 * @brief Pops the last element from the stack
 *
 * @param last A pointer to the last element in the stack
 * @return struct_token The last element to return
 */
struct_token pop(stack **last);

/**
 * @brief Gets the last tocken's type
 *
 * @param last The stack
 * @return int The type value of the last tocken
 */
int peek_type(stack *last);

/**
 * @brief Frees the stack
 *
 * @param result A pointer to the last element in the stack
 */
void clean_stack(stack **result);

/**
 * @brief Auxiliary function to compare two stacks
 *
 * @param first The first stack to compare
 * @param second The second stack to compare
 * @return 0 Stacks are identical
 * @return int Error type
 */
int compare_stack(stack *first, stack *second);

/**
 * @brief Counts tockens in the stack
 *
 * @param last The stack
 * @return int Integer value of the size of stack
 */
int count_tockens(stack *last);

/**
 * @brief Gets the last element in the stack
 *
 * @param last The stack
 * @return stack* The last element in the stack to return
 */
stack *next_stack(stack *last);

/**
 * @brief Flips the stack
 *
 * @param last The input stack
 * @return stack* A new stack to return
 */
stack *flip_over(stack *last);

/**
 * @}
 *
 */

#endif  // SRC_BACK_STACK_H
