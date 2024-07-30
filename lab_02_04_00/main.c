#include <stdio.h>

#define OK 0
#define ERROR_SIZE 1
#define ERROR_SPECIAL 100
#define N 10

// Функция ввода значений. Принимает массив и его размер
int input(int a[], size_t *n)
{
    int input_el;
    printf("Input array:\n");
    while (scanf("%d", &input_el) == 1)
    {
        if (*n == N)
            return ERROR_SPECIAL;

        a[*n] = input_el;
        *n += 1;
    }

    if (*n == 0)
        return ERROR_SIZE;

    return OK;
}

// Функция печатает массив. Принимает массив и его размер
void print(const int a[], size_t n)
{
    printf("Sorted array:\n");
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\n");
}

// Функция меняет местами два элемента. Принимает указатели на два элемента массива
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
// Функция сортировки пузырьком. Принимает массив и его размер
void sort(int a[], size_t n)
{
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}
*/

// Функция сортировки выбором. Принимает массивa и его размер
void sort(int a[], size_t n)
{
    int pos = 0;
    for (size_t i = 0; i < n; ++i)
    {
        pos = i;
        for (size_t j = i + 1; j < n; ++j)
            if (a[pos] > a[j])
                pos = j;

        swap(&a[pos], &a[i]);
    }
}


int main(void)
{
    size_t n = 0;
    int a[N];
    int rc = input(a, &n);
    if (rc == ERROR_SIZE)
    {
        printf("Expected non zero size");
        return rc;
    }

    sort(a, n);
    print(a, n);
    if (rc == ERROR_SPECIAL)
    {
        printf("Overflow warning");
        return rc;
    }
    return OK;
}
