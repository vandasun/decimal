#include "my_decimal.h"

int my_from_decimal_to_float(my_decimal src, float *dst) {
  double res = 0;
  int exp = get_exp(src);
  int sign = get_sign(src);

  for (int i = 0; i <= 2; i++)
    for (int j = 0; j <= 31; j++)
      if ((src.bits[i] >> j) & 1) res += pow(2.0, i * 32 + j);

  for (; exp > 0; exp--) res /= 10;

  *dst = (float)res * (res == 0 ? 0 : sign * (-2) + 1);

  return 0;
}