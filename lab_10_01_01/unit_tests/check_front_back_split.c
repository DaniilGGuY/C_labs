#include "check_head.h"

// Нечетное количество элементов
START_TEST(odd_count)
{
    char *arr[3] = { "a", "c", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *right;
    front_back_split(head, &right);
    ck_assert_int_eq(1, head->next->next == NULL);
    list_free(head);
    list_free(right);
}
END_TEST

// Четное количество элементов
START_TEST(even_count)
{
    char *arr[4] = { "a", "c", "b", "d" };
    node_t *head = list_by_array(arr, 4);
    node_t *right;
    front_back_split(head, &right);
    ck_assert_int_eq(1, head->next->next == NULL);
    list_free(head);
    list_free(right);
}
END_TEST

// Один элемент
START_TEST(one_el)
{
    char *arr[1] = { "a" };
    node_t *head = list_by_array(arr, 1);
    node_t *right = NULL;
    front_back_split(head, &right);
    ck_assert_int_eq(1, head->next == NULL && right == NULL);
    list_free(head);
}
END_TEST

Suite* check_fb_split(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("front_back_split");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, odd_count);
    tcase_add_test(tests, even_count);
    tcase_add_test(tests, one_el);

    suite_add_tcase(s, tests);

    return s;
}