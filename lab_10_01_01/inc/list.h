#ifndef LIST_H__
#define LIST_H__

#include <stdio.h>

#include "node.h"
#include "list_node.h"

/// @brief функция сравнивает две строки
/// @param [in] l - первая строка
/// @param [in] r - вторая строка
/// @return результат лексикографического сравнения
int comp(const void *l, const void *r);

/// @brief функция удаления дубликатов из списка
/// @param [out] head - указатель на голову
/// @param [in] comparator - компаратор
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

/// @brief функция, делящая исходный список на два списка отличающиеся по длине не более чем на 1
/// @param [in] head - указатель на голову первого списка
/// @param [out] back - указатель на голову второго списка
void front_back_split(node_t *head, node_t **back);

/// @brief слияние двух отсортированных списков в один отсортированный
/// @param [out] head_a - указатель на голову первого списка
/// @param [out] head_b - указатель на голову второго списка
/// @param [in] comparator - компаратор
/// @return результат слияния двух списков
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

/// @brief функция сортировки списка
/// @param [in] head - указатель на голову списка
/// @param [in] comparator - компаратор
/// @return отсортированный список
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

/// @brief функция создает дубликат списка по переданному списку
/// @param [in] a - список, по которому создаем дубликат
/// @param [out] b - список-дубликат
/// @return код ошибки
int create_duplicate_list(node_t *a, node_t **b);

#endif