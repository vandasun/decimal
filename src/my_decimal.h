#include <math.h>
#include <stdio.h>

typedef struct {
  int bits[4];
} my_decimal;

typedef struct {
  int bits[6];
} my_big_decimal;

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
void my_simple_add(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result);

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
void my_simple_sub(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result);

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
my_big_decimal my_simple_mul(my_big_decimal value_1,
                               my_big_decimal value_2);

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);
my_big_decimal my_simple_div(my_big_decimal value_1, my_big_decimal value_2,
                               my_big_decimal *big_result);
int mantisa_is_greater_or_equal(my_big_decimal value_1,
                                my_big_decimal value_2);

int my_is_less(my_decimal, my_decimal);
int my_is_less_or_equal(my_decimal, my_decimal);
int my_is_greater(my_decimal, my_decimal);
int my_is_greater_or_equal(my_decimal, my_decimal);
int my_is_equal(my_decimal, my_decimal);
int my_is_not_equal(my_decimal, my_decimal);
int my_is_mantisa_equal(my_big_decimal res_1, my_big_decimal res_2);

int my_from_int_to_decimal(int src, my_decimal *dst);
int my_from_float_to_decimal(float src, my_decimal *dst);
int my_from_decimal_to_int(my_decimal src, int *dst);
int my_from_decimal_to_float(my_decimal src, float *dst);

int my_floor(my_decimal value, my_decimal *result);
int my_round(my_decimal value, my_decimal *result);
int my_truncate(my_decimal value, my_decimal *result);
int my_negate(my_decimal value, my_decimal *result);

void my_mantisa_zeroing(my_big_decimal *variable);
void my_zeroing(my_decimal *variable);
int get_exp(my_decimal value);
void set_exp(my_decimal *result, int exp);
int get_sign(my_decimal value);
my_big_decimal get_mantisa(my_decimal src);
void normalization(my_decimal value_1, my_decimal value_2,
                   my_big_decimal *res_1, my_big_decimal *res_2);
int from_big_to_decimal(my_big_decimal, int exp, int sign,
                        my_decimal *result);
int my_banc_round(my_big_decimal *mantisa, int *exp);
my_big_decimal shift_bit(my_big_decimal value_2, int num_bits);