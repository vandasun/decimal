#include "my_decimal.h"

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_negate(value_2, &value_2);
  return my_add(value_1, value_2, result);
}