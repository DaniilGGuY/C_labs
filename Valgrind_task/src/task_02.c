#include <stdio.h>
#include <time.h>

void foo(int x)
{
    if (x < 10)
        printf("x is less than 10\n");
}

int main(void)
{
    int y;
    time_t now = time(NULL);

    if (now == 0)
	    y = 99;
    foo(y);

    return 0;
}

