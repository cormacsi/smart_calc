/**
 * @file credit_calc.c
 * @author cormacsi
 * @brief Credit calculation
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "credit_calc.h"

/**
 * One-time calculation of the monthly loan payment using the formula.
 */
long double credit_calc(long double loan, long double rate, int months) {
  rate = rate / (12. * 100.);
  long double payment = loan * (rate / (1. - powl((1. + rate), (-months))));
  return round(payment * 100.) / 100.;
}

/**
 * Calculation of the monthly loan payment for each month separately.
 */
long double differen_calc(long double loan, long double rate) {
  long double payment = loan * rate / 100. / 12.;
  return payment;
}
