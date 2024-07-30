#ifndef __ARR_FUNC_H__
#define __ARR_FUNC_H__

#include "defines.h"

#define N 10
#define M 10

/// @brief функция ввода значений элементов матрицы
/// @param matrix[][M] - матрица, которую мы вводим (out)
/// @param *n - указатель на количество строк (out)
/// @param *m - указатель на количество столбцов (out)
/// @return код ошибки, возникающий при вводе матрицы
int input(int matrix[][M], size_t *n, size_t *m);


/// @brief функция, которая проверяте, что массив симметричен
/// @param arr[] массив, который мы проверяем на симметричность (in)
/// @param n размер массива (in)
/// @return возвращает TRUE если симметричен и FALSE если не симметричен
bool is_sym(const int arr[], size_t n);


/// @brief функция формирования массива симметричности строк матрицы
/// @param matrix[][M] матрица, строки которой мы рассматриваем (in)
/// @param n количество строк матрицы (in)
/// @param m количество столбцов матрицы (in)
/// @param arr[] формируемый массив (out)
void form_array(int matrix[][M], size_t n, size_t m, int arr[]);


/// @brief функция печатающая массив
/// @param array[] массив, который печатаем (in)
/// @param n размер массива (in)
void print_array(const int array[], size_t n);


#endif
