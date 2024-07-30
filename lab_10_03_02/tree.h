#ifndef TREE_H__
#define TREE_H__

#include "associative_array_node.h"

/// @brief очистка памяти из-под всего дерева
/// @param [out] tree указатель на корень
void tree_free(node_t *tree);

/// @brief применение действия ко всем узлам ДДП (двоичное дерево поиска)
/// @param [in] tree корень дерева
/// @param [in] action действие
/// @param [in] param параметр функции обратного вызова
void tree_each(node_t *tree, void (*action)(const char *key, int *num, void *param), void *param);

/// @brief функция получения минимума в ДДП
/// @param [in] tree указатель на корень дерева
/// @return указатель на значение минимума
int *tree_get_min(node_t *tree);

/// @brief функция получения максимума в ДДП
/// @param [in] tree указатель на корень дерева
/// @return указатель на значение максимума
int *tree_get_max(node_t *tree);

/// @brief функция поиска в ДДП
/// @param [in] tree указатель на корень
/// @param [in] key ключ, по которому ищем
/// @return указатель на значение, соответсвующее ключу
int *tree_find(node_t *tree, const char *key);

/// @brief вставка в ДДП
/// @param [out] tree указатель на корень дерева
/// @param [in] el элемент, который вставляем
/// @return указатель на корень дерева
node_t *tree_insert(node_t *tree, node_t *el);

/// @brief удаление корня из дерева
/// @param [out] tree указатель на корень
/// @return указатель на новый корень
node_t *del_el_tree(node_t *tree);

/// @brief удаление узла из ДДП
/// @param [out] tree указатель на корень
/// @param [in] key значение, по которому удаляем
/// @return указатель на корень
node_t *tree_delete(node_t *tree, const char *key);

#endif