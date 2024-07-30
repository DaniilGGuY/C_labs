#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "student.h"
#include "bin_file_funcs.h"

int file_sort(FILE *f)
{
    long pos_in_file, pos;
    struct student left, right;
    int rc;
    
    if (fseek(f, 0, SEEK_END))
        return ERR_FILE;
    if ((pos_in_file = ftell(f)) == -1L)
        return ERR_FILE;
    if (pos_in_file % sizeof(struct student))
        return ERR_IO;
    pos = pos_in_file / sizeof(struct student);
    if (pos <= 0)
        return ERR_COL;
        
    for (long i = 0; i < pos - 1; ++i)
    {         
        for (long j = 0; j < pos - i - 1; ++j)
        {        
            rc = get_by_pos(f, j, &left);
            if (rc)
                return rc;
            rc = get_by_pos(f, j + 1, &right);
            if (rc)
                return rc;
                
            if (cmp_studs(&right, &left) < 0)
            {
                rc = put_by_pos(f, j, &right);
                if (rc)
                    return rc;
                rc = put_by_pos(f, j + 1, &left);
                if (rc)
                    return rc;
            }
        }
    }

    return OK;
}


int get_by_pos(FILE *f, long pos, struct student *stud)
{
    long pos_in_file = pos * sizeof(struct student);
    if (fseek(f, pos_in_file, SEEK_SET))
        return ERR_FILE;
        
    if (fread(stud, sizeof(struct student), 1, f) != 1)
        return ERR_FILE;
    
    return OK;
}


int put_by_pos(FILE *f, long pos, const struct student *stud)
{
    long pos_in_file = pos * sizeof(struct student);
    if (fseek(f, pos_in_file, SEEK_SET))
        return ERR_FILE;
        
    if (fwrite(stud, sizeof(struct student), 1, f) != 1)
        return ERR_FILE;
        
    return OK;
}

