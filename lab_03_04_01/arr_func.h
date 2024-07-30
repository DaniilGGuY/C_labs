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


/// @brief функция меняющая местами элементы по определенному в условии правилу
/// @param matrix[][M] матрица, в которой мы меняем местами элементы (out)
/// @param n количество строк квадратной матрицы (in)
void swap(int matrix[][N], size_t n);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем (in)
/// @param n количество строк (in)
/// @param m количество столбцов
void print(int matrix[][M], size_t n, size_t m);


#endif
