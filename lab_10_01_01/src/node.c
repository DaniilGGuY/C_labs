#include <stdlib.h>

#include "node.h"

node_t *node_create(void *data)
{
    node_t *new_el = malloc(sizeof(node_t));

    if (new_el)
    {
        new_el->data = data;
        new_el->next = NULL;
    }

    return new_el;
}

void node_free(node_t *pnode)
{
    free(pnode);
}

void node_free_data(node_t *pnode)
{
    free(pnode->data);
    free(pnode);
}

void node_print(FILE *f, const node_t *pnode)
{
    fprintf(f, "%s\n", (char *)pnode->data);
}

