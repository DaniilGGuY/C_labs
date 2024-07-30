#include <stdlib.h>

#include "memory_funcs.h"

void free_matrix(double **data, size_t n)
{
    free(data[n]);
    free(data);
}

double **allocate_matrix(size_t n, size_t m)
{
    double **ptrs, *data;

    ptrs = malloc((n + 1) * sizeof(double*));
    if (!ptrs)
        return NULL;

    data = malloc(n * m * sizeof(double));
    if (!data)
    {
        free(ptrs);

        return NULL;
    }

    for (size_t i = 0; i < n; i++)
        ptrs[i] = data + i * m;
    
    ptrs[n] = data;

    return ptrs;
}

/*
double **allocate_matrix(size_t n, size_t m)
{
    double **data = calloc(n * sizeof(double*) + n * m * sizeof(double), sizeof(char));
    if (!data)
        return NULL;
 
    for (size_t i = 0; i < n; i++)
        data[i] = (double*)((char*) data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}
*/