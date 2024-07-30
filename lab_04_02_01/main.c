#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "str_funcs.h"
#include "defines.h"


int main(void)
{
    char str[STR_LEN + 1];
    char words[N][WORD_LEN + 1];
    size_t n;
    int rc = read_string(str);
    if (rc)
    {
        switch (rc)
        {
            case ERR_IO:
                printf("There is trouble with read string\n");
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

    sort(words, n);
    printf("Result: ");
    print_words(words, n);

    return OK;
}
