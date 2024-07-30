#include "check_head.h"
#include <stdlib.h>
#include <math.h>

// Возведение 1 в квадрат
START_TEST(square_one)
{
    int rc;
    node_t *ans = NULL, *a = NULL, *c = NULL;
    rc = square(a, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
}
END_TEST

// Возведение в квадрат простого числа
START_TEST(square_prime)
{
    int rc;
    int arr[3] = { 0, 0, 1 };
    int arr_ans[3] = { 0, 0, 2 };
    node_t *a = list_by_array(arr, 3);
    node_t *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = square(a, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(ans);
}
END_TEST

// Возведение в квадрат составного числа
START_TEST(square_composite)
{
    int rc;
    int arr[3] = { 0, 1, 1 };
    int arr_ans[3] = { 0, 2, 2 };
    node_t *a = list_by_array(arr, 3);
    node_t *c = NULL;
    node_t *ans = list_by_array(arr_ans, 3);
    rc = square(a, &c);
    ck_assert_int_eq(1, check_equal(ans, c));
    ck_assert_int_eq(OK, rc);
    list_free(c);
    list_free(a);
    list_free(ans);
}
END_TEST

Suite* check_square(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("sqr");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, square_one);
    tcase_add_test(tests, square_prime);
    tcase_add_test(tests, square_composite);
    
    suite_add_tcase(s, tests);

    return s;
}