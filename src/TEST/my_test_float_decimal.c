#include "my_test_decimal.h"

START_TEST(test_my_DECIMAL_FLOAT_1) {
  float a = 9903520314283042199192993792.0;
  float b = 9903520314283042199192993792.0;
  float c = -1;

  my_decimal _a;

  my_from_float_to_decimal(a, &_a);
  my_from_decimal_to_float(_a, &c);

  ck_assert_float_eq(b, c);
}
END_TEST

START_TEST(test_my_DECIMAL_FLOAT_2) {
  float a = INFINITY;
  my_decimal _a;

  a = my_from_float_to_decimal(a, &_a);

  ck_assert_float_eq(a, 1);
}
END_TEST

START_TEST(test_my_DECIMAL_FLOAT_3) {
  float a = NAN;
  my_decimal _a;

  a = my_from_float_to_decimal(a, &_a);

  ck_assert_float_eq(a, 1);
}
END_TEST

START_TEST(test_my_DECIMAL_FLOAT_4) {
  float a = 7.922816e+00;
  float b = 7.922816e+00;
  float c = -1;

  my_decimal _a;

  my_from_float_to_decimal(a, &_a);

  my_from_decimal_to_float(_a, &c);
  ck_assert_float_eq(c, b);
}
END_TEST

START_TEST(test_my_DECIMAL_FLOAT_5) {
  float a = pow(2, -97);
  my_decimal _a;

  a = my_from_float_to_decimal(a, &_a);

  ck_assert_float_eq(a, 1);
}
END_TEST

TCase *TCase_decimal_float(void) {
  TCase *tc = tcase_create("DECIMAL_FLOAT_tc");

  tcase_add_test(tc, test_my_DECIMAL_FLOAT_1);
  tcase_add_test(tc, test_my_DECIMAL_FLOAT_2);
  tcase_add_test(tc, test_my_DECIMAL_FLOAT_3);
  tcase_add_test(tc, test_my_DECIMAL_FLOAT_4);
  tcase_add_test(tc, test_my_DECIMAL_FLOAT_5);

  return tc;
}
