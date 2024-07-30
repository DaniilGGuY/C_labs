#include "check_head.h"
#include "memory_funcs.h"
#include "error_codes.h"
#include <stdlib.h>
#include <math.h>

#define EPS          1e-9

//Одно уравнение с кррнем
START_TEST(one_equation)
{
    double mat[1][2] = { { 1, 2 } };
    double ans[1][1] = { { 2 } };
    double *pmat[1] = { mat[0] }; 
    double *pans[1] = { ans[0] };
    double **solve = get_roots(pmat, 1, 2);

    ck_assert_int_eq(1, matrix_cmp(pans, solve, 1, 1));
    free_matrix(solve, 1);
}
END_TEST

//Два уравнения с корнями
START_TEST(two_equation)
{
    double mat[2][3] = { { 1, 2, 5 }, { 3, 1, 5 } };
    double ans[2][1] = { { 1 }, { 2 } };
    double *pmat[2] = { mat[0], mat[1] }; 
    double *pans[2] = { ans[0], ans[1] };
    double **solve = get_roots(pmat, 2, 3);

    ck_assert_int_eq(1, matrix_cmp(pans, solve, 2, 1));
    free_matrix(solve, 2);
}
END_TEST

//Три уравнения с корнями
START_TEST(three_equation)
{
    double mat[3][4] = { { 1, 2, 3, 10 }, { 3, 1, 5, 16 }, { 0, 4, 2, 10 } };
    double ans[3][1] = {  { 3 }, { 2 }, { 1  } };
    double *pmat[3] = { mat[0], mat[1], mat[2] }; 
    double *pans[3] = { ans[0], ans[1], ans[2] };
    double **solve = get_roots(pmat, 3, 4);

    ck_assert_int_eq(1, matrix_cmp(pans, solve, 3, 1));
    free_matrix(solve, 3);
}
END_TEST

//Бесконечное количество решений
START_TEST(inf_solve)
{
    double mat[1][2] = { { 0, 0 } };
    double *pmat[1] = { mat[0] }; 
    double **solve = get_roots(pmat, 1, 2);

    ck_assert_int_eq(1, (solve ? 0 : 1));
}
END_TEST

//Решений нет
START_TEST(none_solve)
{
    double mat[1][2] = { { 0, 1 } };
    double *pmat[1] = { mat[0] }; 
    double **solve = get_roots(pmat, 1, 2);

    ck_assert_int_eq(1, (solve ? 0 : 1));
}
END_TEST

//Одно уравнение с вещественным корнем
START_TEST(one_equation_float)
{
    double mat[1][2] = { { 1, 2.2 } };
    double ans[1][1] = { { 2.2 } };
    double *pmat[1] = { mat[0] }; 
    double *pans[1] = { ans[0] };
    double **solve = get_roots(pmat, 1, 2);

    ck_assert_int_eq(1, matrix_cmp(pans, solve, 1, 1));
    free_matrix(solve, 1);
}
END_TEST

Suite* check_slau(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("slau_solve");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, one_equation);
    tcase_add_test(tests, two_equation);
    tcase_add_test(tests, three_equation);
    tcase_add_test(tests, inf_solve);
    tcase_add_test(tests, none_solve);
    tcase_add_test(tests, one_equation_float);

    suite_add_tcase(s, tests);

    return s;
}