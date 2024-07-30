#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "arr_funcs.h"

#define N 10000
#define M  1000

typedef void (*sort_t)(void *, size_t, size_t, comp_t);

void gen_array_rand(int arr[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        arr[i] = rand() % N;
}

void gen_array_sort(int arr[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        arr[i] = i;
}

void gen_array_reverse(int arr[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        arr[i] = n - i;
}

void copy(int dest[], int source[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        dest[i] = source[i];
}

void calc_time(int arr[], size_t n, int arr_copy[], sort_t sort, double speed[], size_t m)
{
    for (size_t j = 0; j < m; ++j)
    {
        clock_t beg, end;
        copy(arr, arr_copy, n);
        beg = clock();
        sort(arr, n, sizeof(int), uni_cmp);
        end = clock();
        speed[j] = (double)(end - beg) / CLOCKS_PER_SEC * 1000.0;
    }
}

void calc_params(double times[], size_t m, double *av, double *rse)
{
    *av = 0, *rse = 0;
    for (size_t i = 0; i < m; ++i)
        *av += times[i];
    
    for (size_t i = 0; i < m; ++i)
        *rse += (*av - times[i]) * (*av - times[i]);

    *rse /= m - 1;
    *rse = sqrt(*rse) / sqrt(m);
    *rse = *rse / *av * 100;
}

int main(void)
{
    int arr_rand[N + 1], arr_sorted[N + 1], arr_reverse[N + 1], arr_to_sort[N + 1];
    gen_array_rand(arr_rand, N + 1);
    gen_array_sort(arr_sorted, N + 1);
    gen_array_reverse(arr_reverse, N + 1);

    double av, rse;
    double times[M];
    for (size_t i = 1; i <= 5001; i += 500)
    {
        calc_time(arr_to_sort, i, arr_rand, mysort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Mysort rand array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);

        calc_time(arr_to_sort, i, arr_reverse, mysort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Mysort reverse array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);

        calc_time(arr_to_sort, i, arr_sorted, mysort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Mysort sort array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);

        calc_time(arr_to_sort, i, arr_rand, (sort_t)qsort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Qsort rand array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);

        calc_time(arr_to_sort, i, arr_reverse, (sort_t)qsort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Qsort reverse array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);

        calc_time(arr_to_sort, i, arr_sorted, (sort_t)qsort, times, M);
        calc_params(times, M, &av, &rse);
        printf("Qsort sort array: size - %zu; time - %lf; rse - %lf\n", i, av, rse);
    }

    return 0;
}

