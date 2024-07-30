#ifndef MY_LIB_H__
#define MY_LIB_H__

#include <stdio.h>

#define ERR_OK    0
#define ERR_IO    1
#define ERR_EMPTY 3
#define ERR_RES   4
#define ERR_PARAM 7
typedef int (*comp_t)(const void *, const void *, size_t);

/// @brief функция сравнения элементов
/// @param l - первый элемент (in)
/// @param r - второй элемент (in)
/// @param size - размер одного элемента (in)
/// @return результат сравнения
int uni_cmp(const void *l, const void *r, size_t size);

/// @brief Функция поиска позиции последнего отрицательного элемента в массиве 
/// @param pb_src указатель на первый элемент в массиве
/// @param ind указатель на последний элемент в массиве
void find_pos(const int *pb_src, const int **ind);

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

/// @brief функция чтения количества целочисленных элементов из файла
/// @param f - имя файла (in)
/// @param count - количество целочисленных элементов(out)
/// @return код ошибки
int read_elems_count(FILE *f, size_t *count);

/// @brief функция чтения целочисленных элементов из файла
/// @param f - имя файла (in)
/// @param pbeg - указатель на первый элемент массива (in)
/// @param pend - указатель на запоследний элемент массива (in)
int read_elems(FILE *f, int *const pbeg, int *const pend);

/// @brief функция записи целочисленных элементов в файл
/// @param f - имя файла (in)
/// @param pbeg - указатель на первый элемент массива (in)
/// @param pend - указатель на запоследний элемент массива (in)
void write_elems(FILE *f, const int *const pbeg, const int *const pend);

#endif