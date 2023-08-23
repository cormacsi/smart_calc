/**
 * @file stack.c
 * @author cormacsi
 * @brief Stack operations functions
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stack.h"

/**
 * Adds a new element to the stack.
 */
void push(stack **last, struct_token element) {
  if (last) {
    stack *tmp = (stack *)calloc(1, sizeof(stack));
    tmp->token = element;
    if ((*last) == NULL) {
      tmp->prev = NULL;
      *last = tmp;
    } else {
      tmp->prev = *last;
      *last = tmp;
    }
  }
}

/**
 * Gets the last element and removes it from the stack.
 */
struct_token pop(stack **last) {
  struct_token element;
  if (last && *last) {
    stack *tmp = *last;
    element = tmp->token;
    *last = tmp->prev;
    free(tmp);
  } else {
    element.type = 0;
    element.value = 0;
  }
  return element;
}

/**
 * The function gets the last tocken's type without removing the element from
 * the stack.
 */
int peek_type(stack *last) {
  int result = 0;
  if (last)
    result = last->token.type;
  else
    result = STACK_ERROR;
  return result;
}

/**
 * The function alternately frees all the elements in the stack.
 */
void clean_stack(stack **result) {
  stack *last = *result;
  while (pop(&last).type)
    ;
  free(last);
  last = NULL;
  *result = last;
}

/**
 * The function compares every tocken's value and type
 * and returns error type if the discrepancy was discovered.
 */
int compare_stack(stack *first, stack *second) {
  int error = OK;
  while (first && second && !error) {
    if (first->token.type != second->token.type ||
        fabsl(first->token.value - second->token.value) > 1e-6) {
      error = ERROR;
    }
    first = first->prev;
    second = second->prev;
  }
  if (first || second) error = STACK_ERROR;
  return error;
}

/**
 * Recursive function to find the size of the stack.
 */
int count_tockens(stack *last) {
  int result = 0;
  if (last) result = 1 + count_tockens(last->prev);
  return result;
}

/**
 * The function returns the last stack structure and removes it from the stack.
 */
stack *next_stack(stack *last) {
  stack *tmp = last->prev;
  free(last);
  return tmp;
}

/**
 * The function goes through all the elements in the stack
 * and rewrites them in reverse order to the new stack.
 */
stack *flip_over(stack *last) {
  stack *reborn = NULL;
  while (last) {
    push(&reborn, last->token);
    stack *tmp = last->prev;
    free(last);
    last = tmp;
  }
  return reborn;
}

// void print_token(struct_token token) {
//   printf("--->\t");
//   printf("token is: %d\t", token.type);
//   printf("value is: %.18Lf\n", token.value);
// }

// void print_stack(stack *last) {
//   while (last) {
//     print_token(last->token);
//     last = last->prev;
//   }
// }
