#include <string.h>

#include "list.h"

node_t *list_insert(node_t *list_beg, node_t **list_end, node_t *el)
{
    node_t *cur = list_beg, *next;
    if (!list_beg)
    {
        list_beg = el;
        *list_end = el;
    }
    else if (strcmp(list_beg->key, el->key) > 0)
    {
        el->next = list_beg;
        list_beg = el;
    }
    else
    {
        next = cur->next;
        while (next && strcmp(next->key, el->key) < 0)
        {
            next = next->next;
            cur = cur->next;
        }

        el->next = next;
        cur->next = el;
        if ((*list_end)->next)
            *list_end = (*list_end)->next;
    }

    return list_beg;
}


node_t *list_find(node_t *list_beg, const char *key)
{
    while (list_beg && strcmp(list_beg->key, key) != 0)
        list_beg = list_beg->next;

    return list_beg;
}

node_t *list_remove(node_t *list_beg, node_t **list_end, const char *key)
{
    node_t *cur = list_beg, *next;
    if (!list_beg->next)
    {
        list_beg = NULL;
        *list_end = NULL;
        node_free(cur);
    }
    else if (strcmp(list_beg->key, key) == 0)
    {
        list_beg = list_beg->next;
        node_free(cur);
    }
    else
    {
        next = cur->next;
        while (next && strcmp(next->key, key) < 0)
        {
            cur = cur->next;
            next = next->next;
        }

        cur->next = next->next;
        if (!next->next)
            *list_end = cur;
        node_free(next);
    }

    return list_beg;
}
