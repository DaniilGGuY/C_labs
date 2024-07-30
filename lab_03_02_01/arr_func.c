#include <stdio.h>
#include <stdlib.h>
#include "arr_func.h"


int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Input size of matrix\n");
    if (scanf("%zu %zu", n, m) != 2)
        return ERR_INPUT;

    if (*n < 1 || *m < 1 || *n > N || *m > M)
        return ERR_RANGE;

    for (size_t i = 0; i < *n; ++i)
        for (size_t j = 0; j < *m; ++j)
        {
            printf("Input element\n");
            if (scanf("%d", &matrix[i][j]) != 1)
                return ERR_INPUT;
        }

    return OK;
}


int calc_sum(int val)
{
    int sum = 0;
    while (val != 0)
    {
        sum += val % 10;
        val /= 10;
    }

    return sum;
}


void find_el(int matrix[][M], size_t n, size_t m, size_t *ind_row, size_t *ind_col)
{
    *ind_row = 0;
    *ind_col = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (calc_sum(abs(matrix[*ind_row][*ind_col])) > calc_sum(abs(matrix[i][j])))
            {
                *ind_row = i;
                *ind_col = j;
            }
}


void delete_by_ind(int arr[], size_t *arr_n, size_t ind)
{
    for (size_t i = ind; i < *arr_n - 1; ++i)
        arr[i] = arr[i + 1];

    --(*arr_n);
}


void memcpy_arr(int arr1[], const int arr2[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        arr1[i] = arr2[i];
}


void delete_el_second(int matrix[][M], size_t *n, size_t *m, size_t ind_row, size_t ind_col)
{
    size_t arr_size;
    for (size_t i = 0; i < *n; ++i)
    {
        arr_size = *m;
        delete_by_ind(matrix[i], &arr_size, ind_col);
        if (i >= ind_row + 1)
            memcpy_arr(matrix[i - 1], matrix[i], *m);
    }

    --(*n);
    --(*m);
}


void delete_col(int matrix[][M], size_t n, size_t *m, size_t ind_col)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = ind_col; j < *m - 1; ++j)
            matrix[i][j] = matrix[i][j + 1];

    --(*m);
}


void delete_row(int matrix[][M], size_t *n, size_t m, size_t ind_row)
{
    for (size_t i = ind_row; i < *n - 1; ++i)
        for (size_t j = 0; j < m; ++j)
            matrix[i][j] = matrix[i + 1][j];

    --(*n);
}


void delete_el(int matrix[][M], size_t *n, size_t *m, size_t ind_row, size_t ind_col)
{
    delete_col(matrix, *n, m, ind_col);
    delete_row(matrix, n, *m, ind_row);
}


void print(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

