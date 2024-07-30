#include "check_head.h"
#include "memory_funcs.h"
#include <stdlib.h>
#include <math.h>

#define EPS          1e-9

//Сумма одного элемента с другим
START_TEST(sum_one_on_one)
{
    double mat_a[1][1] = { { 1 } };
    double mat_b[1][1] = { { -1 } };
    double ans[1][1] = { { 0 } };
    double *pa[1] = { mat_a[0] }, *pb[1] = { mat_b[0] }, *pans[1] = { ans[0] };
    double **mat_c = sum_matrix(pa, pb, 1, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 1));
    free_matrix(mat_c, 1);
}
END_TEST

//Сумма одного элемента с другим вещественные
START_TEST(sum_one_on_one_float)
{
    double mat_a[1][1] = { { 1.123 } };
    double mat_b[1][1] = { { -1.15 } };
    double ans[1][1] = { { -0.027 } };
    double *pa[1] = { mat_a[0] }, *pb[1] = { mat_b[0] }, *pans[1] = { ans[0] };
    double **mat_c = sum_matrix(pa, pb, 1, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 1));
    free_matrix(mat_c, 1);
}
END_TEST

//Сумма строк
START_TEST(sum_one_row)
{
    double mat_a[1][3] = { { 1, 2, 3 } };
    double mat_b[1][3] = { { 3, 2, 1 } };
    double ans[1][3] = { { 4, 4, 4 } };
    double *pa[1] = { mat_a[0] }, *pb[1] = { mat_b[0] }, *pans[1] = { ans[0] };
    double **mat_c = sum_matrix(pa, pb, 1, 3);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 3));
    free_matrix(mat_c, 1);
}
END_TEST

//Сумма столбцов
START_TEST(sum_one_col)
{
    double mat_a[3][1] = { { 1 }, { 2 }, { 3 } };
    double mat_b[3][1] = { { 3 }, { 2 }, { 1 } };
    double ans[3][1] = { { 4 }, { 4 }, { 4 } };
    double *pa[3] = { mat_a[0], mat_a[1], mat_a[2] }, *pb[3] = { mat_b[0], mat_b[1], mat_b[2] }, *pans[3] = { ans[0], ans[1], ans[2] };
    double **mat_c = sum_matrix(pa, pb, 3, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 3, 1));
    free_matrix(mat_c, 3);
}
END_TEST

//Сумма произвольных матриц
START_TEST(sum_random)
{
    double mat_a[3][2] = { { 1, -1 }, { 2, -2 }, { 3, -3 } };
    double mat_b[3][2] = { { 3, 3 }, { 2, 2 }, { 1, 1 } };
    double ans[3][2] = { { 4, 2 }, { 4, 0 }, { 4, -2 } };
    double *pa[3] = { mat_a[0], mat_a[1], mat_a[2] }, *pb[3] = { mat_b[0], mat_b[1], mat_b[2] }, *pans[3] = { ans[0], ans[1], ans[2] };
    double **mat_c = sum_matrix(pa, pb, 3, 2);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 3, 2));
    free_matrix(mat_c, 3);
}
END_TEST

Suite* check_sum(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("sum_matrixes");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, sum_one_on_one);
    tcase_add_test(tests, sum_one_on_one_float);
    tcase_add_test(tests, sum_one_row);
    tcase_add_test(tests, sum_one_col);
    tcase_add_test(tests, sum_random);

    suite_add_tcase(s, tests);

    return s;
}