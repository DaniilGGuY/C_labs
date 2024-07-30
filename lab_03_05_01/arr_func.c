#include <stdio.h>
#include <stdbool.h>
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


void form_array(int matrix[][M], size_t n, size_t m, int arr[], size_t *len)
{
    *len = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (calc_sum(abs(matrix[i][j])) > 10)
            {
                arr[*len] = matrix[i][j];
                *len += 1;
            }
}


void reverse_array(int *arr, size_t size)
{
    int tmp;
    for (size_t i = 0; i < size / 2; ++i)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}


void shift_array(int arr[], size_t n, int shift)
{
    if (shift < 0)
        shift = n - abs(shift) % n;
    else
        shift = shift % n;

    reverse_array(arr, shift);
    reverse_array(arr + shift, n - shift);
    reverse_array(arr, n);
}


void put_elements(int matrix[][M], size_t n, size_t m, int arr[])
{
    int now = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (calc_sum(abs(matrix[i][j])) > 10)
            {
                matrix[i][j] = arr[now];
                now += 1;
            }
}


void print(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix\n");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}
