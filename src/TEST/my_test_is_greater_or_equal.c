#include "my_test_decimal.h"

START_TEST(test_my_is_greater_or_equal_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int c = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  c = my_is_greater_or_equal(_a, _b);

  ck_assert_int_eq(1, c);
}
END_TEST

START_TEST(test_my_is_greater_or_equal_2) {
  int a = (float)-10e5;
  int b = (float)10e1;
  int c = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  c = my_is_greater_or_equal(_a, _b);

  ck_assert_int_eq(0, c);
}
END_TEST

START_TEST(test_my_is_greater_or_equal_3) {
  int a = (float)-10e5;
  int b = (float)-10e5;
  int c = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  c = my_is_greater_or_equal(_a, _b);

  ck_assert_int_eq(1, c);
}
END_TEST

TCase *TCase_is_greater_or_equal(void) {
  TCase *tc = tcase_create("is_greater_or_equal_tc");

  tcase_add_test(tc, test_my_is_greater_or_equal_1);
  tcase_add_test(tc, test_my_is_greater_or_equal_2);
  tcase_add_test(tc, test_my_is_greater_or_equal_3);
  return tc;
}