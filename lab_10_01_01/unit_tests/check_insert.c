#include "check_head.h"
#include <stdio.h>
#include <stdlib.h>

int comp_lists(node_t *l, node_t *r)
{
    while (l && r)
    {
        if (comp(l->data, r->data) != 0)
            return 1;
        l = l->next;
        r = r->next;
    }

    if (l || r)
        return 1;

    return 0;
}

node_t *list_by_array(char *arr[], size_t size)
{
    node_t *head = NULL;
    for (size_t i = size; i > 0; --i)
    {
        node_t *pnode = malloc(sizeof(node_t));
        if (pnode)
        {
            pnode->next = head;
            pnode->data = arr[i - 1];
        }
        head = pnode;
    }

    return head;
}

// Вставка перед последним
START_TEST(before_last)
{
    char *arr[3] = { "a", "c", "b" };
    char *arr_ans[4] = { "a", "c", "d", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *ans = list_by_array(arr_ans, 4);
    node_t *el = node_create("d");
    node_t *before = head->next->next;
    insert(&head, el, before);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

// Вставка перед первым
START_TEST(before_first)
{
    char *arr[3] = { "a", "c", "b" };
    char *arr_ans[4] = { "d", "a", "c", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *ans = list_by_array(arr_ans, 4);
    node_t *el = node_create("d");
    node_t *before = head;
    insert(&head, el, before);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

Suite* check_insert(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("insert");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, before_first);
    tcase_add_test(tests, before_last);

    suite_add_tcase(s, tests);

    return s;
}