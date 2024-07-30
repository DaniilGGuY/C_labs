#ifndef ARR_FILMS_H__
#define ARR_FILMS_H__

#include <stdio.h>

#include "film.h"

typedef int (*comp_t)(const film_t *pl, const film_t *pr);

/// @brief функция вычисляет размер массива структур
/// @param f файл, в котором лежат структуры (in)
/// @param n размер (out)
/// @return код ошибки 
int fa_read_size(FILE *f, size_t *n);

/// @brief функция считывает все кинофильмы из файла и записывает их в отсортированном по полю порядке
/// @param f откуда считываем (in)
/// @param pfilm массив, в который считываем (out)
/// @param n размер массива (in)
/// @param cmp компаратор, который сравнивает структурные типы (in)
/// @return возвращает код ошибки
int fa_read(FILE *f, film_t **pfilm, size_t n, comp_t cmp);

/// @brief функция, которая печатает все фиьмы в файл
/// @param f откуда считываем (in)
/// @param pfilm массив, который печатаем (in)
/// @param n размер массива (in)
void fa_print(FILE *f, const film_t *pfilm, size_t n);

/// @brief функция очистки памяти
/// @param pfilm область памяти, которую очищаем (in)
/// @param n размер массива (in)
void fa_free(film_t *pfilm, size_t n);

/// @brief функция выполняет двоичный поиск поля по названию фильма
/// @param pfilm массив, в котором выполняем бинарный поиск (in)
/// @param n размер массива (in)
/// @param key структура-ключ, по которому выполняется поиск (in)
/// @param pos позиция искомого элемента или -1, если такого элемента нет (out)
/// @param cmp компаратор, который сравнивает структурные типы (in)
void fa_find(film_t *pfilm, size_t n, film_t *key, int *pos, comp_t cmp);

/// @brief функция, которая ищет позицию для вставки элемента в массив
/// @param pfilm массив, в котором ищем искомую позицию (in)
/// @param n размер массива (in)
/// @param film фильм, который хотим вставить (in)
/// @param pos искомая позиция (out)
/// @param cmp компаратор, который сравнивает структурные типы (in)
void fa_find_insert_pos(film_t *pfilm, size_t n, film_t *film, size_t *pos, comp_t cmp);

/// @brief функция, которая вставляет очередной элемент в массив, чтобы массив был отсортирован по полю
/// @param pfilm массив, в который вставляем (out)
/// @param n размер массива (out)
/// @param film фильм, который хотим вставить (in)
/// @param cmp компаратор, который сравнивает структурные типы (in)
void fa_insert(film_t *pfilm, size_t *n, film_t *film, comp_t cmp);

#endif
