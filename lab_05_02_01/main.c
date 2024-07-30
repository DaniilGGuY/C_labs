#include <stdio.h>
#include "defines.h"
#include "file_funcs.h"

int main(int argc, char **argv)
{
    FILE *f;
    double max, min, average;
    size_t count;
    int rc = 0;
    
    if (argc != 2)
    {
        printf("app.exe <name_of_file>\n");
        rc = ERR_ARGS;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            rc = calc_max_and_min(f, &max, &min);
            average = (max + min) / 2;
            if (rc == OK)
            {
                rewind(f);
                
                rc = calc_count(f, average, &count);
                if (rc == OK)
                    printf("The answer is %zu\n", count);
                else if (rc == ERR_IO)
                    printf("It isn`t double value. Maybe the file is corrupted\n");
                else
                    printf("There is another type of error\n");
            }
            else if (rc == ERR_IO)
                printf("It isn`t double value\n");
            else
                printf("There is another type of error\n");
            
            fclose(f);
        }
        else
        {
            printf("There is problems with reading file\n");
            rc = ERR_FILE;
        }
    }
    
    return rc;
}
