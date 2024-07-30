#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define OK 0
#define ERROR_SIZE 1
#define ERROR_IO 2
#define N 10

// Функция ввода значений. Принимает массив и его размер
int input(int a[], size_t *n)
{
    printf("Input size: ");
    if (scanf("%zu", n) != 1)
        return ERROR_IO;
    if (*n <= 0 || *n > N)
        return ERROR_SIZE;

    for (size_t i = 0; i < *n; ++i)
        if (scanf("%d", &a[i]) != 1)
            return ERROR_IO;

    return OK;
}

// Функция печатает массив. Принимает массив и его размер
void print(const int a[], size_t n)
{
    printf("Array:\n");
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\n");
}

// Функция вставки элемента в позицию. Принимает массив, его размер, индекс вставки и сам вставляемый элемент
void insert(int a[], size_t *n, size_t ind, int el)
{
    int el_next = el;
    for (size_t i = ind; i < *n; ++i)
    {
        el_next = a[i];
        a[i] = el;
        el = el_next;
    }

    a[*n] = el;
    *n = *n + 1;
}

// Функция после каждого элемента, кратного трем, вставляет очередное число Фибоначчи. Принимает массив и его размер
void solve(int a[], size_t *n)
{
    int fib_now = 0, fib_next = 1, tmp;
    size_t i = 0;
    while (i < *n)
    {
        if (abs(a[i]) % 3 == 0)
        {
            i += 1;
            insert(a, n, i, fib_now);
            tmp = fib_now;
            fib_now = fib_next;
            fib_next = tmp + fib_next;
        }

        i += 1;
    }
}


int main(void)
{
    size_t n;
    int a[2 * N];
    int rc = input(a, &n);
    switch (rc)
    {
        case ERROR_IO:
            printf("Incorrect input");
            return rc;
        case ERROR_SIZE:
            printf("Incorrect size");
            return rc;
    }

    solve(a, &n);
    print(a, n);
    return OK;
}
