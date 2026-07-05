#include "my_test_decimal.h"

START_TEST(test_my_INT_DECIMAL_1) {
  int a = (float)10e5;
  int b = (float)10e5;
  int c = 0;

  my_decimal _a;

  my_from_int_to_decimal(a, &_a);
  my_from_decimal_to_int(_a, &c);

  ck_assert_int_eq(b, c);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_2) {
  int a = (float)-10e1;
  int b = (float)-10e1;
  int c = -1;

  my_decimal _a;

  my_from_int_to_decimal(a, &_a);
  my_from_decimal_to_int(_a, &c);

  ck_assert_int_eq(b, c);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_3) {
  int a = (float)3;
  int b = (float)3;
  int c = -1;

  my_decimal _a;

  my_from_int_to_decimal(a, &_a);
  my_from_decimal_to_int(_a, &c);

  ck_assert_int_eq(b, c);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_4) {
  int a = 0;
  int b = -1;

  my_decimal res;

  my_from_int_to_decimal(a, &res);

  my_from_decimal_to_int(res, &b);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_5) {
  int a = -1;
  int res = -1;

  my_decimal _a = {{-1, -1, -1, 0}};

  res = my_from_decimal_to_int(_a, &a);

  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_6) {
  int a = -1;
  int b = 0;

  my_decimal res;

  my_from_int_to_decimal(a, &res);

  my_from_decimal_to_int(res, &b);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_7) {
  float a = 1.75;
  int b = 0;

  my_decimal res;

  my_from_float_to_decimal(a, &res);

  my_from_decimal_to_int(res, &b);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_INT_DECIMAL_8) {
  int b = 0;

  my_decimal res = {{-2147483648, 0, 0, -2147483648}};

  my_from_decimal_to_int(res, &b);

  ck_assert_int_eq(-2147483648, b);
}
END_TEST

TCase *TCase_int_decimal(void) {
  TCase *tc = tcase_create("INT_DECIMAL_tc");

  tcase_add_test(tc, test_my_INT_DECIMAL_1);
  tcase_add_test(tc, test_my_INT_DECIMAL_2);
  tcase_add_test(tc, test_my_INT_DECIMAL_3);
  tcase_add_test(tc, test_my_INT_DECIMAL_4);
  tcase_add_test(tc, test_my_INT_DECIMAL_5);
  tcase_add_test(tc, test_my_INT_DECIMAL_6);
  tcase_add_test(tc, test_my_INT_DECIMAL_7);
  tcase_add_test(tc, test_my_INT_DECIMAL_8);

  return tc;
}