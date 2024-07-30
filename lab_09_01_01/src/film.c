#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>

#include "film.h"
#include "err_codes.h"

int film_init_content(film_t *film, const char *title, const char *name, int year)
{
    int rc = ERR_OK;
    char *tmp_title = strdup(title), *tmp_name;
    if (tmp_title)
    {
        tmp_name = strdup(name);
        if (tmp_name)
        {
            /*
            Эта строчка не нужна при реализации неглубокого копирования, так как будет освобождаться память и в массиве структур -> 
            потеря данных и двойная очистка памяти (вторая в main при очистке самого массива структур)
            film_free(film);
            */
            film->title = tmp_title;
            film->name = tmp_name;
            film->year = year;
        }
        else
        {
            free(tmp_title);
            rc = ERR_MEM;
        }
    }
    else
        rc = ERR_MEM;

    return rc;
}

int film_read(FILE *f, film_t *film)
{
    char *buf_title = NULL, *buf_name = NULL;
    ssize_t len_title, len_name;
    int year, rc = ERR_OK;
    size_t len = 0;

    if ((len_title = getline(&buf_title, &len, f)) == -1)
        rc = ERR_MEM;
    if (len_title <= 1 && !rc)
        rc = ERR_IO;
    if (!rc && buf_title[len_title - 1] == '\n')
        buf_title[len_title - 1] = '\0';

    len = 0;
    if ((len_name = getline(&buf_name, &len, f)) == -1 && !rc)
        rc = ERR_MEM;
    if (len_name <= 1 && !rc)
        rc = ERR_IO;
    if (!rc && buf_name[len_name - 1] == '\n') 
        buf_name[len_name - 1] = '\0'; 

    if (!rc)
        if (fscanf(f, "%d\n", &year) != 1 || year <= 0)
            rc = ERR_IO;
    
    if (!rc)
        rc = film_init_content(film, buf_title, buf_name, year);

    if (buf_name)
        free(buf_name);
    if (buf_title)
        free(buf_title);

    return rc;
}

void film_print(FILE *f, const film_t *film)
{
    fprintf(f, "%s\n", film->title);
    fprintf(f, "%s\n", film->name);
    fprintf(f, "%d\n", film->year);
}

void film_free(film_t *film)
{
    free(film->title);
    film->title = NULL;
    free(film->name);
    film->name = NULL;
    film->year = 0;
}

int film_cmp_by_title(const film_t *pl, const film_t *pr)
{
    return strcmp(pl->title, pr->title);
}

int film_cmp_by_name(const film_t *pl, const film_t *pr)
{
    return strcmp(pl->name, pr->name);
}

int film_cmp_by_year(const film_t *pl, const film_t *pr)
{
    if (pl->year > pr->year)
        return 1;
    else if (pl->year < pr->year)
        return -1;
    return 0;
}

void film_copy(film_t *dst, const film_t *src)
{
    dst->title = src->title;
    dst->name = src->name;
    dst->year = src->year;
}
