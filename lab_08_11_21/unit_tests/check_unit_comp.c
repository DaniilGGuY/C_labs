#include "check_head.h"
#include "memory_funcs.h"
#include <stdlib.h>
#include <math.h>

#define EPS          1e-9

// сравнивает две матрицы с заданными размерами и возвращает 1, если они равны и 0 в обратном случае
int matrix_cmp(double **mat_a, double **mat_b, size_t n, size_t m)
{
    if (!mat_a || !mat_b)
        return 0;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (fabs(mat_a[i][j] - mat_b[i][j]) > EPS)
                return 0;

    return 1;
}

//Проверка умножения одного элемента на другой
START_TEST(comp_one_on_one)
{
    double mat_a[1][1] = { { 1 } };
    double mat_b[1][1] = { { -1 } };
    double ans[1][1] = { { -1 } };
    double *pa[1] = { mat_a[0] }, *pb[1] = { mat_b[0] }, *pans[1] = { ans[0] };
    double **mat_c = comp_matrix(pa, pb, 1, 1, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 1));
    free_matrix(mat_c, 1);
}
END_TEST

//Проверка умножения одного элемента на другой вещественные числа
START_TEST(comp_one_on_one_float)
{
    double mat_a[1][1] = { { 1.1 } };
    double mat_b[1][1] = { { -1.1 } };
    double ans[1][1] = { { -1.21 } };
    double *pa[1] = { mat_a[0] }, *pb[1] = { mat_b[0] }, *pans[1] = { ans[0] };
    double **mat_c = comp_matrix(pa, pb, 1, 1, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 1));
    free_matrix(mat_c, 1);
}
END_TEST

//Проверка умножения строки на столбец
START_TEST(comp_row_on_col)
{
    double mat_a[1][2] = { { 1, 2 } };
    double mat_b[2][1] = { { 3 }, { 2 } };
    double ans[1][1] = { { 7 } };
    double *pa[1] = { mat_a[0] }, *pb[2] = { mat_b[0], mat_b[1] }, *pans[1] = { ans[0] };
    double **mat_c = comp_matrix(pa, pb, 1, 2, 1);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 1, 1));
    free_matrix(mat_c, 1);
}
END_TEST

//Проверка умножения столбца на строку
START_TEST(comp_col_on_row)
{
    double mat_a[1][2] = { { 1, 2 } };
    double mat_b[2][1] = { { 3 }, { 2 } };
    double ans[2][2] = { { 3, 6 }, { 2, 4 } };
    double *pa[1] = { mat_a[0] }, *pb[2] = { mat_b[0], mat_b[1] }, *pans[2] = { ans[0], ans[1] };
    double **mat_c = comp_matrix(pb, pa, 2, 1, 2);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 2, 2));
    free_matrix(mat_c, 2);
}
END_TEST

//Проверка умножения произвольных матриц
START_TEST(comp_random)
{
    double mat_a[3][2] = { { 1, -1 }, { 2, -2 }, { 3, -3 } };
    double mat_b[2][3] = { { 3, 2, 1 }, { 3, 2, 1 } };
    double ans[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
    double *pa[3] = { mat_a[0], mat_a[1], mat_a[2] }, *pb[2] = { mat_b[0], mat_b[1] }, *pans[3] = { ans[0], ans[1], ans[2] };
    double **mat_c = comp_matrix(pa, pb, 3, 2, 3);

    ck_assert_int_eq(1, matrix_cmp(pans, mat_c, 3, 3));
    free_matrix(mat_c, 3);
}
END_TEST

Suite* check_comp(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("comp_matrixes");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, comp_one_on_one);
    tcase_add_test(tests, comp_one_on_one_float);
    tcase_add_test(tests, comp_row_on_col);
    tcase_add_test(tests, comp_col_on_row);
    tcase_add_test(tests, comp_random);

    suite_add_tcase(s, tests);

    return s;
}