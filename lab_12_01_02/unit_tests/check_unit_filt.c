#include "check_head.h"

// Проверка перевыделения памяти
START_TEST(reallocated)
{
    int rc;
    size_t size = 0;
    int dst[2] = { -1, 0 };
    int filted[1]; 

    rc = filter(dst, 2, filted, &size);
    ck_assert_int_eq(rc, REALLOCATED);
    ck_assert_int_eq(size, 1);
}
END_TEST

// Проверка добавления элемента
START_TEST(added_one_el)
{
    int rc;
    size_t size = 1;
    int dst[2] = { -1, 0 };
    int ans[1] = { 0 };
    int filted[1]; 

    rc = filter(dst, 2, filted, &size);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size, 1);
    ck_assert_mem_eq(ans, filted, 1);
}
END_TEST

// Проверка добавления двух элементов
START_TEST(added_two_els)
{
    int rc;
    size_t size = 2;
    int dst[2] = { 25, 0 };
    int ans[2] = { 25, 0 };
    int filted[2]; 

    rc = filter(dst, 2, filted, &size);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size, 2);
    ck_assert_mem_eq(ans, filted, 2);
}
END_TEST

// Перевыделение с отрицательными числами
START_TEST(with_negs_vals_reallocated)
{
    int rc;
    size_t size = 2;
    int dst[10] = { 25, 0, -1, -4, 4, 3, 0, 8, 16, 10 };
    int filted[10]; 

    rc = filter(dst, 10, filted, &size);
    ck_assert_int_eq(rc, REALLOCATED);
    ck_assert_int_eq(size, 5);
}
END_TEST

// С отрицательными, но без перевыделения
START_TEST(with_negs_vals)
{
    int rc;
    size_t size = 5;
    int dst[10] = { 25, 0, -1, -4, 4, 3, 0, 8, 16, 10 };
    int ans[5] = { 25, 0, 4, 0, 16 };
    int filted[10]; 

    rc = filter(dst, 10, filted, &size);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size, 5);
    ck_assert_mem_eq(ans, filted, 5);
}
END_TEST

// С отрицательными, но переданный размер dst-массива больше
START_TEST(cut_size_dst)
{
    int rc;
    size_t size = 12;
    int dst[10] = { 25, 0, -1, -4, 4, 3, 0, 8, 16, 10 };
    int ans[5] = { 25, 0, 4, 0, 16 };
    int filted[10]; 

    rc = filter(dst, 10, filted, &size);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size, 5);
    ck_assert_mem_eq(ans, filted, 5);
}
END_TEST

// В исходном массиве нет полных квадратов
START_TEST(no_squares)
{
    int rc;
    size_t size = 12;
    int dst[5] = { -1, -4, 3, 8, 10 };
    int filted[12];

    rc = filter(dst, 10, filted, &size);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size, 0);
}
END_TEST

Suite* filt_arr(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("filt_arr");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, reallocated);
    tcase_add_test(tests, added_one_el);
    tcase_add_test(tests, added_two_els);
    tcase_add_test(tests, with_negs_vals_reallocated);
    tcase_add_test(tests, with_negs_vals);
    tcase_add_test(tests, cut_size_dst);
    tcase_add_test(tests, no_squares);

    suite_add_tcase(s, tests);

    return s;
}