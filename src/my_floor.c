#include "my_decimal.h"

int my_floor(my_decimal value, my_decimal *result) {
  int sign = get_sign(value);
  int exp = get_exp(value);
  int flag = 0;

  my_big_decimal mantisa = get_mantisa(value), remainder = {0},
                  temp = {{10, 0, 0, 0, 0, 0}};
  for (; exp > 0; exp--) {
    remainder = my_simple_div(mantisa, temp, &mantisa);
    if (remainder.bits[0] != 0) flag = 1;
  }
  if (flag && sign == 1) {
    temp.bits[0] = 1;
    my_simple_add(mantisa, temp, &mantisa);
  }
  return (from_big_to_decimal(mantisa, exp, sign, result) != 0);
}