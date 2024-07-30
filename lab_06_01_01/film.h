#ifndef FILM_H__
#define FILM_H__

#include <stdio.h>
#include "constant.h"

struct film_t
{
    char title[TITLE_LEN + 1];
    char name[NAME_LEN + 1];
    int year;
};

/// @brief функция читает из файла информацию о кинофильме
/// @param *f откуда считываем (in)
/// @param *film куда считываем (out)
/// @return возвращает код ошибки
int film_read(FILE *f, struct film_t *film);

/// @brief функция выводит информацию о кинофильме в файл
/// @param *f куда выводим информацию (in)
/// @param *film откуда читаем информацию (in)
void film_print(FILE *f, const struct film_t *film);

/// @brief функция сравнивает две структурные переменные по названию
/// @param *pl первая переменная (in)
/// @param *pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_title(const struct film_t *pl, const struct film_t *pr);

/// @brief функция сравнивает две структурные переменные по имени режиссера
/// @param *pl первая переменная (in)
/// @param *pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_name(const struct film_t *pl, const struct film_t *pr);

/// @brief функция сравнивает две структурные переменные по году выпуска
/// @param *pl первая переменная (in)
/// @param *pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_year(const struct film_t *pl, const struct film_t *pr);

/// @brief меняет местами значения двух структурных переменных
/// @param *pl первая переменная (out)
/// @param *pr вторая переменная (out)
void film_swap(struct film_t *pl, struct film_t *pr);

#endif
