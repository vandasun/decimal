#include "my_decimal.h"

int my_is_greater_or_equal(my_decimal value_1, my_decimal value_2) {
  return (my_is_less(value_1, value_2) ^ 1);
}