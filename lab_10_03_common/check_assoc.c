#include "check_head.h"

static void action(const char *key, int *num, void *param)
{
    if (key && key[0] == 'a')
        (*num) += 2;
    
    param = param;
}


START_TEST(check_assoc_correct_work)
{
    assoc_array_error_t rc;
    int *pointer;
    assoc_array_t assoc = assoc_array_create(); // создание массива
    ck_assert_int_eq(1, assoc != NULL);

    rc = assoc_array_insert(assoc, "e", 5); // вставка в пустой массив
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_min(assoc, &pointer); // минимум в массиве из одного элемента
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(5, *pointer);

    rc = assoc_array_insert(assoc, "f", 6); // вставка в конец массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_max(assoc, &pointer); // максимум в массиве из 2 элемментов
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(6, *pointer);

    rc = assoc_array_insert(assoc, "a", 1); // вставка в начало массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_find(assoc, "b", &pointer); // элемент не найден 
    ck_assert_int_eq(ASSOC_ARRAY_NOT_FOUND, rc);

    rc = assoc_array_find(assoc, "a", &pointer); // элемент найден
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(1, *pointer);

    rc = assoc_array_insert(assoc, "z", 26); // вставка в конец массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_max(assoc, &pointer); // максимум в массиве
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(26, *pointer);

    rc = assoc_array_remove(assoc, "z"); // удаляем максимум
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_max(assoc, &pointer); // максимум в массиве
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(6, *pointer);

    rc = assoc_array_insert(assoc, "b", 2); // вставка в центр
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_each(assoc, action, NULL); // добавляем к значению первого элемента 2
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_min(assoc, &pointer); // минимум в массиве
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(3, *pointer);

    rc = assoc_array_remove(assoc, "a"); // удаляем голову массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_remove(assoc, "f"); // удаляем из середины массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_max(assoc, &pointer); // максимум в массиве
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(5, *pointer);

    rc = assoc_array_min(assoc, &pointer); // максимум в массиве
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);
    ck_assert_int_eq(2, *pointer);

    rc = assoc_array_remove(assoc, "e"); // удаляем хвост массива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    rc = assoc_array_remove(assoc, "b"); // удаляем последний элемент мамссива
    ck_assert_int_eq(ASSOC_ARRAY_OK, rc);

    assoc_array_destroy(&assoc); // уничтожение объекта ассоциативный массив
    ck_assert_int_eq(1, assoc == NULL);
}
END_TEST

// Тесты с некорректными параметрами
START_TEST(check_assoc_notcorrect_work)
{
    assoc_array_error_t rc;
    int *pointer;
    assoc_array_t assoc = assoc_array_create(); // создание массива
    ck_assert_int_eq(1, assoc != NULL);

    rc = assoc_array_insert(NULL, "z", 26); 
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_insert(assoc, "", 26);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_insert(assoc, NULL, 26);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_find(NULL, "b", &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_find(assoc, "", &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_find(assoc, NULL, &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_find(assoc, "a", NULL);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_remove(NULL, "b");
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_remove(assoc, ""); 
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_remove(assoc, NULL); 
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_each(NULL, action, NULL);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_each(assoc, NULL, NULL); 
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_max(NULL, &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_max(assoc, NULL);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_max(assoc, &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_NOT_FOUND, rc);

    rc = assoc_array_min(NULL, &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_min(assoc, NULL);
    ck_assert_int_eq(ASSOC_ARRAY_INVALID_PARAM, rc);

    rc = assoc_array_min(assoc, &pointer);
    ck_assert_int_eq(ASSOC_ARRAY_NOT_FOUND, rc);

    assoc_array_destroy(&assoc); // уничтожение объекта ассоциативный массив
    ck_assert_int_eq(1, assoc == NULL);
}
END_TEST

Suite* check_assoc(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("assoc_array");
    
    tests = tcase_create("tests");
    tcase_add_test(tests, check_assoc_correct_work);
    tcase_add_test(tests, check_assoc_notcorrect_work);

    suite_add_tcase(s, tests);

    return s;
}