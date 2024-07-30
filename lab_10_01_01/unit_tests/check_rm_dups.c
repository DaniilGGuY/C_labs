#include "check_head.h"

// Дубликатов нет
START_TEST(no_dups)
{
    char *arr[3] = { "a", "c", "b" };
    char *arr_ans[3] = { "a", "c", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *ans = list_by_array(arr_ans, 3);
    remove_duplicates(&head, comp);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

// Есть один дубликат
START_TEST(one_dup)
{
    char *arr[3] = { "a", "a", "b" };
    char *arr_ans[2] = { "a", "b" };
    node_t *head = list_by_array(arr, 3);
    node_t *ans = list_by_array(arr_ans, 2);
    remove_duplicates(&head, comp);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

// Два дубликата двух разных элементов
START_TEST(two_dups)
{
    char *arr[4] = { "a", "a", "b", "b" };
    char *arr_ans[2] = { "a", "b" };
    node_t *head = list_by_array(arr, 4);
    node_t *ans = list_by_array(arr_ans, 2);
    remove_duplicates(&head, comp);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

// Список с одинаковыми элементами
START_TEST(dups_of_one_el)
{
    char *arr[4] = { "a", "a", "a", "a" };
    char *arr_ans[1] = { "a" };
    node_t *head = list_by_array(arr, 4);
    node_t *ans = list_by_array(arr_ans, 1);
    remove_duplicates(&head, comp);
    ck_assert_int_eq(0, comp_lists(head, ans));
    list_free(head);
    list_free(ans);
}
END_TEST

Suite* check_rm_dups(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("remove_duplicates");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, no_dups);
    tcase_add_test(tests, one_dup);
    tcase_add_test(tests, two_dups);
    tcase_add_test(tests, dups_of_one_el);

    suite_add_tcase(s, tests);

    return s;
}