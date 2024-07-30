#include <stdio.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][N];
    size_t n, m;
    int el;
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

    el = find_el(matrix, n);
    if (el == 0)
    {
        printf("Incorrect input/ You need to input one more need element");
        return ERR_INPUT;
    }

    printf("Element: %d\n", el);
    return OK;
}
