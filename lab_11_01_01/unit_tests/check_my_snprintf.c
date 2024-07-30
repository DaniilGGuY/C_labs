#include <string.h>

#include "check_head.h"

// Нет спецификаторов
START_TEST(no_speces)
{
    char buf[8], my_buf[8];
    int read = snprintf(buf, sizeof(buf), "Hello!");
    int my_read = my_snprintf(my_buf, sizeof(buf), "Hello!");
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор строки
START_TEST(only_string)
{
    char buf[8], my_buf[8];
    int read = snprintf(buf, sizeof(buf), "%s", "Hello!");
    int my_read = my_snprintf(my_buf, sizeof(buf), "%s", "Hello!");
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа
START_TEST(only_number)
{
    char buf[8], my_buf[8];
    long int a = 9;
    int read = snprintf(buf, sizeof(buf), "%lo", a);
    int my_read = my_snprintf(my_buf, sizeof(buf), "%lo", a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 2 
START_TEST(only_number_2)
{
    char buf[8], my_buf[8];
    long int a = 10;
    int read = snprintf(buf, 2, "%lo", a);
    int my_read = my_snprintf(my_buf, 2, "%lo", a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 3
START_TEST(only_number_3)
{
    char buf[8], my_buf[8];
    long int a = 8;
    int read = snprintf(buf, 2, "%lo", a);
    int my_read = my_snprintf(my_buf, 2, "%lo", a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 4
START_TEST(only_number_4)
{
    char buf[8], my_buf[8];
    long int a = 7;
    int read = snprintf(buf, 2, "%lo", a);
    int my_read = my_snprintf(my_buf, 2, "%lo", a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 5
START_TEST(only_number_5)
{
    char buf[8], my_buf[8];
    long int a = 9;
    int read = snprintf(buf, sizeof(buf), "%lo%lo", a, a);
    int my_read = my_snprintf(my_buf, sizeof(buf), "%lo%lo", a, a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 6
START_TEST(only_number_6)
{
    char buf[8], my_buf[8];
    long int a = 9, b = 0;
    int read = snprintf(buf, sizeof(buf), "%lo%lo", a, b);
    int my_read = my_snprintf(my_buf, sizeof(buf), "%lo%lo", a, b);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 7
START_TEST(only_number_7)
{
    char buf[8], my_buf[8];
    long int a = -9, b = 0;
    int read = snprintf(buf, sizeof(buf), "%lo%lo", a, b);
    int my_read = my_snprintf(my_buf, sizeof(buf), "%lo%lo", a, b);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификатор числа 8. Граничный тест
START_TEST(stress_test)
{
    char buf[8], my_buf[8];
    long int a = 0 - 1, b = 0;
    int read = snprintf(buf, sizeof(buf), "%lo%lo", a, b);
    int my_read = my_snprintf(my_buf, sizeof(buf), "%lo%lo", a, b);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Только спецификаторы
START_TEST(only_speces)
{
    char buf[20], my_buf[20];
    long int a = 9;
    int read = snprintf(buf, sizeof(buf), "%s%lo%s", "a", a, "b");
    int my_read = my_snprintf(my_buf, sizeof(buf), "%s%lo%s", "a", a, "b");
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Комплексный тест
START_TEST(complex_test)
{
    char buf[20], my_buf[20];
    long int a = 9;
    int read = snprintf(buf, sizeof(buf), "L: %s%lo%s", "a", a, "b");
    int my_read = my_snprintf(my_buf, sizeof(buf), "L: %s%lo%s", "a", a, "b");
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Комплексный тест 2
START_TEST(complex_test_2)
{
    char buf[20], my_buf[20];
    long int a = 9;
    int read = snprintf(buf, sizeof(buf), "L: %s%s%s %lo", "a", "Hello", "b", a);
    int my_read = my_snprintf(my_buf, sizeof(buf), "L: %s%s%s %lo", "a", "Hello", "b", a);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Комплексный тест 3
START_TEST(complex_test_3)
{
    char buf[50], my_buf[50];
    long int a = 9, b = 18;
    int read = snprintf(buf, sizeof(buf), "Today in %lo in %s with %lo", a, "school", b);
    int my_read = my_snprintf(my_buf, sizeof(buf), "Today in %lo in %s with %lo", a, "school", b);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Комплексный тест 4
START_TEST(complex_test_4)
{
    char buf[50], my_buf[50];
    long int b = 18;
    int read = snprintf(buf, sizeof(buf), "90 of %s is %lo", "oxygen", b);
    int my_read = my_snprintf(my_buf, sizeof(buf), "90 of %s is %lo", "oxygen", b);
    ck_assert_str_eq(buf, my_buf);
    ck_assert_int_eq(read, my_read);
}
END_TEST

// Тесты для проверки поведения при передаче различных параметров
START_TEST(all_types)
{
    char buf[8];
    int read;

    read = my_snprintf(buf, 0, "abc");
    ck_assert_int_eq(read, 3);

    read = my_snprintf(NULL, 0, "abc");
    ck_assert_int_eq(read, 3);
}
END_TEST

Suite *check_my_snprintf(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("my_snprintf");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, no_speces);
    tcase_add_test(tests, only_string);
    tcase_add_test(tests, only_number);
    tcase_add_test(tests, only_number_2);
    tcase_add_test(tests, only_number_3);
    tcase_add_test(tests, only_number_4);
    tcase_add_test(tests, only_number_5);
    tcase_add_test(tests, only_number_6);
    tcase_add_test(tests, only_number_7);
    tcase_add_test(tests, stress_test);
    tcase_add_test(tests, only_speces);
    tcase_add_test(tests, complex_test);
    tcase_add_test(tests, complex_test_2);
    tcase_add_test(tests, complex_test_3);
    tcase_add_test(tests, complex_test_4);
    tcase_add_test(tests, all_types);

    suite_add_tcase(s, tests);

    return s;
}