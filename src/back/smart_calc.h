/**
 * @file smart_calc.h
 * @author cormacsi
 * @brief Header file for Smart Calculator
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_MAIN_H
#define SRC_BACK_MAIN_H

#include <ctype.h>

#include "calculation.h"
#include "sort.h"
#include "stack.h"

/**
 * @addtogroup SmartCalc
 * @{
 */

/**
 * @brief String of enumeration of white spaces
 *
 */
#define SPACE " \n\t\v\f\r"

/**
 * @brief String of valid characters
 *
 */
#define SYMBOLS \
  "0123456789.,()+-*×·/÷^xmodsincotalgqrXMODSINCOTALGQR√↑π% \n\t\v\f\r"

/**
 * @brief Checks the validity of the current character
 *
 * @param a Current character in the input string
 * @return true Is other symol
 * @return false The symbol is valid
 */
bool is_other_symbols(char a);

/**
 * @brief Checks the correctness of the entered string
 *
 * @param input The input string
 * @return true Valid string
 * @return false Invalid string
 */
bool not_valid(char *input);

/**
 * @brief Cleans the input string from white spaces
 *
 * @param input The input string
 */
void clean_string(char *input);

/**
 * @brief Performs the string validation process
 *
 * @param input The input string
 * @return 0 No error / the string is valid
 * @return int Error type
 */
int check_input(char *input);

/**
 * @brief The main function of the calculator
 *
 * @param input The input string with mathematical expression
 * @param x_str The input string with x statement
 * @param error A pointer to the type of error value
 * @return long double Result value
 */
long double smart_calc(char *input, char *x_str, int *error);

/**
 * @brief Сalculates the values for plotting the function
 *
 * @param input The input string with mathematical expression
 * @param x Double X value
 * @param error A pointer to the type of error value
 * @return long double Result value
 */
long double graph_only(char *input, double x, int *error);

/**
 * @}
 *
 */

#endif  // SRC_BACK_MAIN_H
