#include "my_decimal.h"

void my_mantisa_zeroing(my_big_decimal *variable) {
  for (int i = 5; i >= 0; i--) variable->bits[i] = 0;
}
void my_zeroing(my_decimal *variable) {
  for (int i = 3; i >= 0; i--) variable->bits[i] = 0;
}

int get_exp(my_decimal value) { return (value.bits[3] >> 16) & 255; }

void set_exp(my_decimal *result, int exp) { result->bits[3] |= (exp << 16); }

int get_sign(my_decimal value) { return ((value.bits[3] >> 31) & 1); }

my_big_decimal get_mantisa(my_decimal src) {
  my_big_decimal result = {0};
  for (int i = 0; i <= 2; i++) result.bits[i] = src.bits[i];
  return result;
}

void normalization(my_decimal value_1, my_decimal value_2,
                   my_big_decimal *res_1, my_big_decimal *res_2) {
  int exp = get_exp(value_1) - get_exp(value_2);
  *res_1 = get_mantisa(value_1);
  *res_2 = get_mantisa(value_2);

  my_big_decimal temp = {{10, 0, 0, 0, 0, 0}};
  if (exp > 0)
    for (int i = 1; i <= exp; ++i) *res_2 = my_simple_mul(*res_2, temp);
  else if (exp < 0)
    for (int i = 1; i <= -exp; ++i) *res_1 = my_simple_mul(*res_1, temp);
}

int from_big_to_decimal(my_big_decimal mantisa, int exp, int sign,
                        my_decimal *result) {
  int flag = my_banc_round(&mantisa, &exp);
  if (flag != 0) {
    if (sign == 1)
      return 2;
    else
      return 1;
  }
  if ((mantisa.bits[2] == 0) && (mantisa.bits[1] == 0) &&
      (mantisa.bits[0] == 0))
    sign = exp = 0;

  my_zeroing(result);
  for (int i = 0; i <= 2; i++) result->bits[i] = mantisa.bits[i];
  result->bits[3] |= (sign << 31);
  set_exp(result, exp);

  return flag;
}

int my_banc_round(my_big_decimal *mantisa, int *exp) {
  my_big_decimal remainder = {0}, temp = {{10, 0, 0, 0, 0, 0}};

  for (; (((mantisa->bits[3] != 0) || (mantisa->bits[4] != 0) ||
           (mantisa->bits[5] != 0) || (*exp > 28)) &&
          *exp > 0);
       *exp -= 1)
    remainder = my_simple_div(*mantisa, temp, mantisa);

  if ((((mantisa->bits[0] & 1) == 0) && (remainder.bits[0] > 5)) ||
      (((mantisa->bits[0] & 1) == 1) && (remainder.bits[0] >= 5))) {
    temp.bits[0] = 1;
    my_simple_add(*mantisa, temp, mantisa);
  }
  int flag = 0;
  for (int j = 5; j >= 3; j--)
    if (mantisa->bits[j] != 0) flag++;
  if (flag != 0) return 1;

  return 0;
}

my_big_decimal shift_bit(my_big_decimal value_2, int num_bits) {
  my_big_decimal temp = {0};
  for (int i = 0; i <= 5; i++)
    for (int j = 0; j <= 31; j++)
      if ((value_2.bits[i] >> j) & 1)
        temp.bits[(i * 32 + j + num_bits) / 32] |= (1 << (j + num_bits) % 32);
  return temp;
}
