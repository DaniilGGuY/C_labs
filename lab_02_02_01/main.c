#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define OK 0
#define ERROR_SIZE 1
#define ERROR_IO 2
#define ERROR_RES 3
#define N 10

// Функция проверяет число на простоту. Принимает число
bool is_simple(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return 0;

    return 1;
}

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

// Функция копирует простые числа из 1 массива во второйю Принимает первый массив с его размер и второй массив с его размером
int copy(const int a1[], size_t n1, int a2[], size_t *n2)
{
    size_t j = 0;
    for (size_t i = 0; i < n1; ++i)
    {
        if (is_simple(a1[i]))
        {
            a2[j] = a1[i];
            ++j;
        }
    }

    *n2 = j;
    
    if (*n2 == 0)
        return ERROR_RES;
        
    return OK;
}


int main(void)
{
    size_t n1, n2;
    int a1[N], a2[N];
    int rc = input(a1, &n1);
    switch (rc)
    {
        case ERROR_IO:
            printf("Incorrect input");
            return rc;
        case ERROR_SIZE:
            printf("Incorrect size");
            return rc;
    }

    rc = copy(a1, n1, a2, &n2);
    switch (rc)
    {
        case ERROR_RES:
            printf("Incorrect input/ You need to input one more simple value\n");
            return rc;
        case OK:
            print(a2, n2);
    }
    
    return OK;
}

