#include <stdlib.h>

void f(void)
{
   int *x = malloc(10 * sizeof(int));
   x[10] = 0;      // ошибка 1: доступ за пределы массива
}                  // ошибка 2: утечка памяти (для x не вызывается free)

int main(void)
{
   f();
   return 0;
}

