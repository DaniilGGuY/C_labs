#ifndef MY_SNPRINTF_H__
#define MY_SNPRINTF_H__

#include <stdio.h>

#define BASE          8

/// @brief приписывает к одной строке элементы из другой
/// @param src откуда переписываем
/// @param dst куда переписываем
/// @param len_dst длина строки dst
/// @param max_size максимальный размер буфера
/// @return количество прочитанных элементов
int read_string(char *src, char *dst, size_t *len_dst, size_t max_size);

/// @brief функция чтения длинного восьмеричного числа в буфер
/// @param src длинное десятичное число, которое нужно перевести в восьмеричное
/// @param dst куда читаем
/// @param len_dst длина буфера
/// @param max_size максимальный размер буфера
/// @return количество прочитанных элементов
int read_long_octo(unsigned long src, char *dst, size_t *len_dst, size_t max_size);

/// @brief самописная snprintf
/// @param [out] buffer строка, куда помещаем результат
/// @param [in] bufsz максимальное количество символов в строке
/// @param [in] format формат преобразования в строку
/// @return количество символов записанных в строку
int my_snprintf(char *restrict buffer, size_t bufsz, const char *restrict format, ...);

#endif