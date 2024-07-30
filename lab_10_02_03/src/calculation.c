#include <stdio.h>

#include "list.h"
#include "calculation.h"
#include "err_codes.h"

int mult(node_t *a, node_t *b, node_t **c)
{
    while (a && b)
    {
        node_t *el = node_create(a->num + b->num);
        if (el)
            *c = list_add_tail(*c, el);
        else
            return ERR_MEM;

        a = a->next;
        b = b->next;
    }

    if (add_list_to_list(a, c))
        return ERR_MEM;

    if (add_list_to_list(b, c))
        return ERR_MEM;

    return OK;
}

int square(node_t *a, node_t **c)
{
    while (a)
    {
        node_t *el = node_create(a->num * 2);
        if (el)
            *c = list_add_tail(*c, el);
        else
            return ERR_MEM;

        a = a->next;
    }

    return OK;
}

int division(node_t *a, node_t *b, node_t **c)
{
    while (a && b)
    {
        if (a->num < b->num)
            return ERR_RES;

        node_t *el = node_create(a->num - b->num);
        if (el)
            *c = list_add_tail(*c, el);
        else
            return ERR_MEM;

        a = a->next;
        b = b->next;
    }

    if (add_list_to_list(a, c))
        return ERR_MEM;
    
    if (b)
        return ERR_RES;

    if (*c)
        *c = cut_list(*c);

    return OK;
}