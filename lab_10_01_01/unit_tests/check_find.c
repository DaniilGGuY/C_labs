#include "check_head.h"

// Искомый элемент есть
START_TEST(el_found)
{
    char *arr[3] = { "a", "c", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *el = find(head, "b", comp);
    ck_assert_int_eq(1, (el == head->next->next));
    list_free(head);
}
END_TEST

// Искомого элемента нет
START_TEST(el_not_found)
{
    char *arr[3] = { "a", "c", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *el = find(head, "d", comp);
    ck_assert_int_eq(1, (el == NULL));
    list_free(head);
}
END_TEST

// head - нулевой указатель
START_TEST(null_list)
{
    node_t *el;
    el = find(NULL, "c", comp);
    ck_assert_int_eq(1, el == NULL);
}
END_TEST

Suite* check_find(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("find");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, el_found);
    tcase_add_test(tests, el_not_found);
    tcase_add_test(tests, null_list);

    suite_add_tcase(s, tests);

    return s;
}