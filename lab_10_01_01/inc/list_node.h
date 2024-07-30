#ifndef LIST_NODE_H__
#define LIST_NODE_H__

#include <stdio.h>

#include "node.h"

/// @brief функция добавляет к списку хвост
/// @param [out] head голова списка 
/// @param [in] pnode указатель на присоединяемый хвост
/// @return новый указатель на голову
node_t *list_add_tail(node_t *head, node_t *pnode);

/// @brief функция чтения строки из файла
/// @param [in] f - файл
/// @param [out] buf - строка
/// @return код ошибки 
int read_str(FILE *f, char **buf);

/// @brief функция читает список из файла
/// @param [in] f - файл
/// @param [out] head - указатель на голову считанного списка
/// @return код ошибки
int list_read_from_file(FILE *f, node_t **head);

/// @brief функция очищает память из-под списка
/// @param [in] head - указатель на голову
void list_free(node_t *head);

/// @brief функция очищает память из-под списка и из-под данных
/// @param [in] head - указатель на голову
void list_free_data(node_t *head);

/// @brief функция печатает список в файл
/// @param [in] f - файл
/// @param [in] head - указатель на голову
void list_print(FILE *f, node_t *head);

/// @brief удаление головы списка
/// @param [out] head - указатель на голову
/// @return значение, лежащее в голове
void *pop_front(node_t **head);

/// @brief удаление из хвоста списка
/// @param [out] head - указатель на хвост
/// @return значение, лежащее в хвосте
void *pop_back(node_t **head);

/// @brief втавка элемента в список до определенного элемента
/// @param [out] head - указатель на голову списка
/// @param [in] elem - искомы элемент для вставки
/// @param [in] before - перед чем вставлять
void insert(node_t **head, node_t *elem, node_t *before);

/// @brief функция поиска в списке
/// @param [in] head - указатель на голову
/// @param [in] data - строка, по которой осуществляется поиск
/// @param [in] comparator - компаратор
/// @return указатель на найденный элемент либо нулевой указатель
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

#endif