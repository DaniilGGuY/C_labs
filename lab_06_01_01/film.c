#include "film.h"
#include "error.h"
#include <string.h>


int film_read(FILE *f, struct film_t *film)
{
    char buf_title[TITLE_LEN + 1];
    char buf_name[NAME_LEN + 1];
    size_t len_title, len_name;
    char tmp[2];
    int year;
    
    if (!fgets(buf_title, sizeof(buf_title), f))
        return ERR_IO;
    len_title = strlen(buf_title);
    if (len_title && buf_title[len_title - 1] == '\n')
    {
        buf_title[len_title - 1] = '\0';
        --len_title;
    }
    if (!len_title || len_title > TITLE_LEN)
        return ERR_BUF_SIZE;
    
    if (!fgets(buf_name, sizeof(buf_name), f))
        return ERR_IO;
    len_name = strlen(buf_name);
    if (len_name && buf_name[len_name - 1] == '\n')
    {
        buf_name[len_name - 1] = '\0';
        --len_name;
    }
    if (!len_name || len_name > NAME_LEN)
        return ERR_BUF_SIZE;
        
    if (fscanf(f, "%d", &year) != 1)
        return ERR_IO;
    if (year <= 0)
        return ERR_IO;
        
    fgets(tmp, sizeof(tmp), f);
    strcpy(film->title, buf_title);
    strcpy(film->name, buf_name);
    film->year = year;
    
    return ERR_OK;
}


void film_print(FILE *f, const struct film_t *film)
{
    fprintf(f, "%s\n", film->title);
    fprintf(f, "%s\n", film->name);
    fprintf(f, "%d\n", film->year);
}


int film_cmp_by_title(const struct film_t *pl, const struct film_t *pr)
{
    return strcmp(pl->title, pr->title);
}

int film_cmp_by_name(const struct film_t *pl, const struct film_t *pr)
{
    return strcmp(pl->name, pr->name);
}

int film_cmp_by_year(const struct film_t *pl, const struct film_t *pr)
{
    if (pl->year > pr->year)
        return 1;
    else if (pl->year < pr->year)
        return -1;
    return 0;
}

void film_swap(struct film_t *pl, struct film_t *pr)
{
    struct film_t tmp;
    
    strcpy(tmp.title, pr->title);
    strcpy(tmp.name, pr->name);
    tmp.year = pr->year;
    
    strcpy(pr->title, pl->title);
    strcpy(pr->name, pl->name);
    pr->year = pl->year;
    
    strcpy(pl->title, tmp.title);
    strcpy(pl->name, tmp.name);
    pl->year = tmp.year;
}

