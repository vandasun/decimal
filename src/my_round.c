#include "my_decimal.h"

int my_round(my_decimal value, my_decimal *result) {
  int sign = get_sign(value);
  int exp = get_exp(value);
  my_big_decimal mantisa = get_mantisa(value), remainder = {0},
                  temp = {{10, 0, 0, 0, 0, 0}};
  ;
  for (; exp > 0; exp--) remainder = my_simple_div(mantisa, temp, &mantisa);

  if (remainder.bits[0] >= 5) {
    temp.bits[0] = 1;
    my_simple_add(mantisa, temp, &mantisa);
  }
  return (from_big_to_decimal(mantisa, exp, sign, result) != 0);
}
