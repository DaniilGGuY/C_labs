#include <stdbool.h>

#include "my_lib.h"

int reverse_part(int *pbeg, int *pend)
{
    if (!pbeg || !pend)
        return ERR_ARGS;

    int tmp;
    while (pbeg < pend)
    {
        tmp = *pbeg;
        *pbeg = *pend;
        *pend = tmp;
        ++pbeg;
        --pend;
    }

    return OK;
}

int cycle_left_shift(int *arr, size_t size, int col)
{
    if (!arr || size <= 0)
        return ERR_ARGS;

    col = (col >= 0 ? col % size : size - (-col) % size);

    reverse_part(arr, arr + col - 1);

    reverse_part(arr + col, arr + size - 1);

    reverse_part(arr, arr + size - 1);

    return OK;
}

bool is_square(int value)
{
    if (value < 0)
        return false;
    else if (value == 0)
        return true;
    
    int i = 1;
    while (i < value / i)
        ++i;

    if (i == value / i && value % i == 0)
        return true;
    
    return false;
}

int filter(int *src, size_t src_len, int *dst, size_t *dst_len)
{
    int n = 0;
    for (int i = 0; i < src_len; ++i)
        if (is_square(src[i]))
            ++n;

    if (n > *dst_len)
    {
        *dst_len = n;

        return REALLOCATED;
    }

    n = 0;
    for (int i = 0; i < src_len; ++i)
        if (is_square(src[i]))
            dst[n++] = src[i];


    *dst_len = n;

    return OK;
}
