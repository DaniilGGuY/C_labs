#ifndef MEMORY_FUNCS_H__
#define MEMORY_FUNCS_H__

#include <stdio.h>

/// @brief функция очистки памяти
/// @param data указатель на память, которую очищаем (out)
/// @param n количество строк в матрице (in)
void free_matrix(double **data, size_t n);

/// @brief функция выделения памяти под матрицу
/// @param n количество строк в матрице (in)
/// @param m количество столбцов в матрице (in)
/// @return возвращает указатель на память под искомую матрицу
double **allocate_matrix(size_t n, size_t m);

#endif