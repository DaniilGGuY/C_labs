#ifndef FILM_H__
#define FILM_H__

#include <stdio.h>

typedef struct
{
    char *title;
    char *name;
    int year;
} film_t;
 
/// @brief функция записывает информацио о фильме в переменную
/// @param film куда записываем информацию (out)
/// @param title название фильма (in)
/// @param name имя режиссера (in)
/// @param year год (in)
/// @return код ошибки
int film_init_content(film_t *film, const char *title, const char *name, int year);

/// @brief функция читает из файла информацию о кинофильме
/// @param f откуда считываем (in)
/// @param film куда считываем (out)
/// @return возвращает код ошибки
int film_read(FILE *f, film_t *film);

/// @brief функция выводит информацию о кинофильме в файл
/// @param f куда выводим информацию (in)
/// @param film откуда читаем информацию (in)
void film_print(FILE *f, const film_t *film);

/// @brief функция очищает память выделенную под фильм
/// @param film указатель на память, которую очищаем (in)
void film_free(film_t *film);

/// @brief функция сравнивает две структурные переменные по названию
/// @param pl первая переменная (in)
/// @param pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_title(const film_t *pl, const film_t *pr);

/// @brief функция сравнивает две структурные переменные по имени режиссера
/// @param pl первая переменная (in)
/// @param pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_name(const film_t *pl, const film_t *pr);

/// @brief функция сравнивает две структурные переменные по году выпуска
/// @param pl первая переменная (in)
/// @param pr вторая переменная (in)
/// @return возвращает результат лексикографического сравнения
int film_cmp_by_year(const film_t *pl, const film_t *pr);

/// @brief функция поверхностного копирования
/// @param куда копируем (out)
/// @param что копируем (in)
void film_copy(film_t *dst, const film_t *src);

#endif
