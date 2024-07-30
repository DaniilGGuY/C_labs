#ifndef LIST_H__
#define LIST_H__

#include <stdio.h>

#include "node.h"

/// @brief функция добавляет к списку хвост
/// @param [out] head голова списка 
/// @param [in] pnode указатель на присоединяемый хвост
/// @return новый указатель на голову
node_t *list_add_tail(node_t *head, node_t *pnode);

/// @brief функция освобождения списка
/// @param [in] head указатель на голову списка
void list_free(node_t *head);

/// @brief функция печатает список
/// @param [in] head указатель на голову списка
void list_print(node_t *head);

/// @brief функция формирует список по разбиению целого числа
/// @param [out] head указатель на голову списка
/// @param [in] val искомое число
/// @return код ошибки
int list_form_by_num(node_t **head, int val);

/// @brief функция удаляет нулевые элементы из конца списка
/// @param [in] head указатель на голову списка
/// @return возвращает указатель на новую голову
node_t *cut_list(node_t *head);

/// @brief функция добавляет к списку список, созданный на основе списка a (глубокое копирование)
/// @param [in] a что добавляем
/// @param [out] c к чему добавляем
/// @return код ошибки
int add_list_to_list(node_t *a, node_t **c);

#endif