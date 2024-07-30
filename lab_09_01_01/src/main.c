#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arr_films.h"
#include "film.h"
#include "err_codes.h"
#include "constant.h"

int main(int argc, char **argv)
{
    FILE *f;
    film_t *pfilm = NULL;
    film_t key_struct = { NULL, NULL, 0 };
    size_t n, year;
    int pos;
    int rc = ERR_OK;
    
    if (argc == 3 || argc == 4)
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            rc = fa_read_size(f, &n);
            if (!rc)
            {
                rewind(f);
                if (strcmp(argv[2], TITLE) == 0)
                    rc = fa_read(f, &pfilm, n, film_cmp_by_title);
                else if (strcmp(argv[2], NAME) == 0)
                    rc = fa_read(f, &pfilm, n, film_cmp_by_name);
                else if (strcmp(argv[2], YEAR) == 0)
                    rc = fa_read(f, &pfilm, n, film_cmp_by_year);
                else
                    rc = ERR_ARGS;
            }

            if (!rc && argc == 3)
            {
                fa_print(stdout, pfilm, n);
                fa_free(pfilm, n);
            }
            else if (!rc && argc == 4)
            {
                if (strcmp(argv[2], YEAR) == 0 && sscanf(argv[3], "%zu", &year) != 1)
                    rc = ERR_ARGS;
                else
                {
                    if (strcmp(argv[2], TITLE) == 0)
                    {
                        key_struct.title = argv[3];
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_title);
                    }
                    else if (strcmp(argv[2], NAME) == 0)
                    {
                        key_struct.name = argv[3];
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_name);
                    }
                    else
                    {
                        key_struct.year = atoi(argv[3]);
                        fa_find(pfilm, n, &key_struct, &pos, film_cmp_by_year);
                    }
                            
                    if (pos == -1)
                        printf("Not found");
                    else
                        film_print(stdout, pfilm + pos);
                }

                fa_free(pfilm, n);
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
