#include <string.h>
#include <stdlib.h>

#include "associative_array.h"
#include "associative_array_node.h"
#include "tree.h"

struct assoc_array_type
{
    node_t *root;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t new_el = malloc(sizeof(struct assoc_array_type));

    if (new_el)
        new_el->root = NULL;

    return new_el;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (!arr || !(*arr))
        return;

    (void)assoc_array_clear(*arr);
    free(*arr);
    *arr = NULL;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    int *val = NULL;
    if (assoc_array_find(arr, key, &val) == ASSOC_ARRAY_OK)
        return ASSOC_ARRAY_KEY_EXISTS;

    node_t *el = node_create(key, num);
    if (!el)
        return ASSOC_ARRAY_MEM;

    arr->root = tree_insert(arr->root, el);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!key || !num || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    int *cur = tree_find(arr->root, key);
    
    if (!cur)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = cur;
    
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    int *val = NULL;
    if (assoc_array_find(arr, key, &val) == ASSOC_ARRAY_NOT_FOUND)
        return ASSOC_ARRAY_NOT_FOUND;
    
    arr->root = tree_delete(arr->root, key);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    tree_free(arr->root);

    arr->root = NULL;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;

    tree_each(arr->root, action, param);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!num || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->root)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = tree_get_min(arr->root);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!num || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->root)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = tree_get_max(arr->root);

    return ASSOC_ARRAY_OK;
}
