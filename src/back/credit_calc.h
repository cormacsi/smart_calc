/**
 * @file credit_calc.h
 * @author cormacsi
 * @brief Header file for credit calculation
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_CREDIT_CALCULATOR_H
#define SRC_BACK_CREDIT_CALCULATOR_H

#include <math.h>

/**
 * @addtogroup Credit
 * @{
 */

/**
 * @brief Implements the calculation of a loan with an annuity type of payment
 *
 * @param loan Loan amount input
 * @param interest Interest rate input
 * @param months Total month input
 * @return long double result
 */
long double credit_calc(long double loan, long double interest, int months);

/**
 * @brief Implements the calculation of a loan with an differentiated type of
 * payment
 *
 * @param loan Loan amount input for every month of the loan period
 * @param rate Interest rate input
 * @return long double result
 */
long double differen_calc(long double loan, long double rate);

/**
 * @}
 *
 */

#endif  // SRC_BACK_CREDIT_CALCULATOR_H
