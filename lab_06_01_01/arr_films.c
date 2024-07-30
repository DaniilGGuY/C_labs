#include "arr_films.h"
#include "error.h"
#include <string.h>
#include <stdlib.h>

int fa_read(FILE *f, struct film_t *pfilm, size_t n_max, size_t *n, comp_t cmp)
{
    struct film_t film;
    int rc = ERR_OK;
    *n = 0;
    
    while (!rc)
    {
        rc = film_read(f, &film);
        if (!rc)
        {
            if (*n < n_max)
                fa_insert(pfilm, n, &film, cmp);
            else
                rc = ERR_OVERFLOW;
        }
    }
    
    if (rc && feof(f))
        rc = ERR_OK;
    
    if (*n == 0)
        rc = ERR_IO;
    
    return rc;
}

void fa_print(FILE *f, const struct film_t *pfilm, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        film_print(f, pfilm + i);
}

void fa_find(struct film_t *pfilm, size_t n, struct film_t *key, int *pos, comp_t cmp)
{
    int lhs = -1, rhs = n, mid;
    while (lhs < rhs - 1)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (cmp(pfilm + mid, key) >= 0)
            rhs = mid;
        else 
            lhs = mid;
    }

    if (cmp(pfilm + rhs, key) == 0)
        *pos = rhs;
}
/*
void fa_find_by_title(struct film_t *pfilm, size_t n, struct film_t *key, int *pos)
{
    int lhs = -1, rhs = n, mid;
    while (lhs < rhs - 1)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (film_cmp_by_title(pfilm + mid, key) >= 0)
            rhs = mid;
        else 
            lhs = mid;
    }

    if (film_cmp_by_title(pfilm + rhs, key) == 0)
        *pos = rhs;
}

void fa_find_by_name(struct film_t *pfilm, size_t n, struct film_t *key, int *pos)
{
    int lhs = -1, rhs = n, mid;
    while (lhs < rhs - 1)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (film_cmp_by_name(pfilm + mid, key) >= 0)
            rhs = mid;
        else 
            lhs = mid;
    }

    if (film_cmp_by_name(pfilm + rhs, key) == 0)
        *pos = rhs;
}

void fa_find_by_year(struct film_t *pfilm, size_t n, struct film_t *key, int *pos)
{
    int lhs = -1, rhs = n, mid;
    while (lhs < rhs - 1)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (film_cmp_by_year(pfilm + mid, key) >= 0)
            rhs = mid;
        else 
            lhs = mid;
    }

    if (film_cmp_by_year(pfilm + rhs, key) == 0)
        *pos = rhs;
}
*/
void fa_find_insert_pos(struct film_t *pfilm, size_t n, struct film_t *film, comp_t cmp, size_t *pos)
{
    while (*pos < n)
    {
        if (cmp(pfilm + *pos, film) > 0)
            break;
                
        *pos += 1;
    }
}

void fa_insert(struct film_t *pfilm, size_t *n, struct film_t *film, comp_t cmp)
{
    size_t pos = 0;
    fa_find_insert_pos(pfilm, *n, film, cmp, &pos);
    
    for (size_t i = pos; i < *n; ++i)
        film_swap(pfilm + i, film);
        
    strcpy(pfilm[*n].title, film->title);
    strcpy(pfilm[*n].name, film->name);
    pfilm[*n].year = film->year;
    
    *n += 1;
}
