#include "my_test_decimal.h"

int main(void) {
  int failed = 0;
  Suite *my_all_tests = suite_create("my_decimal_tests");
  suite_add_tcase(my_all_tests, TCase_add());
  suite_add_tcase(my_all_tests, TCase_sub());
  suite_add_tcase(my_all_tests, TCase_mul());
  suite_add_tcase(my_all_tests, TCase_div());

  suite_add_tcase(my_all_tests, TCase_is_less());
  suite_add_tcase(my_all_tests, TCase_is_less_or_equal());
  suite_add_tcase(my_all_tests, TCase_is_greater());
  suite_add_tcase(my_all_tests, TCase_is_greater_or_equal());
  suite_add_tcase(my_all_tests, TCase_equal());
  suite_add_tcase(my_all_tests, TCase_not_equal());

  suite_add_tcase(my_all_tests, TCase_int_decimal());
  suite_add_tcase(my_all_tests, TCase_decimal_float());

  suite_add_tcase(my_all_tests, TCase_floor());
  suite_add_tcase(my_all_tests, TCase_round());

  SRunner *sr = srunner_create(my_all_tests);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}