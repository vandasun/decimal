#include "my_test_decimal.h"

int eq(int a, int b) {
  int res = -1;
  if ((a - b) == 0)
    res = 0;
  else
    res = 1;
  return res;
}

START_TEST(test_my_not_equal_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int res = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  res = my_is_not_equal(_a, _b);
  a = eq(a, b);
  ck_assert_int_eq(res, a);
}
END_TEST

START_TEST(test_my_not_equal_2) {
  int a = (float)10e1;
  int b = (float)10e5;
  int res = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  res = my_is_not_equal(_a, _b);
  a = eq(a, b);
  ck_assert_int_eq(res, a);
}
END_TEST

START_TEST(test_my_not_equal_3) {
  int a = (float)10e1;
  int b = (float)10e1;
  int res = -1;

  my_decimal _a;
  my_decimal _b;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  res = my_is_not_equal(_a, _b);
  a = eq(a, b);
  ck_assert_int_eq(res, a);
}
END_TEST

TCase *TCase_not_equal(void) {
  TCase *tc = tcase_create("not_equal_tc");

  tcase_add_test(tc, test_my_not_equal_1);
  tcase_add_test(tc, test_my_not_equal_2);
  tcase_add_test(tc, test_my_not_equal_3);

  return tc;
}