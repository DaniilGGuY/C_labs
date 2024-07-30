#ifndef CHECK_HEAD_H__
#define CHECK_HEAD_H__

#include "matrix.h"
#include <check.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int matrix_cmp(double **mat_a, double **mat_b, size_t n, size_t m);

Suite* check_sum(void);

Suite* check_comp(void);

Suite* check_slau(void);

#endif