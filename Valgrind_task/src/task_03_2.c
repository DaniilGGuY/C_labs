#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *x = malloc(5 * sizeof(char));
   
    if (!x)
        return 1;

    x[0] = 'a';
    x[1] = 'b';
    x[2] = 'c';
    x[3] = 'd';
    x[4] = 'e';

    printf("%c\n", x[5]);

    x[5] = 'f';

    free(x);

    return 0;
}

