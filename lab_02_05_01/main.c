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
    int *p_left = pa;
    int *p_right = pb - 1;
    while (p_left != pb - 1 && p_right != pa)
    {
        while (*p_left >= 0 && p_left != pb - 1)
            p_left += 1;

        while (*p_right <= 0 && p_right != pa)
            p_right -= 1;

        if (*p_left < 0 && *p_right > 0)
        {
            *res += *p_left * *p_right;
            if (p_left != pb - 1 && p_right != pa)
            {
                p_right -= 1;
                p_left += 1;
            }
        }
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

    if (res == 0)
    {
        printf("Error num of positive or negative value");
        return ERROR_RES;
    }

    printf("Result: %d\n", res);
    return OK;
}
