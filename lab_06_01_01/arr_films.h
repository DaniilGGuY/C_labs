#ifndef ARR_FILMS_H__
#define ARR_FILMS_H__

#include "film.h"
#include <stdio.h>

typedef int (*comp_t)(const struct film_t *pl, const struct film_t *pr);

/// @brief функция считывает все кинофильмы из файла и записывает их в отсортированном по полю порядке
/// @param *f откуда считываем (in)
/// @param *pfilm массив, в который считываем (out)
/// @param n_max максимальный размер массива (in)
/// @param *n размер массива (out)
/// @param cmp компаратор, который сравнивает структурные типы (in)
/// @return возвращает код ошибки
int fa_read(FILE *f, struct film_t *pfilm, size_t n_max, size_t *n, comp_t cmp);

/// @brief функция считывает все кинофильмы из файла и записывает их в отсортированном по полю порядке
/// @param *f откуда считываем (in)
/// @param *pfilm массив, который печатаем (in)
/// @param n размер массива (in)
void fa_print(FILE *f, const struct film_t *pfilm, size_t n);

/// @brief функция выполняет двоичный поиск поля по названию фильма
/// @param *pfilm массив, в котором выполняем бинарный поиск (in)
/// @param n размер массива (in)
/// @param *key структура-ключ, по которому выполняется поиск (in)
/// @param *pos позиция искомого элемента или -1, если такого элемента нет (out)
/// @param cmp компаратор, который сравнивает структурные типы (in)
void fa_find(struct film_t *pfilm, size_t n, struct film_t *key, int *pos, comp_t cmp);

/// @brief функция выполняет двоичный поиск поля по названию фильма
/// @param *pfilm массив, в котором выполняем бинарный поиск (in)
/// @param n размер массива (in)
/// @param *key ключ, по которому выполняется поиск (in)
/// @param *pos позиция искомого элемента или -1, если такого элемента нет (out)
//void fa_find_by_title(struct film_t *pfilm, size_t n, struct film_t *key, int *pos);

/// @brief функция выполняет двоичный поиск поля по имени режиссера
/// @param *pfilm массив, в котором выполняем бинарный поиск (in)
/// @param n размер массива (in)
/// @param *key ключ, по которому выполняется поиск (in)
/// @param *pos позиция искомого элемента или -1, если такого элемента нет (out)
//void fa_find_by_name(struct film_t *pfilm, size_t n, struct film_t *key, int *pos);

/// @brief функция выполняет двоичный поиск поля по году выпуска фильма 
/// @param *pfilm массив, в котором выполняем бинарный поиск (in)
/// @param n размер массива (in)
/// @param *key ключ, по которому выполняется поиск (in)
/// @param *pos позиция искомого элемента или -1, если такого элемента нет (out)
//void fa_find_by_year(struct film_t *pfilm, size_t n, struct film_t *key, int *pos);

/// @brief функция, которая ищет позицию для вставки элемента в массив
/// @param *pfilm массив, в котором ищем искомую позицию (in)
/// @param n размер массива (in)
/// @param *film фильм, который хотим вставить (in)
/// @param cmp компаратор, который сравнивает структурные типы (in)
/// @param *pos искомая позиция (out)
void fa_find_insert_pos(struct film_t *pfilm, size_t n, struct film_t *film, comp_t cmp, size_t *pos);

/// @brief функция, которая вставляет очередной элемент в массив, чтобы массив был отсортирован по полю
/// @param *pfilm массив, в который вставляем (out)
/// @param *n размер массива (out)
/// @param *film фильм, который хотим вставить (in)
/// @param cmp компаратор, который сравнивает структурные типы (in)
void fa_insert(struct film_t *pfilm, size_t *n, struct film_t *film, comp_t cmp);

#endif
