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


/// @brief функция подсчета суммы цифр число
/// @param val число, сумму цифр которого считаем (in)
/// @return возвращаем сумму цифр
int calc_sum(int val);


/// @brief функция, которая ищет элемент с минимальной суммой цифр
/// @param matrix[][M] матрица, в которой мы ищем элемент (in)
/// @param n количество строк матрицы (in)
/// @param m количество столбцов матрицы (in)
/// @param *ind_row указатель на индекс строки, в которой лежит искомый элемент (out)
/// @param *ind_col указатель на индекс столбца, в котором лежит искомый элемент (out)
void find_el(int matrix[][M], size_t n, size_t m, size_t *ind_row, size_t *ind_col);


/// @brief функция, удаляющая столбец по индексу
/// @param matrix[][M] матрица, в которой мы удаляем столбец (out)
/// @param n количество строк (in)
/// @param *m указатель на количество столбцов (out)
/// @param ind_col индекс столбца, который мы удаляем
void delete_col(int matrix[][M], size_t n, size_t *m, size_t ind_col);


/// @brief функция, удаляющая строку по индексу
/// @param matrix[][M] матрица, в которой мы удаляем строку (out)
/// @param *n указатель на количество строк (out_
/// @param m количество столбцов (in)
/// @param ind_row индекс строки, которую мы удаляем
void delete_row(int matrix[][M], size_t *n, size_t m, size_t ind_row);


/// @brief функция удаляющая строку и столбец матрицы по индексам элемента
/// @param matrix[][M] матрица, в которой мы удаляем строку и столбец (out)
/// @param *n указатель на количество строк (out)
/// @param *m указатель на количество столбцов (out)
/// @param ind_row индекс строки, в которой находится искомый элемент (in)
/// @oaram ind_col индекс столбца, в котором находится искомый элемент (in)
void delete_el(int matrix[][M], size_t *n, size_t *m, size_t ind_row, size_t ind_col);


/// @brief функция удаляющая строку и столбец матрицы по индексам элемента другим способом
/// @param matrix[][M] матрица, в которой мы удаляем строку и столбец (out)
/// @param *n указатель на количество строк (out)
/// @param *m указатель на количество столбцов (out)
/// @param ind_row индекс строки, в которой находится искомый элемент (in)
/// @oaram ind_col индекс столбца, в котором находится искомый элемент (in)
void delete_el_second(int matrix[][M], size_t *n, size_t *m, size_t ind_row, size_t ind_col);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем (in)
/// @param n количество строк (in)
/// @param m количество столбцов (in)
void print(int matrix[][M], size_t n, size_t m);


#endif
