#include "my_decimal.h"

void my_simple_sub(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result) {
  my_mantisa_zeroing(result);
  int next = 0;
  for (int i = 0; i <= 5; i++)
    for (int j = 0; j <= 31; j++) {
      switch (((value_1.bits[i] >> j) & 1) - ((value_2.bits[i] >> j) & 1) -
              next) {
        case 0:
          next = 0;
          break;
        case 1:
          result->bits[i] |= (1 << j);
          next = 0;
          break;
        case -1:
          result->bits[i] |= (1 << j);
          next = 1;
          break;
        default:
          next = 1;
          break;
      }
    }
}
