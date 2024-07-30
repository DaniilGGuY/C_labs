#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "my_lib.h"

int uni_cmp(const void *l, const void *r, size_t size)
{
    const char *pl = l;
    const char *pr = r;
    for (size_t i = 0; i < size; ++i)
    {
        if (pl[i] < pr[i])
            return -1;
        else if (pl[i] > pr[i])
            return 1;
    }

    return 0;
}

void find_pos(const int *pb_src, const int **ind)
{
    while (*ind >= pb_src && **ind >= 0)
        --(*ind);
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    const int *ind = pe_src - 1;
    int rc = ERR_OK;
    if (pb_src == pe_src)
        rc = ERR_EMPTY;
    else
    {
        find_pos(pb_src, &ind);

        if (ind != pb_src)
        {
            if (ind < pb_src)
                ind = (int*)pe_src;
            
            if (*pb_dst && *pb_dst + (ind - pb_src))
            {
                *pe_dst = *pb_dst + (ind - pb_src);
                memcpy(*pb_dst, pb_src, (ind - pb_src) * sizeof(int));
            }
            else
                rc = ERR_PARAM;
        }
        else
            rc = ERR_RES;
    }

    return rc;
}

void swap(void *l, void *r, size_t elem_size)
{
    char tmp;
    char *pl = l;
    char *pr = r;
    for (size_t i = 0; i < elem_size; ++i, ++pl, ++pr)
    {
        tmp = *pl;
        *pl = *pr;
        *pr = tmp;
    }
}

void mysort(void *base, size_t num, size_t size, comp_t comp)
{
    char *pos_l = base, *pos_r = pos_l + (num - 1) * size, *last_swap = NULL;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (char *left = pos_l, *right = pos_l + size; left < pos_r; left += size, right += size)
            if (comp(left, right, size) > 0)
            {
                sorted = false;
                last_swap = left;
                swap(left, right, size);
            }
        pos_r = last_swap;

        for (char *right = pos_r, *left = pos_r - size; right > pos_l; right -= size, left -= size)
            if (comp(left, right, size) > 0)
            {
                last_swap = right;
                swap(left, right, size);
            }
        pos_l = last_swap;
    }
}

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
