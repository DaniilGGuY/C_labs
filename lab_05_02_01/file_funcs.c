#include <stdio.h>
#include "defines.h"
#include "file_funcs.h"


int calc_max_and_min(FILE *f, double *max, double *min)
{
    double now;
    if (fscanf(f, "%lf", &now) != 1)
        return ERR_IO;
        
    *min = now;
    *max = now;
    
    while (fscanf(f, "%lf", &now) == 1)
    {
        if (now > *max)
            *max = now;
            
        if (now < *min)
            *min = now;
    }
    
    return !feof(f) ? ERR_IO : OK;
}


int calc_count(FILE *f, double average, size_t *count)
{
    double now;
    *count = 0;
    if (fscanf(f, "%lf", &now) != 1)
        return ERR_IO;
    if (now - average > EPS)
        ++(*count);
    
    while (fscanf(f, "%lf", &now) == 1)
        if (now - average > EPS)
            ++(*count);
    
    return !feof(f) ? ERR_IO : OK;
}

