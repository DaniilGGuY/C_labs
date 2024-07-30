#include "file_funcs.h"
#include <stdlib.h>
#include "error_codes.h"

int read_elems_count(FILE *f, size_t *count)
{
    int el, rc = ERR_OK;
    *count = 0;
    while (fscanf(f, "%d", &el) == 1)
        ++(*count);

    if (!feof(f))
        rc = ERR_IO;

    return rc;
}

int read_elems(FILE *f, int *const pbeg, int *const pend)
{
    for (int *pcur = pbeg; pcur < pend; ++pcur)
        if (fscanf(f, "%d", pcur) != 1)
            return ERR_IO;

    return ERR_OK;
}

void write_elems(FILE *f, const int *const pbeg, const int *const pend)
{
    for (const int *pcur = pbeg; pcur < pend; ++pcur)
        fprintf(f, "%d ", *pcur);
}
