#include "my_decimal.h"

int my_from_decimal_to_int(my_decimal src, int *dst) {
  my_truncate(src, &src);
  if ((src.bits[2] != 0) || (src.bits[1] != 0) ||
      ((src.bits[0] & (1 << 31)) && src.bits[3] == 0))
    return 1;
  if ((src.bits[0] & (1 << 31)) && src.bits[3] != 0) {
    *dst = src.bits[0];
    return 0;
  } else {
    *dst = 0;
    if (src.bits[3]) {
      *dst = src.bits[0] * (-1);
    } else
      *dst = src.bits[0];

    return 0;
  }
}