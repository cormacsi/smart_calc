/**
 * @file sort.h
 * @author cormacsi
 * @brief Header file for sort
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_SORT_H
#define SRC_BACK_SORT_H

#include <string.h>

#include "stack.h"
#include "yard.h"

/**
 * @brief Defines the pi symbol for RPN
 *
 */
#define PI_LET 'P'

/**
 * @brief Defines the value of pi if it is not stated in the mathematical
 * library of some compilers
 *
 */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Defines valid character values for numbers including pi
 *
 */
#define NUMBERS "0123456789.P"

/**
 * @brief Defines all the valid input of operations
 *
 */
#define OPERATIONS "()+-*/^"

/**
 * @brief Defines all the valid input of functions
 *
 */
#define FUNCTIONS "modsincotalgsqr#%"

/**
 * @brief Defines the true value for function if the result id found
 *
 */
#define FOUND 1

/**
 * @addtogroup Sort
 * @{
 */

/**
 * @brief Gets the function type object
 *
 * @param input A pointer to the input string
 * @param type A pointer to the type value
 * @return int Error type
 */
int get_function_type(char **input, int *type);

/**
 * @brief Gets the operation type object
 *
 * @param input A pointer to the input string
 * @param token A pointer to the tocken structure
 * @param x The x value
 * @return int Error type
 */
int get_operation_type(char **input, struct_token *token, long double x);

/**
 * @brief Gets the tokens type
 *
 * @param input The input string
 * @param input_last A pointer to the stack structure
 * @param x The x value
 * @return int Error type
 */
int get_tokens(char *input, stack **input_last, long double x);

/**
 * @brief Changes the current char if it is a wide char
 *
 * @param k A pointer to the input string
 * @return char Identical operation value as an ascii char
 */
char change_math_symbols(char **k);

/**
 * @brief Create a math string object
 *
 * @param input The input string
 * @param math_str The result string
 */
void create_math_string(char *input, char *math_str);

/**
 * @brief The second most important function is sorting the string into tokens
 *
 * @param input The input string
 * @param x_value The x value
 * @param error A pointer to the error type
 * @return stack* The result of parsing the input string into tockens
 */
stack *sort(char *input, double x_value, int *error);

/**
 * @}
 *
 */

#endif  // SRC_BACK_SORT_H
