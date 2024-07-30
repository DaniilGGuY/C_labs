#include <stdio.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][N];
    size_t n, m;
    int rc = input(matrix, &n, &m);
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

    if (m != n)
    {
        printf("Matrix rectangular, but expected square\n");
        return ERR_INPUT;
    }

    swap(matrix, n);
    print(matrix, n, m);

    return OK;
}
