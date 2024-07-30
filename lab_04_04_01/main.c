#include <stdio.h>
#include <stdbool.h>
#include "str_funcs.h"
#include "defines.h"


int main(void)
{
    char str[STR_LEN + 1];
    int rc = read_string(str);
    if (rc)
    {
        switch (rc)
        {
            case ERR_IO:
                return rc;
            case ERR_LEN_STR:
                return rc;
            default:
                return rc;
        }
    }

    if (is_correct_exp_val(str))
        printf("YES\n");
    else
        printf("NO\n");

    return OK;
}
