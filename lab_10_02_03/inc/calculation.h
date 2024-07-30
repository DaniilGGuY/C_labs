#ifndef CALCULATION_H__
#define CALCULATION_H__

#include "node.h"

/// @brief функция умножения чисел, представленных в виде списков простых множителей
/// @param [in] a - первое число 
/// @param [in] b - второе число 
/// @param [out] c - результат умножения
/// @return код ошибки
int mult(node_t *a, node_t *b, node_t **c);

/// @brief функция возведения в квадрат, представленного в виде списка простых множителей
/// @param [in] a - первое число 
/// @param [out] c - результат умножения
/// @return код ошибки
int square(node_t *a, node_t **c);

/// @brief функция деления чисел, представленных в виде списков простых множителей
/// @param [in] a - первое число 
/// @param [in] b - второе число 
/// @param [out] c - результат умножения
/// @return код ошибки
int division(node_t *a, node_t *b, node_t **c);

#endif