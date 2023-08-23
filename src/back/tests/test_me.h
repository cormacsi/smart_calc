#ifndef SRC_TESTS_TEST_ME_H
#define SRC_TESTS_TEST_ME_H

#include <check.h>

#include "../smart_calc.h"

#define X_TEST "\0"
#define X_SORT 0.0

Suite *test_calculation(void);
Suite *test_yard(void);
Suite *test_stack(void);
Suite *test_sort(void);
Suite *test_smart_calc(void);
Suite *test_credit_calc(void);
Suite *test_deposit_calc(void);
Suite *test_only_graph(void);

#endif  // SRC_TESTS_TEST_ME_H
