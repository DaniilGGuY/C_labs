#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERROR_SIZE 1
#define ERROR_IO 2
#define ERROR_RES 3
#define N 10

// Функция ввода значений. Принимает указатель на первый и на последний элемент массива
int input(int *const pa, int *const pb)
{
    for (int *pc = pa; pc < pb; ++pc)
        if (scanf("%d", pc) != 1)
            return ERROR_IO;

    return OK;
}


// Функция подсчета суммы произведений i с начала отрицательного на i с конца положительного. 
// Принимает указатель на первый и на последний элемент массива и результат вычислений
void calc_res(int *const pa, int *const pb, int *res)
{
    int calc = 1;
    for (int *pc = pa; pc < pb; ++pc)
    {
        calc *= *pc;
        *res += calc;
        if (*pc < 0)
            return;
    }
}


int main(void)
{
    int array[N];
    int res = 0;
    int *const pa = array;
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input size");
        return ERROR_IO;
    }

    if (n <= 0 || n > N)
    {
        printf("Incorrect size");
        return ERROR_SIZE;
    }

    int *const pb = array + n;

    if (input(pa, pb) == ERROR_IO)
    {
        printf("Incorrect input");
        return ERROR_IO;
    }

    calc_res(pa, pb, &res);

    printf("Result: %d\n", res);
    return OK;
}
