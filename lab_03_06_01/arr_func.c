#include <stdio.h>
#include "arr_func.h"


int input(size_t *n, size_t *m)
{
    printf("Input size of matrix\n");
    if (scanf("%zu %zu", n, m) != 2)
        return ERR_INPUT;

    if (*n < 1 || *m < 1 || *n > N || *m > M)
        return ERR_RANGE;

    return OK;
}


void fill(int matrix[][M], size_t n)
{
    int x = 0, y = 0, dx = 1, dy = 0, tmp; // (x, y) - координаты, куда вставлять, (dx, dy) - приращения для перехода к следующему элементу матрицы по спирали
    for (size_t i = 0; i < n * n; ++i)
    {
        matrix[y][x] = i + 1; // заполняем очередным числом
        
        // Если при добавлении приращений координата выходит за границу матрицы или же в новых координатах записан ненулевой элемент
        if (x + dx < 0 || x + dx == (int)n || y + dy < 0 || y + dy == (int)n || matrix[y + dy][x + dx] != 0)
        {
            tmp = dx; // Меняем направление (приращения меняются следующим образом (1, 0) -> (0, 1) -> (-1, 0) -> (0, -1), что позволяет обходить матрицу по спирали)
            dx = -dy;
            dy = tmp;
        }

        x += dx; // Переходим к следующему элементу в спирали
        y += dy;
    }
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

