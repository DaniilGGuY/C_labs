#include <stdio.h>
#include "file_funcs.h"
#include "defines.h"


int process(FILE *f, size_t *col)
{
    int prev, next;
    *col = 0;
    
    if (fscanf(f, "%d %d", &prev, &next) != 2)
        return ERR_IO; 
        
    do
    {
        if ((prev < 0 && next >= 0) || (prev >= 0 && next < 0))
            *col += 1;
            
        prev = next;
    }
    while (fscanf(f, "%d", &next) == 1);
    
    return OK;
}

