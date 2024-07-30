#include <stdio.h>
#include <stdbool.h>
#include "arr_func.h"


int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Input size of matrix:\n");
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


bool is_sym(const int arr[], size_t n)
{
    for (size_t i = 0; i < n / 2; ++i)
        if (arr[i] != arr[n - 1 - i])
            return false;

    return true;
}


void form_array(int matrix[][M], size_t n, size_t m, int arr[])
{
    for (size_t i = 0; i < n; ++i)
        if (is_sym(matrix[i], m))
            arr[i] = 1;
        else
            arr[i] = 0;
}


void print_array(const int array[], size_t n)
{
    printf("Desired array\n");
    for (size_t i = 0; i < n; ++i)
        printf("%d ", array[i]);

    printf("\n");
}
