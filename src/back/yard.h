/**
 * @file yard.h
 * @author cormacsi
 * @brief Header file for Shunting yard
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_YARD_H
#define SRC_BACK_YARD_H

#include "stack.h"

/**
 * @addtogroup Shunting-yard
 * @{
 */

/**
 * @brief Implementation of the shunting yard algorithm
 *
 * @param input Infix input stack
 * @param error Error type
 * @return stack* RPN output stack
 */
stack *shunting_yard(stack *input, int *error);

/**
 * @brief Checks whether the last operation type contains open bracket
 *
 * @param carrier The carrier stack
 * @return true Contains open bracket
 * @return false Does not caontain open bracket
 */
bool not_open_bracket(stack *carrier);

/**
 * @brief Checks whether the token type is an operation
 *
 * @param n Tocken type
 * @return true
 * @return false
 */
bool is_operation(int n);

/**
 * @brief Checks whether the token type is a function
 *
 * @param n Tocken type
 * @return true
 * @return false
 */
bool is_function(int n);

/**
 * @brief Changes the operation type to unary
 *
 * @param type Addition or subtraction operation type
 * @return int Type of unary token
 */
int change_to_unar(int type);

/**
 * @brief Checks the priority between two operation types
 *
 * @param carrier The first operation type to compare
 * @param input The second operation type to compare
 * @return true The first operation type has priority
 * @return false The second operation type has priority
 */
bool is_priority(int carrier, int input);

/**
 * @brief Checks the equality of the priority of the operation type
 *
 * @param oper
 * @return true
 * @return false
 */
bool equal_priority(int oper);

/**
 * @brief Gets the operation type
 *
 * @param oper Operation value
 * @return int Operation type
 */
int priority(int oper);

/**
 * @}
 *
 */

#endif  // SRC_BACK_YARD_H
