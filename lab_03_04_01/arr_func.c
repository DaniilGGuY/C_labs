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


void swap(int matrix[][N], size_t n)
{
    int tmp; // переменная для перестановки двух элементов
    // обходим половину строк матрицы, обходим элементы лежащие выше главной диагонали и выше побочной включая элементы на диагоналях
    for (size_t i = 0; i < n / 2; ++i)
        for (size_t j = i; j < n - i; ++j)
        {
            // меняем местами элементы с зеркально противоположными относительно оси i
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - i][j];
            matrix[n - 1 - i][j] = tmp;
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
