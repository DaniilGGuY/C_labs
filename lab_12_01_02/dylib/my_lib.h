#ifndef MY_LIB_H__
#define MY_LIB_H__

#include <stdbool.h>
#include <stdlib.h>

#define OK            0
#define ERR_ARGS      1
#define REALLOCATED   2

/// @brief функция разворачивает массив
/// @param [out] p1 указатель на первый элемент массива
/// @param [out] p2 указатель на последний элемент массива
/// @return код ошибки
int reverse_part(int *p1, int *p2);

/// @brief функция циклического сдвига влево
/// @param [out] arr массив
/// @param [in] size размер массива
/// @param [in] col на сколько двигать
/// @return код ошибки
int cycle_left_shift(int *arr, size_t size, int col);

/// @brief функция проверяет число на то, что оно является полным квадратом
/// @param [in] value число, которое проверяем
/// @return является ли число полным квадратом или нет
bool is_square(int value);

/// @brief функция оставлет во втором массиве только те числа из первого массива, которые являются полными квадратами
/// @param [in] src первый массив
/// @param [in] src_len размер первого массива
/// @param [out] dst второй массив
/// @param [out] dst_len размер второго массива
/// @return код, отвечающий за то, нужно ли перевыделение памяти или нет
int filter(int *src, size_t src_len, int *dst, size_t *dst_len);

#endif