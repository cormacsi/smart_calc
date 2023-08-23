/**
 * @file sort.c
 * @author cormacsi
 * @brief Sort operations and auxiliary functions
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sort.h"

/**
 * The function accepts a poiter to the input string, gets the type value
 * which is written to the pointer of the type value and moves the pointer
 * of the input string while the current char is a function type.
 */
int get_function_type(char **input, int *type) {
  int error = OK;
  if (**input == '%') {
    *type = MOD;
    *input += 1;
  } else if (!strncmp(*input, "mod", 3)) {
    *type = MOD;
    *input += 3;
  } else if (!strncmp(*input, "sin(", 4)) {
    *type = SIN;
    *input += 4;
  } else if (!strncmp(*input, "cos(", 4)) {
    *type = COS;
    *input += 4;
  } else if (!strncmp(*input, "tan(", 4)) {
    *type = TAN;
    *input += 4;
  } else if (!strncmp(*input, "asin(", 5)) {
    *type = ASIN;
    *input += 5;
  } else if (!strncmp(*input, "acos(", 5)) {
    *type = ACOS;
    *input += 5;
  } else if (!strncmp(*input, "atan(", 5)) {
    *type = ATAN;
    *input += 5;
  } else if (!strncmp(*input, "ln(", 3)) {
    *type = LN;
    *input += 3;
  } else if (!strncmp(*input, "log(", 4)) {
    *type = LOG;
    *input += 4;
  } else if (!strncmp(*input, "#(", 2)) {
    *type = SQRT;
    *input += 2;
  } else if (!strncmp(*input, "sqrt(", 5)) {
    *type = SQRT;
    *input += 5;
  } else
    error = SORT_ERROR;
  return error;
}

/**
 * The function accepts a poiter to the input string, gets the type of
 * the current operation including functions, numbers or x value.
 * If the x char is read in the input string, the token of the x number
 * is written in the stucture.
 */
int get_operation_type(char **input, struct_token *token, long double x) {
  int result = OK;
  token->type = 0, token->value = 0.;

  if (**input == 'x') {
    token->type = NUM;
    token->value = x;
    (*input)++;

  } else if (strchr(NUMBERS, **input)) {
    token->type = NUM;
    if (**input == PI_LET) {
      token->value = M_PI;
      (*input)++;
    } else {
      token->value = strtold(*input, input);
    }
  } else if (strchr(OPERATIONS, **input)) {
    token->type = **input;
    (*input)++;

  } else if (strchr(FUNCTIONS, **input)) {
    result = get_function_type(input, &(token->type));

  } else
    result = SORT_ERROR;
  return result;
}

/**
 * The function accepts the input stirng and starts the parsing process.
 */
int get_tokens(char *input, stack **input_last, long double x) {
  int error = OK;
  while (*input && !error) {
    struct_token token;
    if (!get_operation_type(&input, &token, x)) {
      push(input_last, token);
    } else {
      error = SORT_ERROR;
      clean_stack(input_last);
    }
  }
  return error;
}

/**
 * The function accepts a pointer to the input string and
 * checks the presence of wide symbols. If the wide char is found,
 * it moves the current string pointer and return an ascii char
 * (as an identical operation).
 */
char change_math_symbols(char **k) {
  char this = **k;
  char next = *((*k) + 1);
  if (this == COMA) {
    this = DOT;
  } else if (strchr("π", this)) {
    (*k)++;
    this = PI_LET;
  } else if (this == MUL && next == MUL) {
    (*k)++;
    this = POW;
  } else if (strchr("÷", next) && strchr("÷", this)) {
    (*k)++;
    this = DIV;
  } else if (strchr("×", next) && strchr("÷", this)) {
    (*k)++;
    this = MUL;
  } else if (strchr("÷", next) && strchr("·", this)) {
    (*k)++;
    this = MUL;
  } else if (strchr("↑", this)) {
    int check = 1;
    while (strchr("↑", *((*k) + 1))) {
      (*k)++;
      check++;
    }
    if (check == 3) {
      this = POW;
    } else if (strchr("↑", this) && strchr("√", this)) {
      (*k) += 2;
      this = '#';
    }
  }
  return this;
}

/**
 * The function creates a new sting with only ascii values to facilitate
 * parsing.
 */
void create_math_string(char *input, char *math_str) {
  for (int i = 0; *input; i++) {
    math_str[i] = change_math_symbols(&input);
    input++;
  }
  return;
}

/**
 * The function processes the input string,
 * translates it into more understandable tokens
 * and sends it to the shunting yard algorithm.
 * The result of this function is a fully processed
 * stack with reverse polish notation or an error type.
 */
stack *sort(char *input, double x_value, int *error) {
  stack *input_tokens = NULL;
  stack *output = NULL;

  *error = get_tokens(input, &input_tokens, x_value);
  if (!(*error)) {
    stack *input_yard = flip_over(input_tokens);

    stack *output_yard = shunting_yard(input_yard, error);
    if (!(*error)) output = flip_over(output_yard);
  }
  return output;
}
