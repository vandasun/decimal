#include "my_test_decimal.h"

START_TEST(test_my_mul_1) {
  int a = (float)10e1;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}
END_TEST

START_TEST(test_my_mul_2) {
  float c = -1;

  my_decimal _a = {{0, -2147483648, 0, 0}};
  my_decimal _b = {{0, -2147483648, 0, 0}};
  my_decimal res;

  set_exp(&_a, 18);
  set_exp(&_b, 18);
  my_mul(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_int_eq(85, c);
}
END_TEST

START_TEST(test_my_mul_3) {
  float c = 0;

  my_decimal _a = {{-1, -1, -1, 0}};
  my_decimal _b = {{-1, -1, -1, 0}};
  my_decimal res;

  set_exp(&_a, 28);
  set_exp(&_b, 28);

  my_mul(_a, _b, &res);

  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(62.771019, c);
}
END_TEST

TCase *TCase_mul(void) {
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, test_my_mul_1);
  tcase_add_test(tc, test_my_mul_2);
  tcase_add_test(tc, test_my_mul_3);

  return tc;
}