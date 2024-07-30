#include "arr_funcs.h"
#include <stdbool.h>
#include <string.h>
#include "error_codes.h"
#include <stdlib.h>

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

static void find_pos(const int *pb_src, const int **ind)
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
            *pb_dst = malloc((ind - pb_src) * sizeof(int));
            if (*pb_dst)
            {
                *pe_dst = *pb_dst + (ind - pb_src);
                memcpy(*pb_dst, pb_src, (ind - pb_src) * sizeof(int));
            }
            else
                rc = ERR_MEM;
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
