#include "my_decimal.h"

int my_is_equal(my_decimal value_1, my_decimal value_2) {
  if (get_sign(value_1) ^ get_sign(value_2)) return 0;

  my_big_decimal res_1 = {0}, res_2 = {0};
  normalization(value_1, value_2, &res_1, &res_2);

  return my_is_mantisa_equal(res_1, res_2);
}

int my_is_mantisa_equal(my_big_decimal res_1, my_big_decimal res_2) {
  for (int i = 0; i <= 5; i++)
    if (res_1.bits[i] != res_2.bits[i]) return 0;
  return 1;
}