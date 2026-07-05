#include "my_decimal.h"

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_big_decimal res_1 = {0}, res_2 = {0}, mantisa = {0};
  normalization(value_1, value_2, &res_1, &res_2);

  int sign = 0;
  if (get_sign(value_1) ^ get_sign(value_2)) {
    if (mantisa_is_greater_or_equal(res_1, res_2)) {
      sign = get_sign(value_1);
      my_simple_sub(res_1, res_2, &mantisa);
    } else {
      sign = get_sign(value_2);
      my_simple_sub(res_2, res_1, &mantisa);
    }
  } else {
    sign = get_sign(value_1);
    my_simple_add(res_1, res_2, &mantisa);
  }

  int exp = (get_exp(value_1) > get_exp(value_2)) ? (get_exp(value_1))
                                                  : (get_exp(value_2));

  return from_big_to_decimal(mantisa, exp, sign, result);
}