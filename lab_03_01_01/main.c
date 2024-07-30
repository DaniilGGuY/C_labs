#include <stdio.h>
#include <stdbool.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][M];
    int array[N];
    size_t n, m;
    int rc = input(matrix, &n, &m);
    if (rc)
    {
        switch (rc)
        {
            case ERR_INPUT:
                printf("Incorrect input of entered value\n");
            case ERR_RANGE:
                printf("Incorrect range of size\n");
            default:
                printf("Another type of error\n");
        }
        
        return rc;
    }

    form_array(matrix, n, m, array);
    print_array(array, n);

    return OK;
}
