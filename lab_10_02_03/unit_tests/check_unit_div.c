#include "check_head.h"
#include <stdlib.h>
#include <math.h>

// Делим на единицу
START_TEST(del_by_one)
{
    int rc;
    int arr[3] = { 0, 0, 2 };
    int arr_ans[3] = { 0, 0, 2 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = NULL, *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = division(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(a);
    list_free(c);
    list_free(ans);
}
END_TEST

// Делим на простое число
START_TEST(del_by_prime)
{
    int rc;
    int arr[3] = { 0, 1, 1 };
    int arr_2[2] = { 0, 1 };
    int arr_ans[3] = { 0, 0, 1 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = division(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(b);
    list_free(ans);
}
END_TEST

// Делим на составное число
START_TEST(del_by_composite)
{
    int rc;
    int arr[3] = { 1, 1, 1 };
    int arr_2[2] = { 1, 1 };
    int arr_ans[3] = { 0, 0, 1 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = division(a, b, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(b);
    list_free(ans);
}
END_TEST

// Делим на большее число
START_TEST(second_greater)
{
    int rc;
    int arr[3] = { 0, 1, 1 };
    int arr_2[2] = { 0, 1 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    rc = division(b, a, &c);
    ck_assert_int_eq(ERR_RES, rc);
    list_free(c);
    list_free(a);
    list_free(b);
}
END_TEST

// Деление с остатком
START_TEST(remainder_of_div)
{
    int rc;
    int arr[3] = { 0, 1, 1 };
    int arr_2[2] = { 0, 2 };
    node_t *a = list_by_array(arr, 3);
    node_t *b = list_by_array(arr_2, 2), *c = NULL;
    rc = division(a, b, &c);
    ck_assert_int_eq(ERR_RES, rc);
    list_free(c);
    list_free(a);
    list_free(b);
}
END_TEST

Suite* check_division(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("div");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, del_by_one);
    tcase_add_test(tests, del_by_prime);
    tcase_add_test(tests, del_by_composite);
    tcase_add_test(tests, second_greater);
    tcase_add_test(tests, remainder_of_div);

    suite_add_tcase(s, tests);

    return s;
}