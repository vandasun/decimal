#include "my_decimal.h"

int my_is_less(my_decimal value_1, my_decimal value_2) {
  if (get_sign(value_1) ^ get_sign(value_2)) {
    if (get_sign(value_1))
      return 1;
    else
      return 0;
  }

  my_big_decimal res_1 = {0}, res_2 = {0};
  normalization(value_1, value_2, &res_1, &res_2);

  for (int i = 5; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      if (((res_1.bits[i] >> j) & 1) ^ ((res_2.bits[i] >> j) & 1)) {
        if ((res_2.bits[i] >> j) & 1)
          return 1 ^ get_sign(value_1);
        else
          return 0 ^ get_sign(value_1);
      }
    }
  }
  return 0;
}