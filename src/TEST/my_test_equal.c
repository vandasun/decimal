#include "my_test_decimal.h"

int simple_equal(int a, int b) {
  int res = -1;
  if ((a - b) == 0)
    res = 1;
  else
    res = 0;
  return res;
}

START_TEST(test_my_equal_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int res = -1;
  int eq = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  res = my_is_equal(_a, _b);
  eq = simple_equal(a, b);
  ck_assert_int_eq(res, eq);
}
END_TEST

START_TEST(test_my_equal_2) {
  int a = (float)10e5;
  int b = (float)10e5;
  int res = -1;
  int eq = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  res = my_is_equal(_a, _b);
  eq = simple_equal(a, b);
  ck_assert_int_eq(res, eq);
}
END_TEST

TCase *TCase_equal(void) {
  TCase *tc = tcase_create("equal_tc");

  tcase_add_test(tc, test_my_equal_1);
  tcase_add_test(tc, test_my_equal_2);

  return tc;
}