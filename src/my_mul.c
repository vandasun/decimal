#include "my_decimal.h"

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_big_decimal mantisa =
      my_simple_mul(get_mantisa(value_1), get_mantisa(value_2));
  int sign = (get_sign(value_1) ^ get_sign(value_2));
  int exp = (get_exp(value_1) + get_exp(value_2));

  return from_big_to_decimal(mantisa, exp, sign, result);
}

my_big_decimal my_simple_mul(my_big_decimal value_1,
                               my_big_decimal value_2) {
  my_big_decimal big_result = {0};
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 31; j++) {
      if ((value_1.bits[i] >> j) & 1) {
        my_big_decimal temp = shift_bit(value_2, i * 32 + j);
        my_simple_add(big_result, temp, &big_result);
      }
    }
  }
  return big_result;
}
