#include <stdio.h>

int main(void)
{
    char x[] = {'A', 'B', 'C', 'D', 'E'};

    printf("%c\n", x[5]);

    x[5] = 'F';

    return 0;
}

