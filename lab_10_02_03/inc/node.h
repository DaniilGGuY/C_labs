#ifndef NODE_H__
#define NODE_H__

typedef struct node 
{
    int num;
    struct node *next; 
} node_t;

/// @brief функция создания узла списка
/// @param [in] num значение, которое будет хранится в узле списка 
/// @return указатель на узел списка
node_t *node_create(int num);

/// @brief функция очищает память из-под узла
/// @param [in] pnode указатель на узел списка 
void node_free(node_t *pnode);

/// @brief функция печатает узел на экран
/// @param [in] pnode указатель на узел
void node_print(const node_t *pnode);

#endif