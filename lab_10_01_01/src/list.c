#include <stdlib.h>
#include <string.h>

#include "err_codes.h"
#include "list.h"

int comp(const void *l, const void *r)
{
    const char *pl = l;
    const char *pr = r;
    return strcmp(pl, pr);
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (!(*head) || !(*head)->next)
        return;

    node_t *cur = *head;
    while (cur->next)
    {
        if (comparator(cur->data, cur->next->data) == 0)
        {
            node_t *el_del = cur->next;
            cur->next = el_del->next;
            node_free(el_del);
        }
        else
            cur = cur->next;        
    }
}

void front_back_split(node_t *head, node_t **back)
{
    if (!head)
        return;
        
    node_t *cur_1 = head, *cur_2 = head;
    while (cur_2 && cur_2->next && cur_2->next->next)
    {
        cur_2 = cur_2->next->next;
        cur_1 = cur_1->next;
    }
    
    *back = cur_1->next;
    cur_1->next = NULL;
}

/// @brief функция, которая отделяет первый элемент из списка и добавляет в конец другого списка
/// @param [out] head_ans - указатель на голову второй список
/// @param [out] tail_ans - указатель на хвост второго списка
/// @param [out] head - указатель на голову первого списка
static void rearrange_node(node_t **head_ans, node_t **tail_ans, node_t **head)
{
    node_t *node = *head;
    (*head) = (*head)->next;
    node->next = NULL;

    if (*tail_ans)
        (*tail_ans)->next = node;
    else
        (*head_ans) = node;

    *tail_ans = node;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b || !comparator)
        return NULL;
        
    node_t *head_ans = NULL, *tail_ans = NULL;
    while (*head_a || *head_b)
    {
        if (*head_a && *head_b)
        {
            if (comparator((*head_a)->data, (*head_b)->data) >= 0)
                rearrange_node(&head_ans, &tail_ans, head_b);
            else
                rearrange_node(&head_ans, &tail_ans, head_a);
        }
        else if (*head_a)
            rearrange_node(&head_ans, &tail_ans, head_a);
        else if (*head_b)
            rearrange_node(&head_ans, &tail_ans, head_b);
    }

    return head_ans;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !comparator)
        return NULL;

    if (!head->next)
        return head;

    node_t *right;
    front_back_split(head, &right);

    head = sort(head, comparator);
    right = sort(right, comparator);

    return sorted_merge(&head, &right, comparator);
}

int create_duplicate_list(node_t *a, node_t **b)
{
    int rc = OK;
    while (a && !rc)
    {
        node_t *next = node_create(a->data);
        if (!next)
            rc = ERR_MEM;
        else
            *b = list_add_tail(*b, next);
        
        a = a->next;
    }

    return rc;
}
