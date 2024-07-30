#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#include "err_codes.h"
#include "list_node.h"

node_t *list_add_tail(node_t *head, node_t *pnode)
{
    if (!head)
        head = pnode;
    else
    {
        node_t *cur = head;
        while (cur->next)
            cur = cur->next;
        
        cur->next = pnode;
    }

    return head;
}

int read_str(FILE *f, char **buf)
{
    ssize_t read; 
    size_t len = 0;
    int rc = OK;
    char *tmp = NULL;

    if ((read = getline(&tmp, &len, f)) == -1)
        rc = ERR_MEM;
    if (!rc && tmp[read - 1] == '\n')
        tmp[read - 1] = '\0';
    if (strlen(tmp) < 1 && !rc)
        rc = ERR_IO;

    *buf = tmp;

    return rc;
}

int list_read_from_file(FILE *f, node_t **head)
{
    int rc = OK;
    while (!feof(f) && !rc)
    {
        char *elem;
        rc = read_str(f, &elem);
        if (!rc)
        {   
            node_t *cur = node_create(elem);
            if (cur)
                insert(head, cur, *head);
            else
                rc = ERR_MEM;
        } 
        else
        {
            if (elem)
                free(elem);
        }
    }

    if (!(*head))
        rc = ERR_EMPTY;

    return rc;
}

void list_free(node_t *head)
{
    node_t *cur = head, *next;
    while (cur)
    {
        next = cur->next;
        node_free(cur);
        cur = next;
    }
}

void list_free_data(node_t *head)
{
    node_t *cur = head, *next;
    while (cur)
    {
        next = cur->next;
        node_free_data(cur);
        cur = next;
    }
}

void list_print(FILE *f, node_t *head)
{
    while (head != NULL)
    {
        node_print(f, head);
        head = head->next;
    }
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur = head;

    while (cur && comparator(cur->data, data))
        cur = cur->next;
    
    return cur;
}

void *pop_front(node_t **head)
{
    if (!head)
        return NULL;

    if (!(*head))
        return NULL;

    node_t *cur = *head;
    void *data = cur->data;
    *head = cur->next;
    cur->next = NULL;
    node_free(cur);

    return data;
}

void *pop_back(node_t **head)
{
    if (!head)
        return NULL;

    if (!(*head))
        return NULL;
        
    node_t *cur = *head, *next;
    void *data;
    if (!cur->next)
    {
        data = cur->data;
        *head = cur->next;
        node_free(cur);
    }
    else
    {
        next = cur->next;
        while (next->next)
        {
            cur = cur->next;
            next = next->next;
        }

        data = next->data;
        cur->next = NULL;
        node_free(next);
    }

    return data;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *cur = *head;
    if (*head == before)
    {
        elem->next = *head;
        *head = elem;
    }
    else if (*head)
    {
        while (cur && cur->next != before)
            cur = cur->next;
        
        if (cur)
        {
            elem->next = cur->next;
            cur->next = elem;
        }
    }
}
