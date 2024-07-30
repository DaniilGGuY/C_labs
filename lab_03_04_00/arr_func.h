#ifndef __ARR_FUNC_H__
#define __ARR_FUNC_H__

#include "defines.h"

#define N 10
#define M 10

/// @brief функция ввода значений элементов матрицы
/// @param matrix[][M] матрица, которую мы вводим (out)
/// @param *n указатель на количество строк (out)
/// @param *m указатель на количество столбцов (out)
/// @return код ошибки, возникающий при вводе матрицы
int input(int matrix[][M], size_t *n, size_t *m);


/// @brief функция, которая ищет минимальный нечетный элемент под главной диагональю
/// @param matrix[][M] матрица, в которой мы меняем местами элементы (in)
/// @param n количество строк квадратной матрицы (in)
/// @return возвращает искомый элемент
int find_el(int matrix[][N], size_t n);


#endif
