#ifndef FILE_FUNCS__
#define FILE_FUNCS__

#include <stdio.h>

/// @brief функция чтения из файла матрицы, заданной обычным способом
/// @param f файл, из которого читаем (in)
/// @param data матрица (out)
/// @param n количество строк в матрице (out)
/// @param m количество столбцов в матрице (out)
/// @return возвращает код ошибки 
int input_matrix(FILE *f, double ***data, size_t *n, size_t *m);

/// @brief функция чтения из файла матрицы, заданной координатным способом
/// @param f файл, из которого читаем (in)
/// @param data матрица (out)
/// @param n количество строк в матрице (out)
/// @param m количество столбцов в матрице (out)
/// @return возвращает код ошибки 
int input_matrix_coord(FILE *f, double ***data, size_t *n, size_t *m);

/// @brief функция печати матрицы в файл обычным способом
/// @param f файл, куда записываем (in)
/// @param data матрица (in)
/// @param n количество строк в матрице (in)
/// @param m количество столбцов в матрице (in)
void print_matrix(FILE *f, double **data, size_t n, size_t m);

#endif