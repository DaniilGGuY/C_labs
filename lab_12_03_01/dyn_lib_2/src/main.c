#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "error_codes.h"

typedef int (*read_col)(FILE *, size_t *);
typedef int (*reader)(FILE *, int *, int *);
typedef void (*writer)(FILE *, const int *, const int *);
typedef int (*cmp)(const void *, const void *, size_t);
typedef int (*key)(const int *, const int *, int **, int **);
typedef void (*sort)(void *, size_t , size_t , cmp);

int main(int argc, char **argv)
{
    FILE *in_file = NULL, *out_file = NULL;
    int rc = ERR_OK;
    size_t size = 0;
    int *arr_beg = NULL, *arr_end = NULL, *arr_filt_beg = NULL, *arr_filt_end = NULL;
    read_col read_num_of_els;
    reader read_els;
    writer write_els;
    key filter;
    sort sorted;
    cmp uni_cmp;
    void *hlib = NULL;

    if (argc != 4 && argc != 5)
        rc = ERR_ARGS;

    if (!rc)
    {
        hlib = dlopen(argv[1], RTLD_NOW);
        if (!hlib)
            rc = ERR_LIB;
    }

    if (!rc)
    {
        in_file = fopen(argv[2], "r");
        if (!in_file)
            rc = ERR_ARGS;
    }
    
    if (!rc)
    {
        read_num_of_els = (read_col)dlsym(hlib, "read_elems_count");
        if (!read_num_of_els)
            rc = ERR_LIB;
        else
            rc = read_num_of_els(in_file, &size);
    }
    
    if (!rc && size == 0)
        rc = ERR_IO;
    
    if (!rc)
    {
        rewind(in_file);
        arr_beg = malloc(size * sizeof(int));
        if (!arr_beg)
            rc = ERR_MEM;
    }
    
    if (!rc)
    {
        arr_end = arr_beg + size;
        read_els = (reader)dlsym(hlib, "read_elems");
        if (!read_els)
            rc = ERR_LIB;
        else
            rc = read_els(in_file, arr_beg, arr_end);
    }
    
    if (!rc)
    {
        if (argc == 5)
        {
            if (strcmp(argv[4], "f") == 0)
            {
                arr_filt_beg = malloc(size * sizeof(int));
                if (arr_filt_beg)
                {
                    filter = (key)dlsym(hlib, "key");
                    if (!filter)
                        rc = ERR_LIB;
                    else
                        rc = filter(arr_beg, arr_end, &arr_filt_beg, &arr_filt_end);
                }
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
        sorted = (sort)dlsym(hlib, "mysort");
        if (!sorted)
            rc = ERR_LIB;
        else
        {
            uni_cmp = (cmp)dlsym(hlib, "uni_cmp");
            if (!uni_cmp)
                rc = ERR_LIB;
            else
                sorted(arr_filt_beg, arr_filt_end - arr_filt_beg, sizeof(*arr_filt_beg), uni_cmp);
        }
    }
    
    if (!rc)
    {
        out_file = fopen(argv[3], "w"); 
        if (!out_file)
            rc = ERR_ARGS;
    }

    if (!rc)
    {
        write_els = (writer)dlsym(hlib, "write_elems");
        if (!write_els)
            rc = ERR_LIB;
        else
            write_els(out_file, arr_filt_beg, arr_filt_end);
    }
    
    if (out_file)
        fclose(out_file);

    if (in_file)
        fclose(in_file);

    if (arr_beg)
    {
        if (arr_filt_beg && arr_filt_beg != arr_beg)
            free(arr_filt_beg);

        free(arr_beg);
    }

    if (hlib)
        dlclose(hlib);
    
    return rc;
}
