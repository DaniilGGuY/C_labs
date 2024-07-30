#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "student.h"
#include "txt_file_funcs.h"


int read_studs(FILE *src, struct student studs[], size_t *stud_col)
{
    *stud_col = 0;
    while (!stud_read(src, studs + *stud_col))
        (*stud_col)++;
    
    if (*stud_col == 0)
        return ERR_IO;
        
    return OK;
}


int file_substr_print(FILE *dst, const struct student studs[], size_t studs_col, const char *substr)
{
    size_t col = 0;
    for (size_t i = 0; i < studs_col; ++i)
    { 
        if (strncmp(substr, studs[i].surname, strlen(substr)) == 0)
        {
            stud_print(dst, studs + i);
            col += 1;
        }
    }
    
    if (col == 0)
        return ERR_IO;
        
    return OK;
}

