/**
 * @file deposit_calc.c
 * @author cormacsi
 * @brief Deposit calculation
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "deposit_calc.h"

/**
 * @brief Static constant integer array of lengths of months in a year
 *
 */
static const int const_months[13] = {0,  31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

/**
 * Accepts the current year and checks if it is a leap year
 */
bool leap_year(int year) {
  bool leap = 0;
  if (year % 400 == 0)
    leap = 1;
  else if (year % 100 == 0)
    leap = 0;
  else if (year % 4 == 0)
    leap = 1;
  return leap;
}

/**
 * The function accepts the number of months of the deposit period and returns
 * the number of calendar days in it.
 */
int find_payment_period(int m, t_date current) {
  int result = 0;

  for (int i = 0; i <= m; i++) {
    int days_a_month = 0;
    if (current.month == 2 && leap_year(current.year))
      days_a_month = 29;
    else
      days_a_month = const_months[current.month];

    if (i == 0)
      result += (days_a_month - current.date);
    else if (i == m)
      result += current.date;
    else
      result += days_a_month;

    current.month += 1;
    if (current.month > 12) {
      current.month = 1;
      current.year++;
    }
  }
  return result;
}

/**
 * The function runs along the entire length of the array and sets the value of
 * the initial deposit amount.
 */
void add_deposit(long double *capital, int N, long double amount) {
  for (int i = 0; i < N; i++) {
    capital[i] = amount;
  }
}

/**
 * The function accepts two values: the first is
 * the type of the payment period in the value of an integer,
 * the second is the current date in the structure.
 */
int find_period_RW(int type, t_date *current) {
  int period = 0;
  if (type == 1)
    period = find_payment_period(1, *current);
  else if (type == 2)
    period = find_payment_period(3, *current);
  else if (type == 3)
    period = find_payment_period(6, *current);
  else  // (type == 4)
    period = find_payment_period(12, *current);
  reload_date(current, period);
  return period;
}

/**
 * The function takes an array of deposit values on each
 * day of the deposit period and adds the replenishment value to
 * the certain dates depending on the payment periodicity if it is provided.
 * If there is a withdrawal period from the deposit account,
 * then the program subtracts this value.
 */
void add_rep_or_with(long double *capital, int N, deposit calc,
                     t_date current) {
  long double replenishment = 0., withdrawal = 0.;
  int rep_period = calc.rep_type ? find_period_RW(calc.rep_type, &current) : N;
  int wit_period = calc.wit_type ? find_period_RW(calc.wit_type, &current) : N;

  for (int i = 0; i < N; i++) {
    if (calc.rep_type && rep_period == 1) {
      rep_period = find_period_RW(calc.rep_type, &current);
      replenishment += calc.rep_amount;
    }
    if (calc.wit_type && wit_period == 1) {
      wit_period = find_period_RW(calc.wit_type, &current);
      withdrawal += calc.wit_amount;
    }
    rep_period -= 1;
    wit_period -= 1;
    capital[i] += replenishment;
    capital[i] -= withdrawal;
  }
}

/**
 * The function accepts a pointer to the structure
 * of the current date and the period in calendar days,
 * then it increments the value of the current date.
 */
void reload_date(t_date *current, int period) {
  for (int i = 0; i < period; i++) {
    current->date += 1;
    if (current->date == 29 && current->month == 2 &&
        leap_year(current->year)) {
    } else if (current->date > const_months[current->month]) {
      current->date = 1;
      current->month += 1;
    }
    if (current->month > 12) {
      current->month = 1;
      current->year += 1;
    }
  }
}

/**
 * The function accepts the integer value of the payment type
 * (which is needed for calculation capitalization for the particular period)
 * and a pointer to the structure of the current date.
 * It returns the integer value of days in the certain period.
 */
int find_period_AC(int pay_type, t_date *current) {
  int period = 0;
  if (pay_type == 0)
    period = 1;
  else if (pay_type == 1)
    period = 7;
  else if (pay_type == 2)
    period = find_payment_period(1, *current);
  else if (pay_type == 3)
    period = find_payment_period(3, *current);
  else if (pay_type == 4)
    period = find_payment_period(6, *current);
  else if (pay_type == 5)
    period = find_payment_period(12, *current) + 1;
  reload_date(current, period);
  return period;
}

/**
 * The function takes an array of deposit values on each
 * day of the deposit period and calculates capitalization
 * for each payment period if it is provided.
 */
void accrued_interest(long double *capital, int N, deposit calc, t_date current,
                      s_result *result) {
  int period =
      (calc.pay_type == 6) ? N - 1 : find_period_AC(calc.pay_type, &current);
  long double capitalization = 0.;
  int last_period = period;

  r_tax tax;
  tax.last_year = current.year;
  tax.rate = calc.tax;
  tax.last_cap = 0;
  tax.total = 0.;

  for (int i = 0; i < N; i++) {
    if (period == 0) {
      int da_year = leap_year(current.year) ? 366 : 365;
      long double s = capital[i - last_period] * calc.interest * last_period /
                      da_year / 100.;
      capitalization += roundl(s * 100.) / 100.;
      if (calc.cap) capital[i] += capitalization;
      period = find_period_AC(calc.pay_type, &current);
      last_period = period;
      if (current.year != tax.last_year || i == N - 1)
        calc_tax(&tax, capitalization);
    }
    period -= 1;
  }
  if (period != last_period - 1) {
    period = last_period - period - 1;
    int da_year = leap_year(current.year) ? 366 : 365;
    long double s =
        capital[N - period] * calc.interest * period / da_year / 100.;
    capitalization += roundf(s * 100.) / 100.;
    calc_tax(&tax, capitalization);
    if (calc.cap) capital[N - 1] += capitalization;
  }
  result->accrued = capitalization;
  result->t_amount = tax.total;
  result->d_amount = capital[N - 1];
}

/**
 * Сalculates the tax value for each deposit year
 * depending on the total accrued interest for that year.
 */
void calc_tax(r_tax *tax, long double capitalization) {
  long double tax_rate = 0.075 * 10e5;

  long double new_cap = capitalization - tax->last_cap;
  if (new_cap > tax_rate) {
    tax->total += (new_cap - tax_rate) * tax->rate / 100.;
  }
  tax->last_year += 1;
  tax->last_cap += new_cap;
}

/**
 * The main function for deposit calculation accepts all the values from the
 * front part and returns the result structure.
 */
s_result deposit_calculator(deposit calc, t_date current) {
  s_result result;
  result.accrued = 0.;
  result.t_amount = 0.;
  result.d_amount = 0.;

  int N = find_payment_period(calc.total_month, current) + 1;

  long double *capital = calloc(N, sizeof(long double));
  add_deposit(capital, N, calc.amount);

  if (calc.rep_amount == 0. || calc.rep_type == 0) {
    calc.rep_type = 0;
    calc.rep_amount = 0.;
  }
  if (calc.wit_amount == 0. || calc.wit_type == 0) {
    calc.wit_type = 0;
    calc.wit_amount = 0.;
  }
  if (calc.rep_type || calc.wit_type)
    add_rep_or_with(capital, N, calc, current);
  if (calc.total_month < 12 && calc.pay_type == 5) calc.pay_type = 6;

  accrued_interest(capital, N, calc, current, &result);
  result.d_amount = capital[N - 1];

  free(capital);
  return result;
}
