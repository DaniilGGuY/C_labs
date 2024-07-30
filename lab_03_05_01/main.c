#include <stdio.h>
#include <stdbool.h>
#include "arr_func.h"

int main(void)
{
    int matrix[N][M];
    int array[N * M];
    size_t n, m, len;
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
    
    form_array(matrix, n, m, array, &len);
    
    if (len == 0)
    {
        printf("Incorrect vals in matrix. Should be one more element with sum more than ten");
        return ERR_VAL;
    }
 
    shift_array(array, len, 3);
    put_elements(matrix, n, m, array);
    print(matrix, n, m);

    return OK;
}
