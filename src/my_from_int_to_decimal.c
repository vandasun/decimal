#include "my_decimal.h"

int my_from_int_to_decimal(int src, my_decimal *dst) {
  my_zeroing(dst);
  dst->bits[3] |= (src & (1 << 31));
  if (dst->bits[3])
    dst->bits[0] = src * (-1);
  else
    dst->bits[0] = src;
  return 0;
}