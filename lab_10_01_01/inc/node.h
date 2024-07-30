#ifndef NODE_H__
#define NODE_H__

#include <stdio.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

/// @brief функция создания узла списка
/// @param [in] data значение, которое будет хранится в узле списка 
/// @return указатель на узел списка
node_t *node_create(void *data);

/// @brief функция очищает память из-под узла
/// @param [in] pnode указатель на узел списка 
void node_free(node_t *pnode);

/// @brief функция очищает память из-под узла и из-под ключа в нем
/// @param [in] pnode указатель на узел списка 
void node_free_data(node_t *pnode);

/// @brief функция печатает узел на экран
/// @param [in] f файл, куда записываем
/// @param [in] pnode указатель на узел
void node_print(FILE *f, const node_t *pnode);

#endif