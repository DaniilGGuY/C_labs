#include "check_head.h"
#include "film.h"
#include <stdlib.h>
#include <math.h>

// Поиск по названию для 1 записи
START_TEST(find_by_title_one)
{
    film_t arr[1] = { { "a", "b", 1 } };
    int pos;
    film_t need = { "a", "c", 2 };
    fa_find(arr, 1, &need, &pos, film_cmp_by_title);
    ck_assert_int_eq(0, pos);
}
END_TEST

// Поиск по имени режиссера для 1 записи не удался
START_TEST(not_found_by_name_one)
{
    film_t arr[1] = { { "a", "b", 1 } };
    int pos;
    film_t need = { "a", "c", 2 };
    fa_find(arr, 1, &need, &pos, film_cmp_by_name);
    ck_assert_int_eq(-1, pos);
}
END_TEST

// Поиск по году
START_TEST(find_by_year)
{
    film_t arr[3] = { { "a", "b", 1 }, { "b", "c", 2 }, { "c", "d", 3 } };
    int pos;
    film_t need = {"a", "c", 3 };
    fa_find(arr, 3, &need, &pos, film_cmp_by_year);
    ck_assert_int_eq(2, pos);
}
END_TEST

// Поиск по названию
START_TEST(find_by_title)
{
    film_t arr[3] = { { "a", "b", 1 }, { "b", "c", 2 }, { "c", "d", 3 } };
    int pos;
    film_t need = {"a", "c", 3 };
    fa_find(arr, 3, &need, &pos, film_cmp_by_title);
    ck_assert_int_eq(0, pos);
}
END_TEST

// Поиск по имени режиссера
START_TEST(find_by_name)
{
    film_t arr[3] = { { "a", "b", 1 }, { "b", "c", 2 }, { "c", "d", 3 } };
    int pos;
    film_t need = { "a", "c", 3 };
    fa_find(arr, 3, &need, &pos, film_cmp_by_name);
    ck_assert_int_eq(1, pos);
}
END_TEST

// Поиск когда есть 2 одинаковых элемента
START_TEST(find_non_unique)
{
    film_t arr[3] = { { "a", "b", 1 }, { "b", "c", 2 }, { "a", "b", 1 } };
    int pos;
    film_t need = {"a", "b", 3 };
    fa_find(arr, 3, &need, &pos, film_cmp_by_name);
    ck_assert_int_eq(0, pos);
}
END_TEST

Suite* check_find(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("search");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, find_by_title_one);
    tcase_add_test(tests, not_found_by_name_one);
    tcase_add_test(tests, find_by_year);
    tcase_add_test(tests, find_by_title);
    tcase_add_test(tests, find_by_name);
    tcase_add_test(tests, find_non_unique);

    suite_add_tcase(s, tests);

    return s;
}