#include "my_test_decimal.h"

START_TEST(test_my_sub_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}
END_TEST

START_TEST(test_my_sub_2) {
  int a = (float)5;
  int b = (float)2;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}
END_TEST

START_TEST(test_my_sub_3) {
  int a = (float)3;
  int b = (float)5;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}
END_TEST

START_TEST(test_my_sub_5) {
  int c = -1;

  my_decimal _a = {{0, -2147483648, 0, 0}};
  my_decimal _b = {{0, -2147483648, 0, -2147483648}};
  my_decimal res;

  set_exp(&_a, 26);
  set_exp(&_b, 27);

  c = my_sub(_a, _b, &res);

  ck_assert_int_eq(0, c);
}
END_TEST

START_TEST(test_my_sub_6) {
  float c = 0;

  my_decimal _a = {{-1, -1, -1, 0}};
  my_decimal _b = {{-1, -1, -1, 0}};
  my_decimal res;

  set_exp(&_a, 28);
  set_exp(&_b, 28);

  my_sub(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(0, c);
}
END_TEST

START_TEST(test_my_sub_7) {
  float a = -0.00879;
  float b = 0.123456;
  float c = -1;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_sub(_a, _b, &res);

  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(a - b, c);
}
END_TEST

TCase *TCase_sub(void) {
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, test_my_sub_1);
  tcase_add_test(tc, test_my_sub_2);
  tcase_add_test(tc, test_my_sub_3);
  tcase_add_test(tc, test_my_sub_5);
  tcase_add_test(tc, test_my_sub_6);
  tcase_add_test(tc, test_my_sub_7);

  return tc;
}