#ifndef ASSOCIATIVE_ARRAY_NODE_H__
#define ASSOCIATIVE_ARRAY_NODE_H__

typedef struct node node_t;

struct node
{
    char *key;
    int num;
    node_t *next;
};

/// @brief функция создания узла
/// @param [in] key ключ
/// @param [in] num значение
/// @return искомый узел
node_t *node_create(const char *key, int num);

/// @brief функция очистки памяти из-под узла
/// @param [out] node узел
void node_free(node_t *node);

#endif