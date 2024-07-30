#include "check_head.h"
#include <stdlib.h>

// Проверка выдачи ошибки результата в случае, когда фильтр не оставляет ни одного элемента
START_TEST(filter_err_res)
{
    int rc;
    const int pb[] = { -1, 0 };
    const int *pe = pb + 2;
    int arr[2];
    int *pb_dst = arr;
    int *pe_dst = NULL;

    rc = key(pb, pe, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_RES);
}
END_TEST

// Проверка выдачи ошибки ввода в случае, когда совпадают указатели на первый и запоследний элемент
START_TEST(filter_empty_arr)
{
    int rc;
    const int pb[] = { 0 };
    const int *pe = pb;
    int arr[1];
    int *pb_dst = arr;
    int *pe_dst = NULL;

    rc = key(pb, pe, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_EMPTY);
}
END_TEST

// Проверка корректности фильтрации массива, в котором единственный отрицательный элемент последний
START_TEST(filter_correct_arr)
{
    int rc;
    const int pb[] = { 0, 1, 2, 3, -4 };
    const int *pe = pb + 5;
    int arr[5];
    int *pb_dst = arr;
    int *pe_dst = NULL;

    rc = key(pb, pe, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_mem_eq(pb, pb_dst, 4 * sizeof(int));
}
END_TEST

// Проверка корректности фильтрации массива, в котором только отрицательные элементы
START_TEST(filter_correct_arr_with_negs)
{
    int rc;
    const int pb[] = { -1, -2, -3, -4, -4 };
    const int *pe = pb + 5;
    int arr[5];
    int *pb_dst = arr;
    int *pe_dst = NULL;

    rc = key(pb, pe, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_mem_eq(pb, pb_dst, 4 * sizeof(int));
}
END_TEST

// Проверка корректности фильтрации массива, в котором только положительные элементы
START_TEST(filter_correct_arr_without_negs)
{
    int rc;
    const int pb[] = { 1, 2, 3, 4, 4 };
    const int *pe = pb + 5;
    int arr[5];
    int *pb_dst = arr;
    int *pe_dst = NULL;

    rc = key(pb, pe, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_OK);
    ck_assert_mem_eq(pb, pb_dst, 5 * sizeof(int));
}
END_TEST

Suite* filt_arr(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("filt_arr");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, filter_err_res);
    tcase_add_test(tc_neg, filter_empty_arr);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, filter_correct_arr);
    tcase_add_test(tc_pos, filter_correct_arr_with_negs);
    tcase_add_test(tc_pos, filter_correct_arr_without_negs);

    suite_add_tcase(s, tc_pos);

    return s;
}