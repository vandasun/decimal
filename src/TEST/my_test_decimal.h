#ifndef TEST_MY_TEST_DECIMAL_H
#define TEST_MY_TEST_DECIMAL_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../my_decimal.h"

TCase *TCase_add(void);
TCase *TCase_sub(void);
TCase *TCase_mul(void);
TCase *TCase_div(void);

TCase *TCase_is_less(void);
TCase *TCase_is_less_or_equal(void);
TCase *TCase_is_greater(void);
TCase *TCase_is_greater_or_equal(void);
TCase *TCase_equal(void);
TCase *TCase_not_equal(void);

TCase *TCase_decimal_float(void);
TCase *TCase_int_decimal(void);

TCase *TCase_floor(void);
TCase *TCase_round(void);

#endif  // TEST_MY_TEST_DECIMAL_H
