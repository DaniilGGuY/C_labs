#ifndef ARR_FUNCS_H__
#define ARR_FUNCS_H__

#include <stdio.h>

typedef int (*comp_t)(const void *, const void *, size_t);

/// @brief функция сравнения элементов
/// @param l - первый элемент (in)
/// @param r - второй элемент (in)
/// @param size - размер одного элемента (in)
/// @return результат сравнения
int uni_cmp(const void *l, const void *r, size_t size);

/// @brief функция фильтрации массива
/// @param pb_src - указатель на первый элемент исходного массива (in)
/// @param pe_src - указатель на запоследний элемент исходного массива (in)
/// @param pb_dst - указатель на первый элемент отфильтрованного массива (out)
/// @param pe_dst - указатель на запоследний элемент отфильтрованного массива (out)
/// @return код ошибки
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

/// @brief функция обменв элементов
/// @param l - первый элемент (out)
/// @param r - второй элемент (out)
/// @param elem_size - размер элемента (in)
void swap(void *l, void *r, size_t elem_size);

/// @brief функция сортировки массива
/// @param base - указатель на первый элемент массива (out)
/// @param num - количество элементов в массиве (in)
/// @param size - размер одного элемента (in)
/// @param comp - функция компаратор (in)
void mysort(void *base, size_t num, size_t size, comp_t comp);

#endif