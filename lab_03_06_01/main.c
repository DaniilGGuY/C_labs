#include <stdio.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][N] = { 0 }; // инициализация нужна для корректного заполнения
    size_t n, m;
    int rc = input(&n, &m);
    if (rc)
    {
        switch (rc)
        {
            case ERR_INPUT:
                printf("Incorrect input of entered value\n");
                return rc;
            case ERR_RANGE:
                printf("Incorrect range of size\n");
                return rc;
            default:
                printf("Another type of error\n");
                return rc;
        }
    }
    
    if (n != m)
    {
        printf("Expected square matrix\n");
        return ERR_INPUT;
    }

    fill(matrix, n);
    print(matrix, n, n);

    return OK;
}
