#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "defines.h"
#include "file_funcs.h"


int create_bin_file(FILE *f, size_t number)
{
    srand(time(NULL));
    
    int num;
    
    for (size_t i = 0; i < number; ++i)
    {
        num = rand();
        if (fwrite(&num, sizeof(int), 1, f) != 1)
            return ERR_FILE;       
    }
    
    return OK;
}


int print_file(FILE *f)
{
    int val, col = 0;
    while (fread(&val, sizeof(val), 1, f))
    {
        col += 1;
        printf("%d\n", val);
    }
    
    if (col == 0)
        return ERR_COL;
    
    return feof(f) ? OK : ERR_IO;
}


int get_number_by_pos(FILE *f, long pos, int *val)
{
    long pos_in_file = pos * sizeof(*val);

    if (fseek(f, pos_in_file, SEEK_SET))
        return ERR_FILE;
        
    if (fread(val, sizeof(*val), 1, f) != 1)
        return ERR_IO;
        
    return OK;
}


int put_number_by_pos(FILE *f, long pos, const int *val)
{   
    long pos_in_file = pos * sizeof(*val);
    
    if (fseek(f, pos_in_file, SEEK_SET))
        return ERR_FILE;
        
    if (fwrite(val, sizeof(*val), 1, f) != 1)
        return ERR_IO;
        
    return OK;
}


int sort_file(FILE *f)
{
    long pos_in_file, pos;
    int left, right, rc, tmp;
    if (fseek(f, 0, SEEK_END))
        return ERR_FILE;
        
    if ((pos_in_file = ftell(f)) == -1L)
        return ERR_FILE;

    pos = pos_in_file / sizeof(int);
    
    if (pos <= 0)
        return ERR_COL;

    for (long i = 0; i < pos - 1; ++i)
    {
        for (long j = 0; j < pos - i - 1; ++j)
        {
            rc = get_number_by_pos(f, j, &left);    
            if (rc)
                return rc;
            rc = get_number_by_pos(f, j + 1, &right);
            if (rc)
                return rc;
                
            if (right < left)
            {
                tmp = right;
                right = left;
                left = tmp;
                rc = put_number_by_pos(f, j, &left);
                if (rc)
                    return rc;
                rc = put_number_by_pos(f, j + 1, &right);
                if (rc)
                    return rc;
            }
        }
    }
    
    return OK;
}

