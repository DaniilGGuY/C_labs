#include "check_head.h"

// Проверка корректности сортировки одного элемента
START_TEST(sort_one_el)
{
    size_t size = 1;
    int pb[] = { 0 };
    const int ans[] = { 0 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки двух отсортированных элементов
START_TEST(sort_two_sorted_els)
{
    size_t size = 2;
    int pb[] = { 1, 2 };
    const int ans[] = { 1, 2 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки двух неотсортированных элементов
START_TEST(sort_two_els)
{
    size_t size = 2;
    int pb[] = { 2, 1 };
    const int ans[] = { 1, 2 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки отсортированного массива
START_TEST(sort_sorted_els)
{
    size_t size = 4;
    int pb[] = { 1, 2, 3, 4 };
    const int ans[] = { 1, 2, 3, 4 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки отсортированного массива с повторениями
START_TEST(sort_sorted_els_with_reps)
{
    size_t size = 4;
    int pb[] = { 1, 2, 3, 3 };
    const int ans[] = { 1, 2, 3, 3 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки отсортированного в обратном порядке массива
START_TEST(sort_reverse_sorted_els)
{
    size_t size = 4;
    int pb[] = { 4, 3, 2, 1 };
    const int ans[] = { 1, 2, 3, 4 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка корректности сортировки массива с отрицательными элементами
START_TEST(sort_with_negs_els)
{
    size_t size = 4;
    int pb[] = { -1, 2, -5, 6 };
    const int ans[] = { -5, -1, 2, 6 };
    mysort(pb, size, sizeof(int), uni_cmp);

    ck_assert_mem_eq(pb, ans, size * sizeof(int));
}
END_TEST

// Проверка сортировки символов
START_TEST(sort_string)
{
    size_t size = 4;
    char pb[] = "acbd";
    const char ans[] = "abcd";
    mysort(pb, size, sizeof(char), uni_cmp);

    ck_assert_mem_eq(ans, pb, size * sizeof(char));
}
END_TEST

Suite* sort_arr(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort_arr");
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, sort_one_el);
    tcase_add_test(tc_pos, sort_two_sorted_els);
    tcase_add_test(tc_pos, sort_two_els);
    tcase_add_test(tc_pos, sort_sorted_els);
    tcase_add_test(tc_pos, sort_sorted_els_with_reps);
    tcase_add_test(tc_pos, sort_reverse_sorted_els);
    tcase_add_test(tc_pos, sort_with_negs_els);
    tcase_add_test(tc_pos, sort_string);

    suite_add_tcase(s, tc_pos);

    return s;
}