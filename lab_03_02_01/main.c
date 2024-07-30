#include <stdio.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][M];
    size_t n, m, ind_row, ind_col;
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

    find_el(matrix, n, m, &ind_row, &ind_col);
    delete_el_second(matrix, &n, &m, ind_row, ind_col);

    if (n == 0 || m == 0)
    {
        printf("Deleted all elements from matrix");
        return ERR_RESULT;
    }

    print(matrix, n, m);

    return OK;
}
