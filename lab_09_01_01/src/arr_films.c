#include <string.h>
#include <stdlib.h>

#include "arr_films.h"
#include "err_codes.h"

int fa_read_size(FILE *f, size_t *n)
{
    film_t film = { NULL, NULL, 0 };
    int rc = ERR_OK;
    *n = 0;

    while (!rc)
    {
        rc = film_read(f, &film);
        if (!rc)
        {
            film_free(&film);
            ++(*n);
        }
    }
    
    if (rc && feof(f))
        rc = ERR_OK;
    
    if (*n == 0)
        rc = ERR_IO;
    
    return rc;
}

int fa_read(FILE *f, film_t **pfilm, size_t n, comp_t cmp)
{
    film_t film = { NULL, NULL, 0 };
    int rc = ERR_OK;
    size_t i = 0;
    *pfilm = calloc(n, sizeof(film_t));
    if (*pfilm)
    {
        while (!rc && i < n)
        {
            rc = film_read(f, &film);
            if (!rc)
            {
                fa_insert(*pfilm, &i, &film, cmp);
                /*
                В случае неглубокого копирования эта строка очистит данные и из самого массива
                film_free(&film);
                */
            }
        }
        
        if (rc && feof(f))
            rc = ERR_OK;

        if (i != n)
        {
            fa_free(*pfilm, i);
            *pfilm = NULL;
            rc = ERR_FILE;
        }
    }
    else
        rc = ERR_MEM;
    
    return rc;
}

void fa_print(FILE *f, const film_t *pfilm, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        film_print(f, pfilm + i);
}

void fa_free(film_t *pfilm, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        film_free(pfilm + i);

    free(pfilm);
}

void fa_find(film_t *pfilm, size_t n, film_t *key, int *pos, comp_t cmp)
{
    int lhs = -1, rhs = n, mid;
    *pos = -1;
    while (lhs < rhs - 1)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (cmp(pfilm + mid, key) < 0)
            lhs = mid;
        else 
            rhs = mid;
    }

    if (lhs + 1 < (int)n && cmp(pfilm + lhs + 1, key) == 0)
        *pos = lhs + 1;
}

void fa_find_insert_pos(film_t *pfilm, size_t n, film_t *film, size_t *pos, comp_t cmp)
{
    *pos = 0;
    while (*pos < n)
    {
        if (cmp(pfilm + *pos, film) > 0)
            break;
                
        *pos += 1;
    }
}

void fa_insert(film_t *pfilm, size_t *n, film_t *film, comp_t cmp)
{
    size_t pos;
    fa_find_insert_pos(pfilm, *n, film, &pos, cmp);
    
    //for (size_t i = *n; i > pos && !rc; --i)
    //    rc = film_init_content(pfilm + i, pfilm[i - 1].title, pfilm[i - 1].name, pfilm[i - 1].year);
    
    for (size_t i = *n; i > pos; --i)
        film_copy(pfilm + i, pfilm + i - 1);
    
    film_copy(pfilm + pos, film);
    *n += 1;
}
