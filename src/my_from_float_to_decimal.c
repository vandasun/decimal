#include "my_decimal.h"

int my_from_float_to_decimal(float src, my_decimal *dst) {
  union FloatBits {
    float f;
    int bits;
  };
  union FloatBits fb;
  fb.f = src;

  my_zeroing(dst);

  if (isinf(src) || fabsf(src) > 79228162514264337593543950335.0f ||
      isnan(src) || (fabsf(src) > 0 && fabsf(src) < 1e-28))
    return 1;

  int exp = -6;
  int sign = ((fb.bits >> 31) & 1);
  int bin_exp = ((fb.bits >> 23) & 255) - 23 - 127;

  my_big_decimal mantisa = {0}, fl = {0}, dm_val = {0};
  fl.bits[0] = (fb.bits & 8388607) | 8388608;

  if (bin_exp >= 0) {
    dm_val.bits[(bin_exp) / 32] |= (1 << ((bin_exp) % 32));
    mantisa = my_simple_mul(fl, dm_val);
  }

  else if (bin_exp < 0) {
    dm_val.bits[(-bin_exp) / 32] |= (1 << ((-bin_exp) % 32));
    my_big_decimal remainder = my_simple_div(fl, dm_val, &mantisa);
    my_big_decimal ten = {{10, 0, 0, 0, 0, 0}}, temp = {0};

    for (; exp < 0; exp++) {
      remainder = my_simple_mul(remainder, ten);
      mantisa = my_simple_mul(mantisa, ten);
      remainder = my_simple_div(remainder, dm_val, &temp);
      my_simple_add(mantisa, temp, &mantisa);
    }

    remainder = my_simple_mul(remainder, ten);
    remainder = my_simple_div(remainder, dm_val, &temp);
    if (temp.bits[0] >= 5) {
      my_big_decimal one = {{1, 0, 0, 0, 0, 0}};
      my_simple_add(mantisa, one, &mantisa);
    }
  }
  return (from_big_to_decimal(mantisa, 6 + exp, sign, dst) != 0);
}
