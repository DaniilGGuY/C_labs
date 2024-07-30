#ifndef LIST_H__
#define LIST_H__

#include "associative_array_node.h"

/// @brief функция, которая вставляет элемент в список
/// @param [out] list_beg указатель на голову списка 
/// @param [out] list_end указатель на хвост списка
/// @param [in] el элемент, который вставляем
/// @return указатель на новую голову списка
node_t *list_insert(node_t *list_beg, node_t **list_end, node_t *el);

/// @brief функция поиска в списка
/// @param [in] list_beg указатель на голову списка
/// @param [in] key элемент, по которому ищем
/// @return указатель на найденный элемент
node_t *list_find(node_t *list_beg, const char *key);

/// @brief функция, которая удаляет элемент из списка по ключу
/// @param [out] list_beg указатель на голову списка
/// @param [out] list_end указатель на хвост списка
/// @param [in] key ключ, по которому удаляем
/// @return указатель на новую голову
node_t *list_remove(node_t *list_beg, node_t **list_end, const char *key);

#endif