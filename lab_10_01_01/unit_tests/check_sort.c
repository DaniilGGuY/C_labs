#include "check_head.h"

// Сортировка с 1 элементом
START_TEST(sort_one)
{
    char *arr[1] = { "a" };
    char *arr_ans[1] = { "a" };
    node_t *head = list_by_array(arr, 1);
    node_t *ans = list_by_array(arr_ans, 1);
    node_t *res = sort(head, comp);
    ck_assert_int_eq(1, comp_lists(res, ans) == 0);
    list_free(res);
    list_free(ans);
}
END_TEST

// Сортировка 2 отсортированных элементов
START_TEST(two_sorted)
{
    char *arr[2] = { "a", "b" };
    char *arr_ans[2] = { "a", "b" };
    node_t *head = list_by_array(arr, 2);
    node_t *ans = list_by_array(arr_ans, 2);
    node_t *res = sort(head, comp);
    ck_assert_int_eq(1, comp_lists(res, ans) == 0);
    list_free(res);
    list_free(ans);
}
END_TEST

// Сортировка 2 неотсортированных элементов
START_TEST(two_non_sorted)
{
    char *arr[2] = { "b", "a" };
    char *arr_ans[2] = { "a", "b" };
    node_t *head = list_by_array(arr, 2);
    node_t *ans = list_by_array(arr_ans, 2);
    node_t *res = sort(head, comp);
    ck_assert_int_eq(1, comp_lists(res, ans) == 0);
    list_free(res);
    list_free(ans);
}
END_TEST

// Сортировка с 3 элементами
START_TEST(three_rands)
{
    char *arr[3] = { "b", "a", "c" };
    char *arr_ans[3] = { "a", "b", "c" };
    node_t *head = list_by_array(arr, 3);
    node_t *ans = list_by_array(arr_ans, 3);
    node_t *res = sort(head, comp);
    ck_assert_int_eq(1, comp_lists(res, ans) == 0);
    list_free(res);
    list_free(ans);
}
END_TEST

Suite* check_sort(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("sort");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, sort_one);
    tcase_add_test(tests, two_sorted);
    tcase_add_test(tests, two_non_sorted);
    tcase_add_test(tests, three_rands);

    suite_add_tcase(s, tests);

    return s;
}