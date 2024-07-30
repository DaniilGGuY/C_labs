#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arr_films.h"
#include "film.h"
#include "error.h"
#include "constant.h"

int main(int argc, char **argv)
{
    FILE *f;
    struct film_t pfilm[N_MAX];
    struct film_t key_struct;
    size_t n, year;
    int pos = -1;
    int rc = ERR_OK;
    
    if (argc == 3 || argc == 4)
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            if (strcmp(argv[2], TITLE) == 0)
                rc = fa_read(f, pfilm, N_MAX, &n, film_cmp_by_title);
            else if (strcmp(argv[2], NAME) == 0)
                rc = fa_read(f, pfilm, N_MAX, &n, film_cmp_by_name);
            else if (strcmp(argv[2], YEAR) == 0)
                rc = fa_read(f, pfilm, N_MAX, &n, film_cmp_by_year);
            else
                rc = ERR_ARGS;
                
            if (!rc && argc == 3)
                fa_print(stdout, pfilm, n);
            else if (!rc && argc == 4)
            {
                if (strcmp(argv[2], YEAR) == 0 && sscanf(argv[3], "%zu", &year) != 1)
                    rc = ERR_ARGS;
                else
                {
                    if (strcmp(argv[2], TITLE) == 0)
                    {
                        strcpy(key_struct.title, argv[3]);
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_title);
                        //fa_find_by_title(pfilm, n, &key_struct, &pos);
                    }
                    else if (strcmp(argv[2], NAME) == 0)
                    {
                        strcpy(key_struct.name, argv[3]);
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_name);
                        //fa_find_by_name(pfilm, n, &key_struct, &pos);
                    }
                    else
                    {
                        key_struct.year = atoi(argv[3]);
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_year);
                        //fa_find_by_year(pfilm, n, &key_struct, &pos);
                    }
                            
                    if (pos == -1)
                        printf("Not found");
                    else
                        film_print(stdout, pfilm + pos);
                }
            }

            fclose(f);
        }
        else
            rc = ERR_ARGS;
    }
    else 
        rc = ERR_ARGS;
        
    return rc;
}
