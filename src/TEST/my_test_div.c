#include "my_test_decimal.h"

START_TEST(test_my_div_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a / b, c);
}
END_TEST

START_TEST(test_my_div_2) {
  float a = 1.0;
  float b = 2.0;
  float c = 0.0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(a / b, c);
}
END_TEST

START_TEST(test_my_div_3) {
  int a = (float)1;
  int b = (float)0;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  c = my_div(_a, _b, &res);

  ck_assert_int_eq(3, c);
}
END_TEST

START_TEST(test_my_div_4) {
  int a = 0;
  int b = 1;
  int c = 0;
  float d = -1;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  c = my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &d);

  ck_assert_int_eq(0, c);
  ck_assert_float_eq(a / b, d);
}
END_TEST

START_TEST(test_my_div_5) {
  float a = 0.01;
  float b = 39614081257132168796771975168.0;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  c = my_div(_a, _b, &res);

  ck_assert_int_eq(2, c);
}
END_TEST

START_TEST(test_my_div_6) {
  float c = 0;

  my_decimal _a = {{-1, -1, -1, 0}};
  my_decimal _b = {{-1, -1, -1, 0}};
  my_decimal res;

  set_exp(&_a, 28);
  set_exp(&_b, 28);

  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(1, c);
}
END_TEST

TCase *TCase_div(void) {
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, test_my_div_1);
  tcase_add_test(tc, test_my_div_2);
  tcase_add_test(tc, test_my_div_3);
  tcase_add_test(tc, test_my_div_4);
  tcase_add_test(tc, test_my_div_5);
  tcase_add_test(tc, test_my_div_6);

  return tc;
}
