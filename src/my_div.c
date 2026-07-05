#include "my_decimal.h"

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  if ((value_2.bits[0] == 0) && (value_2.bits[1] == 0) &&
      (value_2.bits[2] == 0))
    return 3;

  int sign = (get_sign(value_1) ^ get_sign(value_2));
  int exp = (get_exp(value_1) - get_exp(value_2));
  my_big_decimal big_1 = get_mantisa(value_1), big_2 = get_mantisa(value_2),
                  mantisa = {0}, ten = {{10, 0, 0, 0, 0, 0}}, temp = {0};

  for (; exp < 0; exp++) big_1 = my_simple_mul(big_1, ten);

  my_big_decimal remainder = my_simple_div(big_1, big_2, &mantisa);

  for (; exp <= 29; exp++) {
    int flag = 0;
    for (int i = 5; i >= 0; i--) {
      if (remainder.bits[i] != 0) flag++;
    }
    if (flag == 0) break;
    remainder = my_simple_mul(remainder, ten);
    temp = my_simple_mul(mantisa, ten);
    remainder = my_simple_div(remainder, big_2, &mantisa);
    my_simple_add(mantisa, temp, &mantisa);
  }

  if ((mantisa.bits[0] == 0) && (mantisa.bits[1] == 0) &&
      (mantisa.bits[2] == 0) && (mantisa.bits[3] == 0) &&
      (mantisa.bits[4] == 0) && (mantisa.bits[5] == 0) &&
      ((value_1.bits[0] != 0) || (value_1.bits[1] != 0) ||
       (value_1.bits[2] != 0)))
    return 2;

  return from_big_to_decimal(mantisa, exp, sign, result);
}

my_big_decimal my_simple_div(my_big_decimal value_1, my_big_decimal value_2,
                               my_big_decimal *big_result) {
  my_mantisa_zeroing(big_result);

  int bit = 0;
  for (int i = 5; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      if ((value_2.bits[i] >> j) & 1) {
        bit = i * 32 + j;
        break;
      }
    }
    if (bit != 0) break;
  }

  while (mantisa_is_greater_or_equal(value_1, value_2)) {
    int i = 0;
    while (mantisa_is_greater_or_equal(value_1, shift_bit(value_2, i)) &&
           i <= (190 - bit))
      i++;

    my_simple_sub(value_1, shift_bit(value_2, (i - 1)), &value_1);
    my_big_decimal temp = {0};
    temp.bits[(i - 1) / 32] |= (1 << ((i - 1) % 32));
    my_simple_add(*big_result, temp, big_result);
  }
  return value_1;
}

int mantisa_is_greater_or_equal(my_big_decimal value_1,
                                my_big_decimal value_2) {
  for (int i = 5; i >= 0; --i) {
    for (int j = 31; j >= 0; --j) {
      if ((value_1.bits[i] >> j) ^ (value_2.bits[i] >> j)) {
        if ((value_1.bits[i] >> j) & 1) {
          return 1;
        } else {
          return 0;
        }
      }
    }
  }
  return 1;
}
