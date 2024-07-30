#include <math.h>
#include <stdbool.h>

#include "list.h"
#include "err_codes.h"

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

void list_print(node_t *head)
{
    while (head != NULL)
    {
        node_print(head);
        head = head->next;
    }
    
    printf("L");
}

static bool check_prime(int x)
{
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0)
            return false;
    
    return true;
}

int list_form_by_num(node_t **head, int val)
{
    node_t *list = NULL;
    int degree = 0, del = 2;

    while (val > 1)
    {
        if (check_prime(del))
        {
            while (val % del == 0)
            {
                ++degree;
                val /= del;
            }

            node_t *new_node = node_create(degree);
            if (new_node)
                list = list_add_tail(list, new_node);
            else
                return ERR_MEM;
            
            degree = 0;
        }

        ++del;
    }

    *head = list;
    return OK;
}

node_t *cut_list(node_t *head)
{
    node_t *cur = head, *find = head;
    while (find)
    {
        if (find->num != 0)
            cur = find;

        find = find->next;
    }

    if (cur && cur->num != 0 && cur->next)
    {
        list_free(cur->next);
        cur->next = NULL;
    }
    else if (cur == head && cur->num == 0)
    {
        list_free(cur);
        head = NULL;
    }

    return head;
}

int add_list_to_list(node_t *a, node_t **c)
{
    while (a)
    {
        node_t *el = node_create(a->num);
        if (el)
            *c = list_add_tail(*c, el);
        else
            return ERR_MEM;

        a = a->next;
    }

    return OK;
}