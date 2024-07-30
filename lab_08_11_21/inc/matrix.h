#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>

/// @brief функция сложения матриц
/// @param mat_a первая матрица (in)
/// @param mat_b вторая матрица (in)
/// @param n количество строк в матрице (in)
/// @param m количество столбцов в матрице (in)
/// @return возвращает матрицу, являющуюся суммой 
double **sum_matrix(double **mat_a, double **mat_b, size_t n, size_t m);

/// @brief функция перемножения матриц
/// @param mat_a первая матрица (in)
/// @param mat_b вторая матрица (in)
/// @param na количество строк в матрице A (in)
/// @param nb количество строк в матрице B (in)
/// @param mb количество столбцов в матрице B (in)
/// @return возвращает матрицу, являющуюся произведением 
double **comp_matrix(double **mat_a, double **mat_b, size_t na, size_t nb, size_t mb);

/// @brief функция решения слау, заданной матрицей
/// @param mat_a искомая матрица (in)
/// @param na количество строк в матрице (in)
/// @param ma количество столбцов в матрице (in)
/// @return столбец решений
double **get_roots(double **mat_a, size_t na, size_t ma);

#endif
