#include "check_head.h"
#include <stdlib.h>
#include <math.h>

// Один из множителей единица
START_TEST(mult_with_one)
{
    int rc;
    int arr[3] = { 0, 0, 2 };
    int arr_ans[3] = { 0, 0, 2 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = NULL, *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = mult(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(ans);
}
END_TEST

// Первое число - уникальный простой множитель
START_TEST(mult_with_prime)
{
    int rc;
    int arr[3] = { 0, 0, 1 };
    int arr_2[2] = { 1, 1 };
    int arr_ans[3] = { 1, 1, 1 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = mult(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(b);
    list_free(ans);
}
END_TEST

// Числа с пересекающимися множителями
START_TEST(mult_with_cross_nums)
{
    int rc;
    int arr[3] = { 0, 1, 1 };
    int arr_2[2] = { 1, 1 };
    int arr_ans[3] = { 1, 2, 1 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = mult(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(b);
    list_free(ans);
}
END_TEST

Suite* check_mult(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("mul");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, mult_with_one);
    tcase_add_test(tests, mult_with_prime);
    tcase_add_test(tests, mult_with_cross_nums);

    suite_add_tcase(s, tests);

    return s;
}