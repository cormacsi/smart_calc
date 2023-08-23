/**
 * @file deposit_calc.h
 * @author cormacsi
 * @brief Header file for deposit calculator
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_DEPOSIT_CALCULATOR_H
#define SRC_BACK_DEPOSIT_CALCULATOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup Deposit
 * @{
 */

/**
 * @brief  The structure of input values for deposit calculation
 *
 */
typedef struct d_struct {
  long double amount;     /**< Deposit amount */
  int pay_type;           /**< Periodicity of payments */
  int total_month;        /**< Deposit term in months */
  long double interest;   /**< Interest rate */
  long double tax;        /**< Tax rate */
  bool cap;               /**< Capitalization of interest */
  int rep_type;           /**< Periodicity of replenishments */
  long double rep_amount; /**< Replenishment amount */
  int wit_type;           /**< Periodicity of partial withdrawals */
  long double wit_amount; /**< Withdrawal amount */
} deposit;

/**
 * @brief Current date structure
 *
 */
typedef struct t_struct {
  int date;  /**< Date */
  int month; /**< Month */
  int year;  /**< Year */
} t_date;

/**
 * @brief Output struct with result values
 *
 */
typedef struct r_struct {
  long double accrued;  /**< Accrued interest */
  long double t_amount; /**< Tax amount */
  long double d_amount; /**< Deposit amount by the end of the term */
} s_result;

/**
 * @brief Structure for calculating the tax for each year of the deposit
 *
 */
typedef struct tax_struct {
  int last_year;        /**< Previous year */
  long double rate;     /**< Interest rate */
  long double last_cap; /**< Previous amount of accrued interest */
  long double total;    /**< Total amount of tax*/
} r_tax;

/**
 * @brief Сhecking the leap year
 *
 * @param year Current year for check
 * @return true
 * @return false
 */
bool leap_year(int year);

/**
 * @brief Find out the number of calendar days in the deposit term
 *
 * @param m The number of months of the deposit period
 * @param current Current date (deposit term start date)
 * @return int The number of calendar days in the deposit period
 */
int find_payment_period(int m, t_date current);

/**
 * @brief The function sets the main deposit amount to every value in the array
 *
 * @param capital An array of daily deposit values
 * @param N Array length
 * @param amount The main deposit amount
 */
void add_deposit(long double *capital, int N, long double amount);

/**
 * @brief The function determines the number of calendar days in the period
 *
 * @param type Periodicity of replenishments or withdrawals
 * @param current A pointer to the current date structure
 * @return int Periodicity of calendar days
 */
int find_period_RW(int type, t_date *current);

/**
 * @brief The function adds replenishments and subtracts withdrawals in a
 * certain period
 *
 * @param capital An array of daily deposit values
 * @param N Array length
 * @param calc Struct of input values for deposit calculation
 * @param current Current date structure
 */
void add_rep_or_with(long double *capital, int N, deposit calc, t_date current);

/**
 * @brief Increases the value of the current date
 *
 * @param current A pointer to the current date structure
 * @param period Integer value of the period in calendar days
 */
void reload_date(t_date *current, int period);

/**
 * @brief Finds the period of capitalization if it is provided
 *
 * @param pay_type Periodicity of payments
 * @param current A pointer to the current date structure
 * @return int Integer value of the period in calendar days
 */
int find_period_AC(int pay_type, t_date *current);

/**
 * @brief The main function for calculating capitalization of deposit interest
 * and taxes
 *
 * @param capital An array of daily deposit values
 * @param N Array length
 * @param calc Struct of input values for deposit calculation
 * @param current The current date structure
 * @param result A pointer to the output struct with result values
 */
void accrued_interest(long double *capital, int N, deposit calc, t_date current,
                      s_result *result);

/**
 * @brief Tax value calculation function
 *
 * @param tax A pointer to the structure with the necessary values for
 * calculating the annual tax
 * @param capitalization Current value of accrued interest
 */
void calc_tax(r_tax *tax, long double capitalization);

/**
 * @brief The main function in deposit calculator
 *
 * @param calc The structure of input values for deposit calculation
 * @param current The current date structure
 * @return s_result Output structure with result values
 */
s_result deposit_calculator(deposit calc, t_date current);

/**
 * @}
 *
 */

#endif  // SRC_BACK_DEPOSIT_CALCULATOR_H
