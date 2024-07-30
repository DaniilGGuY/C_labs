#ifndef __ARR_FUNC_H__
#define __ARR_FUNC_H__

#include "defines.h"


/// @brief функция ввода размеров формируемой матрицы
/// @param *n указатель на количество строк
/// @param *m указатель на количество столбцов
/// @return код ошибки, возникающий при вводе размеров
int input(size_t *n, size_t *m);


/// @brief функция, заполняющая квадратную матрицу по спирали (обход по часовой стрелке)
/// @param matrix[][M] матрица, которую мы заполняем
/// @param n количество строк матрицы
void fill(int matrix[][M], size_t n);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем
/// @param n количество строк
/// @param m количество столбцов
void print(int matrix[][M], size_t n, size_t m);


#endif
