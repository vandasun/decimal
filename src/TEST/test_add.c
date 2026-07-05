#include "my_test_decimal.h"

START_TEST(test_my_add_1) {
  int a = (float)10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_2) {
  int a = (float)-10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_3) {
  int a = (float)3;
  int b = (float)3;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_4) {
  float a = 3.12;
  float b = 3.135;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_5) {
  float a = 7.922816;
  float b = 7.922816;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_6) {
  float c = 0;

  my_decimal _a = {{-1, -1, -1, 0}};
  my_decimal _b = {{-1, -1, -1, 0}};
  my_decimal res;

  set_exp(&_a, 28);
  set_exp(&_b, 28);

  my_add(_a, _b, &res);

  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(15.845633, c);
}
END_TEST

START_TEST(test_my_add_7) {
  float c = 0;

  my_decimal _a = {{100000, 0, 0, 0}};
  my_decimal _b = {{1000, 0, 0, 0}};
  my_decimal res;

  set_exp(&_a, 2);

  my_add(_a, _b, &res);

  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(2000, c);
}
END_TEST

START_TEST(test_my_add_8) {
  int c = 0;

  my_decimal _a = {{-1, -1, -1, -2147483648}};
  my_decimal _b = {{-1, -1, -1, -2147483648}};
  my_decimal res;

  c = my_add(_a, _b, &res);

  ck_assert_float_eq(2, c);
}
END_TEST

START_TEST(test_my_add_9) {
  int c = 0;

  my_decimal _a = {{-1, -1, -1, 0}};
  my_decimal _b = {{-1, -1, -1, 0}};
  my_decimal res;

  c = my_add(_a, _b, &res);

  ck_assert_float_eq(1, c);
}
END_TEST

START_TEST(test_my_add_10) {
  float a = 9903520314283042199192993792.0;
  float b = 9903520314283042199192993792.0;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_11) {
  int a = (float)10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_12) {
  int a = (float)-10e5;
  int b = (float)10e1;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

START_TEST(test_my_add_13) {
  int a = (float)3;
  int b = (float)3;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}
END_TEST

TCase *TCase_add(void) {
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_my_add_1);
  tcase_add_test(tc, test_my_add_2);
  tcase_add_test(tc, test_my_add_3);
  tcase_add_test(tc, test_my_add_4);
  tcase_add_test(tc, test_my_add_5);
  tcase_add_test(tc, test_my_add_6);
  tcase_add_test(tc, test_my_add_7);
  tcase_add_test(tc, test_my_add_8);
  tcase_add_test(tc, test_my_add_9);
  tcase_add_test(tc, test_my_add_10);
  tcase_add_test(tc, test_my_add_11);
  tcase_add_test(tc, test_my_add_12);
  tcase_add_test(tc, test_my_add_13);

  return tc;
}