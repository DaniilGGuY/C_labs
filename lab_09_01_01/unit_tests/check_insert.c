#include "check_head.h"
#include "film.h"
#include <stdlib.h>
#include <math.h>

static int comp_films(const film_t pl[], const film_t pr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (film_cmp_by_title(pl + i, pr + i) || film_cmp_by_name(pl + i, pr + i) || film_cmp_by_year(pl + i, pr + i))
            return 1;
    }

    return 0;
}

// Вставляется в конец
START_TEST(insert_end)
{
    size_t size = 1;
    film_t arr[2] = { { "a", "b", 1 } }, res[2] = { { "a", "b", 1 }, { "a", "c", 2 } };
    film_t el = { "a", "c", 2 };
    fa_insert(arr, &size, &el, film_cmp_by_title);
    ck_assert_int_eq(1, 0 == comp_films(arr, res, size));
}
END_TEST

// Вставляется в начало
START_TEST(insert_beg)
{
    size_t size = 1;
    film_t arr[2] = { { "a", "c", 1 } }, res[2] = { { "a", "b", 2 }, { "a", "c", 1 } };
    film_t el = { "a", "b", 2 };
    fa_insert(arr, &size, &el, film_cmp_by_name);
    ck_assert_int_eq(1, 0 == comp_films(arr, res, size));
}
END_TEST

// Вставляется в середину
START_TEST(insert_mid)
{
    size_t size = 3;
    film_t arr[4] = { { "a", "b", 1 }, { "b", "c", 2 }, { "c", "d", 3 } };
    film_t res[4] = { { "a", "b", 1 }, { "b", "c", 2 }, {"a", "c", 2 }, { "c", "d", 3 } };
    film_t el = {"a", "c", 2 };
    fa_insert(arr, &size, &el, film_cmp_by_year);
    ck_assert_int_eq(1, 0 == comp_films(arr, res, size));
}
END_TEST

Suite* check_insert(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("insert");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, insert_end);
    tcase_add_test(tests, insert_beg);
    tcase_add_test(tests, insert_mid);

    suite_add_tcase(s, tests);

    return s;
}