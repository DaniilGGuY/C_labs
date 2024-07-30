#include "check_head.h"

// Проверка ошибки при передачи нулевого указателя
START_TEST(err_array)
{
    int rc = cycle_left_shift(NULL, 2, 1);
    ck_assert_int_eq(rc, ERR_ARGS);
}
END_TEST

// Проверка ошибки при передачи нулевого размера
START_TEST(err_size)
{
    int rc;
    int arr[5] = { 1, 2, 3, 4, 5 };
    rc = cycle_left_shift(arr, 0, 1);
    ck_assert_int_eq(rc, ERR_ARGS);
}
END_TEST

// Проверка левого сдвига
START_TEST(shift_left)
{
    int rc;
    int arr[5] = { 1, 2, 3, 4, 5 };
    int ans[5] = { 3, 4, 5, 1, 2 };
    rc = cycle_left_shift(arr, 5, 2);
    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(arr, ans, 5);
}
END_TEST

// Проверка полного циклического сдвига
START_TEST(full_shift)
{
    int rc;
    int arr[5] = { 1, 2, 3, 4, 5 };
    int ans[5] = { 1, 2, 3, 4, 5 };
    rc = cycle_left_shift(arr, 5, 25);
    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(arr, ans, 5);
}
END_TEST

// Проверка правого сдвига
START_TEST(shift_right)
{
    int rc;
    int arr[5] = { 1, 2, 3, 4, 5 };
    int ans[5] = { 3, 4, 5, 1, 2 };
    rc = cycle_left_shift(arr, 5, -3);
    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(arr, ans, 5);
}
END_TEST

Suite* shift_arr(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("shift_arr");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, err_array);
    tcase_add_test(tests, err_size);
    tcase_add_test(tests, shift_left);
    tcase_add_test(tests, full_shift);
    tcase_add_test(tests, shift_right);

    suite_add_tcase(s, tests);

    return s;
}