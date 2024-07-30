#include <stdio.h>
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


int max_arr(const int array[], size_t n)
{
    int mx = array[0];
    for (size_t i = 1; i < n; ++i)
        if (array[i] > mx)
            mx = array[i];

    return mx;
}


void swap(int arr1[], int arr2[], size_t n)
{
    int tmp;
    for (size_t i = 0; i < n; ++i)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}


void sort(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = 0; j < n - 1 - i; ++j)
            if (max_arr(matrix[j], m) < max_arr(matrix[j + 1], m))
                swap(matrix[j], matrix[j + 1], m);
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
