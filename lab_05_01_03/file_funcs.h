#ifndef __FILE_FUNCS_H__
#define __FILE_FUNCS_H__


/// @brief Функция, которая считает, сколько раз в последовательности меняется знак
/// @param *f - откуда читаем последовательность чисел
/// @param *col - искомое количество смен знака
/// @return - код ошибки
int process(FILE *f, size_t *col);

#endif
