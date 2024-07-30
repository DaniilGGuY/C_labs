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


/// @brief функция формирования массива элементов матрицы, сумма цифр которых больше 10
/// @param matrix[][M] матрица, на основе которой мы формируем массив (in)
/// @param n количество строк матрицы (in)
/// @param m количество столбцов матрицы (in)
/// @param arr[] массив элементов матрицы, сумма цифр которых больше 10 (out)
/// @param *len указатель на размер формируемого массива (out)
void form_array(int matrix[][M], size_t n, size_t m, int arr[], size_t *len);


/// @brief функция, разворачивающая массив
/// @param *arr указатель на первый элемент разворачиваемого массива (out)
/// @param size размер массива (in)
void reverse_array(int *arr, size_t size);


/// @brief функция циклического сдвига массива
/// @param arr[] массив, который циклически сдвигаем (out)
/// @param n размер массива (in)
/// @param shift размер сдвига (больше нуля, если сдвигаем влево; меньше нуля, если вправо) (in)
void shift_array(int arr[], size_t n, int shift);


/// @brief функция вставляющая элементы массива обратно в матрицу
/// @param matrix[][M] матрица, куда вставляем элементы массива (out)
/// @param n количество строк матрицы (in)
/// @param m количество столбцов матрицы (in)
/// @param arr[] массив, элементы которого вставляем (in)
void put_elements(int matrix[][M], size_t n, size_t m, int arr[]);


/// @brief функция, печатающая матрицу
/// @param matrix[][M] матрица, которую печатаем (in)
/// @param n количество строк (in)
/// @param m количество столбцов (in)
void print(int matrix[][M], size_t n, size_t m);


#endif
