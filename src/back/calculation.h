/**
 * @file calculation.h
 * @author cormacsi
 * @brief Header file for calculation
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_CALCULATION_H
#define SRC_BACK_CALCULATION_H

#include "yard.h"

/**
 * @addtogroup Calculation
 * @{
 */

/**
 * @brief Calculation function
 *
 * @param output A pointer to input stack
 * @param error A pointer to the error value
 * @return long double Calculation result
 */
long double calculation(stack **output, int *error);

/**
 * @brief Auxiliary function for determining the left-hand associativity of the
 * operator
 *
 * @param oper Input value of the operator priority group
 * @return true
 * @return false
 */
bool leftside(int oper);

/**
 * @brief Performs calculation of functions and unary operations
 *
 * @param operand Input value of operand type
 * @param numbers A pointer to stack with numbers to read the last value and
 * rewrite a new value
 */
void make_function(int operand, stack **numbers);

/**
 * @brief Performs calculation of operations
 *
 * @param operand Input value of operand type
 * @param numbers A pointer to stack with numbers to read the last value and
 * rewrite a new value
 */
void make_operation(int operand, stack **numbers);

/**
 * @}
 *
 */

#endif  // SRC_BACK_CALCULATION_H
