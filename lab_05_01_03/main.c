#include <stdio.h>
#include "defines.h"
#include "file_funcs.h"

int main(void)
{
    FILE *f = stdin;
    size_t col;
    int rc = process(f, &col);
    
    if (rc == OK)
        printf("There is %zu signs changes\n", col);
    else if (rc == ERR_IO)
        printf("There is no one digit\n");
    else
        printf("Another type of error\n");
    
    return rc;
}
