#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *back_calculator_test[] = {
      test_calculation(),  test_yard(),       test_stack(),
      test_sort(),         test_smart_calc(), test_credit_calc(),
      test_deposit_calc(), test_only_graph(), NULL};

  for (int i = 0; back_calculator_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(back_calculator_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Failed: %d\n", failed);

  return failed == 0 ? 0 : 1;
}
