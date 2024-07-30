#include <stdio.h>
#include <string.h>
#include "student.h"
#include "bin_file_funcs.h"
#include "txt_file_funcs.h"
#include "defines.h"

int main(int argc, char **argv)
{
    FILE *src, *dst, *f;
    int rc = OK;
    struct student studs[STUD_COUNT];
    size_t stud_col;
    if (argc == 3)
    {
        if (strcmp(argv[1], "sb") == 0)
        {
            f = fopen(argv[2], "rb+");
            if (f)
            {
                rc = file_sort(f);
                    
                fclose(f);
            }
            else
                rc = ERR_FILE;
        }
        else
            rc = ERR_ARGS;
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "ft") == 0)
        {
            src = fopen(argv[2], "r");
            if (src)
            {
                rc = read_studs(src, studs, &stud_col);
                fclose(src);
                if (!rc)
                {
                    dst = fopen(argv[3], "w");
                    if (dst)
                    {
                        rc = file_substr_print(dst, studs, stud_col, argv[4]);
                        
                        fclose(dst);
                    }
                    else
                        rc = ERR_FILE;
                }
            }
            else
                rc = ERR_FILE;
        }
        else
            rc = ERR_ARGS;
    }
    else 
        rc = ERR_ARGS;
       
    return rc;
}
