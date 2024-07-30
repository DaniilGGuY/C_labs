#ifndef __ARR_FUNC_H__
#define __ARR_FUNC_H__

#include "defines.h"

#define N 10
#define M 10

/// @brief функция ввода размеров формируемой матрицы
/// @param *n указатель на количество строк (out)
/// @param *m указатель на количество столбцов (out)
/// @return код ошибки, возникающий при вводе размеров
int input(size_t *n, size_t *m);


/// @brief функция, заполняющая квадратную матрицу по спирали (обход по часовой стрелке)
/// @param matrix[][M] матрица, которую мы заполняем (out)
/// @param n количество строк матрицы (in)
void fill(int matrix[][M], size_t n);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем (tn)
/// @param n количество строк (in)
/// @param m количество столбцов (in)
void print(int matrix[][M], size_t n, size_t m);


#endif
