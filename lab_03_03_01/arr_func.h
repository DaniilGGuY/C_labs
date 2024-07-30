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


/// @brief функция ищет максимум в массиве
/// @param array[] массив, в котором мы ищем максимум (in)
/// @param n размер массива (in)
/// @return возвращает максимальное значение в массиве
int max_arr(const int array[], size_t n);


/// @brief функция меняет местами строки матрицы
/// @param arr1[] первая строка (out)
/// @param arr2[] вторая строка (out)
/// @param n размер строк (in)
void swap(int arr1[], int arr2[], size_t n);


/// @brief функция, которая упорядочивает матрицу по убыванию максимального значения
/// @param matrix[][M] матрица, которую упорядочиваем (out)
/// @param n количество строк в матрице (in)
/// @param m количество столбцов в матриц (in)
void sort(int matrix[][M], size_t n, size_t m);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем (in)
/// @param n количество строк (in)
/// @param m количество столбцов (in)
void print(int matrix[][M], size_t n, size_t m);


#endif
