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


int find_el(int matrix[][N], size_t n)
{
    int el = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < i; ++j)
            if (matrix[i][j] % 2 != 0 && (el > matrix[i][j] || el == 0))
                el = matrix[i][j];

    return el;
}
