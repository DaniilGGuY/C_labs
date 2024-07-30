#include "check_head.h"
#include <stdlib.h>
#include <math.h>

int check_equal(node_t *a, node_t *b)
{
    while (a && b)
    {
        if (a->num != b->num)
            return 0;

        a = a->next;
        b = b->next;
    }

    if (a || b)
        return 0;

    return 1;
}

node_t *list_by_array(int arr[], size_t size)
{
    node_t *head = NULL;
    for (size_t i = size; i > 0; --i)
    {
        node_t *pnode = malloc(sizeof(node_t));
        if (pnode)
        {
            pnode->next = head;
            pnode->num = arr[i - 1];
        }

        head = pnode;
    }

    return head;
}

// Тест, когда формируется список по числу 1
START_TEST(form_by_one)
{
    int val = 1, rc;
    node_t *ans = NULL, *a = NULL;
    rc = list_form_by_num(&a, val);
    ck_assert_int_eq(1, check_equal(ans, a));
    ck_assert_int_eq(OK, rc);
    list_free(a);
}
END_TEST

// Тест, когда формируется список по простому числу
START_TEST(form_by_prime_num)
{
    int val = 5, rc;
    int arr[3] = { 0, 0, 1 };
    node_t *ans = list_by_array(arr, 3), *a; 
    rc = list_form_by_num(&a, val);
    ck_assert_int_eq(1, check_equal(ans, a));
    ck_assert_int_eq(OK, rc);
    list_free(a);
    list_free(ans);
}
END_TEST

// Тест, когда формируется список по составному числу
START_TEST(form_by_composite_num)
{
    int val = 6, rc;
    int arr[2] = { 1, 1 };
    node_t *ans = list_by_array(arr, 2), *a; 
    rc = list_form_by_num(&a, val);
    ck_assert_int_eq(1, check_equal(ans, a));
    ck_assert_int_eq(OK, rc);
    list_free(a);
    list_free(ans);
}
END_TEST

Suite* check_form(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("form by num");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, form_by_one);
    tcase_add_test(tests, form_by_prime_num);
    tcase_add_test(tests, form_by_composite_num);

    suite_add_tcase(s, tests);

    return s;
}