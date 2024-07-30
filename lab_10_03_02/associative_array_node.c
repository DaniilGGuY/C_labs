#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#include "associative_array_node.h"

node_t *node_create(const char *key, int num)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        char *new_key = strdup(key);
        if (!new_key)
            free(node);
        else
        {
            node->key = (char *)new_key;
            node->num = num;
            node->left = NULL;
            node->right = NULL;
        }
    }

    return node;
}

void node_free(node_t *node)
{
    free(node->key);
    free(node);
}