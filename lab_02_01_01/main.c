#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERROR_SIZE 1
#define ERROR_IO 2
#define ERROR_RES 3
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

// Функция подсчета результата. Принимает массив, его размер и произведение нечетных
int calc_res(const int a[], size_t n, int *res)
{
    *res = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (a[i] % 2)
        {
            if (*res == 0)
                *res += a[i];
            else
                *res *= a[i];
        }
    }

    if (*res == 0)
        return ERROR_RES;

    return OK;
}


int main(void)
{
    size_t n;
    int res;
    int a[N];
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

    rc = calc_res(a, n, &res);

    switch (rc)
    {
        case ERROR_RES:
            printf("You need to input one more odds value\n");
            return rc;
        case OK:
            printf("Calculated result: %d\n", res);
    }
    
    return rc;
}
