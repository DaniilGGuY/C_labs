#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node_t *node_create(int num)
{
    node_t *new_el = malloc(sizeof(node_t));

    if (new_el)
    {
        new_el->num = num;
        new_el->next = NULL;
    }

    return new_el;
}

void node_free(node_t *pnode)
{
    free(pnode);
}

void node_print(const node_t *pnode)
{
    printf("%d ", pnode->num);
}