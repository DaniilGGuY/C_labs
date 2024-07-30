#ifndef FILE_FUNCS__
#define FILE_FUNCS__

#include <stdio.h>

/// @brief функция чтения количества целочисленных элементов из файла
/// @param f - имя файла (in)
/// @param count - количество целочисленных элементов(out)
/// @return код ошибки
int read_elems_count(FILE *f, size_t *count);

/// @brief функция чтения целочисленных элементов из файла
/// @param f - имя файла (in)
/// @param pbeg - указатель на первый элемент массива (in)
/// @param pend - указатель на запоследний элемент массива (in)
int read_elems(FILE *f, int *const pbeg, int *const pend);

/// @brief функция записи целочисленных элементов в файл
/// @param f - имя файла (in)
/// @param pbeg - указатель на первый элемент массива (in)
/// @param pend - указатель на запоследний элемент массива (in)
void write_elems(FILE *f, const int *const pbeg, const int *const pend);

#endif