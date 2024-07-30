#ifndef __FILE_FUNCS_H__
#define __FILE_FUNCS_H__

#define EPS 0.000001

/// @brief Функция находит максимум и минимум в файле
/// @param *f - файловая переменная (in)
/// @param *max - максимум в файле (out)
/// @param *min - минимум в файле (out)
/// @return код ошибки
int calc_max_and_min(FILE *f, double *max, double *min);

/// @brief Функция подсчитывает, сколько чисел в файле больших среднего арифметического максимума и минимума
/// @param *f - файловая переменная (in)
/// @param average - среднее значение максимума и минимума (in)
/// @param *count - искомое количество (out)
/// @return код ошибки
int calc_count(FILE *f, double average, size_t *count);


#endif
