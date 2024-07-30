#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "memory_funcs.h"
#include "file_funcs.h"
#include "error_codes.h"

int main(int argc, char **argv)
{
    FILE *in_1, *in_2, *out;
    double **mat_a = NULL, **mat_b = NULL, **mat_c = NULL;
    size_t na, ma, nb, mb, nc, mc;
    int rc = ERR_OK;
    if (argc == 4 && strcmp(argv[1], "o") == 0)
    {
        in_1 = fopen(argv[2], "r");
        if (!in_1)
            rc = ERR_FILE;
        if (!rc)
        {
            rc = input_matrix_coord(in_1, &mat_a, &na, &ma);
            fclose(in_1);
        }
        if (!rc)
        {
            if (na == ma - 1)
            {
                mat_c = get_roots(mat_a, na, ma);
                nc = na;
                mc = 1;
            }
            else
                rc = ERR_IO;
        }
        if (!rc)
        {
            out = fopen(argv[3], "w");
            if (!out)
                rc = ERR_FILE;
        }
        if (!rc)
        {
            if (mat_c)
                print_matrix(out, mat_c, nc, mc);  
            else
                rc = ERR_RES;

            fclose(out);
        }

        if (mat_a)
            free_matrix(mat_a, na);
        if (mat_c)
            free_matrix(mat_c, nc);
    }
    else if (argc == 5 && strcmp(argv[1], "m") == 0)
    {
        in_1 = fopen(argv[2], "r");
        if (!in_1)
            rc = ERR_FILE;
        if (!rc)
        {
            rc = input_matrix_coord(in_1, &mat_a, &na, &ma);
            fclose(in_1);
        }
        if (!rc)
        {
            in_2 = fopen(argv[3], "r");
            if (!in_2)
                rc = ERR_FILE;
        }
        if (!rc)
        {
            rc = input_matrix_coord(in_2, &mat_b, &nb, &mb);
            fclose(in_2);
        }
        if (!rc)
        {
            if (ma == nb)
            {
                mat_c = comp_matrix(mat_a, mat_b, na, nb, mb);
                nc = na;
                mc = mb;
            }
            else
                rc = ERR_IO;
        }
        if (!rc)
        {
            out = fopen(argv[4], "w");
            if (!out)
                rc = ERR_FILE;
        }
        if (!rc)
        {
            print_matrix(out, mat_c, nc, mc);
            fclose(out);
        }

        if (mat_a)
            free_matrix(mat_a, na);
        if (mat_b)
            free_matrix(mat_b, nb);
        if (mat_c)
            free_matrix(mat_c, na);
    }
    else if (argc == 5 && strcmp(argv[1], "a") == 0)
    {
        in_1 = fopen(argv[2], "r");
        if (!in_1)
            rc = ERR_FILE;
        if (!rc)
        {
            rc = input_matrix_coord(in_1, &mat_a, &na, &ma);
            fclose(in_1);
        }
        if (!rc)
        {
            in_2 = fopen(argv[3], "r");
            if (!in_2)
                rc = ERR_FILE;
        }
        if (!rc)
        {
            rc = input_matrix_coord(in_2, &mat_b, &nb, &mb);
            fclose(in_2);
        }
        if (!rc)
        {
            if (na == nb && ma == mb)
            {
                mat_c = sum_matrix(mat_a, mat_b, na, ma);
                nc = na;
                mc = ma;
            }
            else
                rc = ERR_IO;
        }
        if (!rc)
        {
            out = fopen(argv[4], "w");
            if (!out)
                rc = ERR_FILE;
        }
        if (!rc)
        {
            print_matrix(out, mat_c, nc, mc);
            fclose(out);
        }

        if (mat_a)
            free_matrix(mat_a, na); 
        if (mat_b)
            free_matrix(mat_b, nb);
        if (mat_c)
            free_matrix(mat_c, nc);
    }
    else
        rc = ERR_ARGS;

    return rc;
}
