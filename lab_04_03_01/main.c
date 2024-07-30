#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "str_funcs.h"
#include "defines.h"


int main(void)
{
    char str[STR_LEN + 1], str_out[STR_LEN + 1];
    char words[N][WORD_LEN + 1];
    size_t n;
    int rc = read_string(str);
    if (rc)
    {
        switch (rc)
        {
            case ERR_IO:
                printf("There is trouble with reading string\n");
                return rc;
            case ERR_LEN_STR:
                printf("This str is so long\n");
                return rc;
            default:
                printf("Another type of error\n");
                return rc;
        }
    }

    rc = parse_string(str, words, &n);
    if (rc)
    {
        switch (rc)
        {
            case ERR_LEN_WORD:
                printf("So long word\n");
                return rc;
            case ERR_IO:
                printf("There is no one word. Input one more\n");
                return rc;
            default:
                printf("Another type of error\n");
                return rc;
        }
    }

    rc = add_words_in_string(words, n, str_out);
    if (rc)
    {
        switch (rc)
        {
            case ERR_RES:
                printf("In outline no one word\n");
                return rc;
            default:
                printf("Another type of error\n");
                return rc;
        }
    }
    
    printf("Result: %s\n", str_out);
    
    return OK;
}
