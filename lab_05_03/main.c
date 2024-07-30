/*
В программе реализованы 3 операции с файлом: создание и заполнение его случайными чсилами, вывод файлаи сортировка пузырьком файла в возрастающем порядке. 
В функциях put_number_by_pos и get_number_by_pos выбран тип long для pos для того, чтобы облегчить работу с большими файлами.
Т.к pos - позиция в файле, то при больших размерах файла и при переносе кода на 16-битную платформу может произойти переполнение при использовании типа int.
Таким образом, тип long обеспечивает эту самую переносимость.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "file_funcs.h"

int main(int argc, char **argv)
{
    FILE *f;
    int rc;
    char *end_ptr;
    size_t count_nums;
    
    if (argc == 4)
    {
        if (!strcmp(argv[1], "c"))
        {
            count_nums = strtol(argv[2], &end_ptr, 10);
            if (!(*end_ptr))
            {
                f = fopen(argv[3], "wb");
                if (f)
                {
                    rc = create_bin_file(f, count_nums);
                    
                    fclose(f);
                }
                else
                    rc = ERR_ARGS;
            }
            else
                rc = ERR_ARGS;
        }
        else
            rc = ERR_ARGS;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "p") == 0)
        {
            f = fopen(argv[2], "rb");
            
            if (f)
            {
                rc = print_file(f);
                fclose(f);
            }
            else
                rc = ERR_ARGS;
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            f = fopen(argv[2], "rb+");
            
            if (f)
            {
                rc = sort_file(f);
                fclose(f);
            }
            else
                rc = ERR_ARGS;
        }
        else
            rc = ERR_ARGS;
    }
    else 
        rc = ERR_ARGS;

    return rc;
}


