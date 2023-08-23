/**
 * @file smart_calc.c
 * @author cormacsi
 * @brief Smart Calculator main and auxiliary functions
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "smart_calc.h"

/**
 * The function returns false if the symol is valid,
 * otherwise true (if the symbol is not in the validator string).
 */
bool is_other_symbols(char a) { return !strchr(SYMBOLS, a); }

/**
 * Returns true if the string contains invalid characters.
 */
bool not_valid(char *input) {
  int result = OK;
  for (int i = 0; !result && input[i]; i++) {
    if (is_other_symbols(input[i])) {
      result = ERROR;
    }
  }
  return result;
}

/**
 * Checks the content of white characters in the string and clears them.
 */
void clean_string(char *input) {
  int i = 0;
  for (int k = 0; input[k] != 0; i++) {
    while (strchr(SPACE, input[k])) {
      k++;
      if (input[k] == 0) break;
    }
    input[i] = tolower(input[k]);
    if (input[k] != 0) k++;
  }
  input[i] = 0;
}

/**
 * Starts the checking process of characters in the input string.
 */
int check_input(char *input) {
  int result = OK;
  if (strlen(input) < 1 || strlen(input) > MAX_SIZE) {
    result = SIZE_ERROR;

  } else if (not_valid(input)) {
    result = INPUT_ERROR;
  }
  if (!result) clean_string(input);
  return result;
}

/**
 * Takes a string of a mathematical function and converts it to the final value.
 * If the value x is present in the string, the x_str is used in the calculation
 * process. If an error was found in a mathematical expression at any stage ,
 * then the error type is placed in its value.
 */
long double smart_calc(char *input, char *x_str, int *error) {
  long double result = 0., x_value = 0.;
  *error = check_input(input);

  char *math_str = calloc(400, sizeof(char));
  create_math_string(input, math_str);

  if (!(*error) && strchr(input, 'x')) {
    if (!strchr(x_str, 'x')) {
      x_value = smart_calc(x_str, "", error);
    } else {
      *error = INPUT_ERROR;
    }
  }

  if (!(*error)) {
    stack *output = sort(math_str, x_value, error);
    if (!(*error)) {
      result = calculation(&output, error);
    }
  }
  free(math_str);
  return result;
}

/**
 * Takes the value of a mathematical expression and double x and returns the y
 * value used to plot the function.
 */
long double graph_only(char *input, double x, int *error) {
  long double result = 0.;

  stack *output = sort(input, x, error);
  if (!(*error)) {
    result = calculation(&output, error);
  }
  return result;
}
