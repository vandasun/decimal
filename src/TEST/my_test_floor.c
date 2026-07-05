#include "my_test_decimal.h"

START_TEST(test_my_floor_1) {
  float a = 0.5;
  int c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_floor(_a, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(0, c);
}
END_TEST

START_TEST(test_my_floor_2) {
  float a = -1.5;
  int c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_floor(_a, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(-2, c);
}
END_TEST

START_TEST(test_my_floor_3) {
  float a = -10231.1232;
  int c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_floor(_a, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(-10232, c);
}
END_TEST

TCase *TCase_floor(void) {
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, test_my_floor_1);
  tcase_add_test(tc, test_my_floor_2);
  tcase_add_test(tc, test_my_floor_3);
  return tc;
}