#include <string.h>
#include <stdlib.h>

#include "associative_array.h"
#include "associative_array_node.h"
#include "list.h"

struct assoc_array_type
{
    node_t *head;
    node_t *tail;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t new_el = malloc(sizeof(struct assoc_array_type));

    if (new_el)
    {
        new_el->head = NULL;
        new_el->tail = NULL;
    }

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

    arr->head = list_insert(arr->head, &arr->tail, el);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!key || !num || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    node_t *cur = list_find(arr->head, key);
    
    if (!cur)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &cur->num;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    int *val = NULL;
    if (assoc_array_find(arr, key, &val) == ASSOC_ARRAY_NOT_FOUND)
        return ASSOC_ARRAY_NOT_FOUND;
    
    arr->head = list_remove(arr->head, &arr->tail, key);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    node_t *cur = arr->head, *next;
    while (cur)
    {
        next = cur->next;
        node_free(cur);
        cur = next;
    }

    arr->head = NULL;
    arr->tail = NULL;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (node_t *pcur = arr->head; pcur; pcur = pcur->next)
        action(pcur->key, &pcur->num, param);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!num || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->head->num;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!num || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->tail->num;

    return ASSOC_ARRAY_OK;
}
