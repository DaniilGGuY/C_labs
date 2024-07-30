#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_lib.h"
#include "error_codes.h"


int main(int argc, char **argv)
{
    FILE *in_file, *out_file;
    int rc = ERR_OK;
    size_t size;
    int *arr_beg = NULL, *arr_end = NULL, *arr_filt_beg = NULL, *arr_filt_end = NULL;

    if (argc == 3 || argc == 4)
    {
        in_file = fopen(argv[1], "r");
        if (in_file)
        {
            rc = read_elems_count(in_file, &size);
            if (size == 0)
                rc = ERR_IO;
            if (!rc)
            {
                rewind(in_file);
                arr_beg = malloc(size * sizeof(int));

                if (arr_beg)
                {
                    arr_end = arr_beg + size;
                    rc = read_elems(in_file, arr_beg, arr_end);
                    if (!rc)
                    {
                        if (argc == 4) 
                        {
                            if (strcmp(argv[3], "f") == 0)
                            {
                                arr_filt_beg = malloc(size * sizeof(int));
                                if (arr_filt_beg)
                                    rc = key(arr_beg, arr_end, &arr_filt_beg, &arr_filt_end);
                                else
                                    rc = ERR_MEM;
                            }
                            else
                                rc = ERR_ARGS;
                        }
                        else 
                        {
                            arr_filt_beg = arr_beg;
                            arr_filt_end = arr_end;
                        }
                    }
                    
                    if (!rc)
                    {
                        mysort(arr_filt_beg, arr_filt_end - arr_filt_beg, sizeof(*arr_filt_beg), uni_cmp);
                        out_file = fopen(argv[2], "w"); 
                        if (out_file)
                        {
                            write_elems(out_file, arr_filt_beg, arr_filt_end);
                            fclose(out_file);
                        }
                    }

                    if (arr_filt_beg != arr_beg)
                        free(arr_filt_beg);
                    free(arr_beg);
                }
                else
                    rc = ERR_MEM;
            }

            fclose(in_file);
        }
        else
            rc = ERR_ARGS;
    }
    else
        rc = ERR_ARGS;
    
    return rc;
}
