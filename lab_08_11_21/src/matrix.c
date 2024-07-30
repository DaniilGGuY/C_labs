#include <math.h>
#include <stdlib.h>

#include "matrix.h"
#include "memory_funcs.h"
#include "error_codes.h"

#define EPS             1e-7

double **sum_matrix(double **mat_a, double **mat_b, size_t n, size_t m)
{
    double **mat_sum = allocate_matrix(n, m);

    if (mat_sum)
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
                mat_sum[i][j] = mat_a[i][j] + mat_b[i][j];

    return mat_sum;
}

double **comp_matrix(double **mat_a, double **mat_b, size_t na, size_t nb, size_t mb)
{
    double **mat_comp = allocate_matrix(na, mb);
    double el;
    if (mat_comp)
        for (size_t i = 0; i < na; ++i)
            for (size_t j = 0; j < mb; ++j)
            {
                el = 0.0;
                for (size_t k = 0; k < nb; ++k)
                    el += mat_a[i][k] * mat_b[k][j];

                mat_comp[i][j] = el;
            }
            
    return mat_comp;
}

// Функция меняет местами указатели first и second
static void swap_rows(double **first, double **second)
{
    double *tmp = *first;
    *first = *second;
    *second = tmp;
}

// Функция меняет местами элементы с индексами ind_first и ind_sec в массиве arr
static void swap_elems(int *arr, size_t ind_first, size_t ind_sec)
{
    double tmp = arr[ind_first];
    arr[ind_first] = arr[ind_sec];
    arr[ind_sec] = tmp;
}

// Функция меняет местами столбцы с индексами ind_first и ind_sec в матрице mat_a с количеством строк na
static void swap_column(double **mat_a, size_t ind_first, size_t ind_sec, size_t na)
{
    double tmp;
    for (size_t i = 0; i < na; ++i)
    {
        tmp = mat_a[i][ind_first];
        mat_a[i][ind_first] = mat_a[i][ind_sec];
        mat_a[i][ind_sec] = tmp;
    }
}

static void find_main_num(double **data, size_t na, size_t k, size_t *max_row_ind, size_t *max_col_ind)
{
    for (size_t i = k + 1; i < na; ++i)
    {
        for (size_t j = k + 1; j < na; ++j)
        {
            if (fabs(data[i][j]) > fabs(data[*max_row_ind][*max_col_ind]))
            {
                *max_col_ind = j;
                *max_row_ind = i;
            }
        }
    }
}

double **get_roots(double **mat_a, size_t na, size_t ma)
{
    int *ind = malloc(na * sizeof(int));  // массив с индексами столбцов слау
    double **ans = allocate_matrix(na, 1);  // столбец корней
    size_t max_row_ind, max_col_ind;
    double coef;
    int rc = ERR_OK;

    if (!ind && ans)
        free_matrix(ans, na);
    if (!ans && ind)
        free(ind);

    if (ind && ans)
    {
        for (size_t j = 0; j < ma - 1; ++j)
            ind[j] = j;  // запоминаем позиции переменных в слау
        // цикл преобразования слау к диагональному виду
        for (size_t k = 0; k < na && !rc; ++k)
        {
            max_col_ind = k;
            max_row_ind = k;
            // выбор ведущего элемента
            find_main_num(mat_a, na, k, &max_row_ind, &max_col_ind);
            // перестановка ведущего элемента в верхний левый угол активной подматрицы
            swap_column(mat_a, k, max_col_ind, na);
            swap_elems(ind, k, max_col_ind);
            swap_rows(mat_a + k, mat_a + max_row_ind);
            // приведение к диагональному виду
            if (fabs(mat_a[k][k]) < EPS)
                rc = ERR_RES;

            for (size_t i = k + 1; i < na && !rc; ++i)
            {
                coef = mat_a[i][k] / mat_a[k][k];
                for (size_t j = k; j < ma; ++j)
                    mat_a[i][j] -= coef * mat_a[k][j];
            }
        }
        // обратный ход алгоритма, нахождение корней
        for (int i = na - 1; i >= 0 && !rc; --i)
        {
            if (fabs(mat_a[i][i]) < EPS)
            {
                rc = ERR_RES;
                break;
            }
            
            ans[ind[i]][0] = mat_a[i][na] / mat_a[i][i];
            for (size_t j = i + 1; j < na; ++j)
                ans[ind[i]][0] -= mat_a[i][j] * ans[ind[j]][0] / mat_a[i][i];
        }
        // очищаем память в случае ошибки
        free(ind);
        if (rc)
            free_matrix(ans, na);
    }
    
    if (rc)
        return NULL;

    return ans;
}
