#include "file_funcs.h"
#include "memory_funcs.h"
#include "error_codes.h"


static void fill_matrix(double **tmp, size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            tmp[i][j] = 0;
}

int input_matrix(FILE *f, double ***data, size_t *n, size_t *m)
{
    double **tmp;
    if (fscanf(f, "%zu %zu", n, m) != 2 || *n == 0 || *m == 0)
        return ERR_IO;

    tmp = allocate_matrix(*n, *m);
    if (tmp)
    {
        for (size_t i = 0; i < *n; ++i)
            for (size_t j = 0; j < *m; ++j)
                if (fscanf(f, "%lf", &tmp[i][j]) != 1)
                {
                    free_matrix(tmp, *n);
                    return ERR_IO;
                }
    }
    else
        return ERR_MEM;

    *data = tmp;

    return ERR_OK;
}

int input_matrix_coord(FILE *f, double ***data, size_t *n, size_t *m)
{
    size_t col_non_null_el, row, column;
    double el;
    double **tmp;
    if (fscanf(f, "%zu %zu %zu", n, m, &col_non_null_el) != 3 || *n == 0 || *m == 0)
        return ERR_IO;

    tmp = allocate_matrix(*n, *m);
    if (tmp)
    {           
        fill_matrix(tmp, *n, *m);
        for (size_t i = 0; i < col_non_null_el; ++i)
        {
            if (fscanf(f, "%zu %zu %lf", &row, &column, &el) != 3 || row > *n || column > *m || row == 0 || column == 0)
            {
                free_matrix(tmp, *n);
                return ERR_IO;
            }

            tmp[row - 1][column - 1] = el;
        }

        *data = tmp;
    }
    else
        return ERR_MEM;

    return ERR_OK;
}

void print_matrix(FILE *f, double **data, size_t n, size_t m)
{
    fprintf(f, "%zu %zu\n", n, m);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
            fprintf(f, "%lf ", data[i][j]);

        fprintf(f, "\n");
    }
}
