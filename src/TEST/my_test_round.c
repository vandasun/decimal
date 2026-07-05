#include <math.h>

#include "my_test_decimal.h"

START_TEST(test_my_round_1) {
  int a = (float)10e5;
  int c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_round(_a, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a, c);
}
END_TEST

START_TEST(test_my_round_2) {
  int a = (float)-10e5;
  int c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_round(_a, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a, c);
}
END_TEST

START_TEST(test_my_round_3) {
  float a = -10 + 0.4;
  float c = 0;

  my_decimal _a;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_round(_a, &res);
  my_from_decimal_to_float(res, &c);

  a = round(a);
  ck_assert_float_eq(a, c);
}
END_TEST

TCase *TCase_round(void) {
  TCase *tc = tcase_create("round_tc");

  tcase_add_test(tc, test_my_round_1);
  tcase_add_test(tc, test_my_round_2);
  tcase_add_test(tc, test_my_round_3);

  return tc;
}