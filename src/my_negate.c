#include "my_decimal.h"

int my_negate(my_decimal value, my_decimal *result) {
  *result = value;
  result->bits[3] ^= (1 << 31);
  return 0;
}