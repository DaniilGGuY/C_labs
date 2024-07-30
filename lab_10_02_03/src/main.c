#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "calculation.h"
#include "list.h"
#include "node.h"
#include "err_codes.h"

#define N        5

int read_string(char *str)
{
    char *p;
    if (!fgets(str, N, stdin))
        return ERR_IO;

    p = strchr(str, '\n');
    if (!p)
        return ERR_IO;

    *p = 0;

    return OK;
}

int main(void)
{
    node_t *a_list = NULL, *b_list = NULL, *c_list = NULL;
    char str[N];
    int a, b, rc = OK;

    rc = read_string(str);

    if (!rc)
    {
        if (strcmp(str, "out") == 0)
        {
            if (scanf("%d", &a) != 1 || a < 1)
                rc = ERR_IO;

            if (!rc)
                rc = list_form_by_num(&a_list, a);

            if (!rc)
                list_print(a_list);
        }
        else if (strcmp(str, "mul") == 0)
        {
            if (scanf("%d %d", &a, &b) != 2 || a < 1 || b < 1)
                rc = ERR_IO;

            if (!rc)
                rc = list_form_by_num(&a_list, a);

            if (!rc)
                rc = list_form_by_num(&b_list, b);

            if (!rc)
                rc = mult(a_list, b_list, &c_list);

            if (!rc)
                list_print(c_list);
        }
        else if (strcmp(str, "sqr") == 0)
        {
            if (scanf("%d", &a) != 1 || a < 1)
                rc = ERR_IO;

            if (!rc)
                rc = list_form_by_num(&a_list, a);

            if (!rc)
                rc = square(a_list, &c_list);

            if (!rc)
                list_print(c_list);
        }
        else if (strcmp(str, "div") == 0)
        {
            if (scanf("%d %d", &a, &b) != 2 || a < 1 || b < 1)
                rc = ERR_IO;

            if (!rc)
                rc = list_form_by_num(&a_list, a);

            if (!rc)
                rc = list_form_by_num(&b_list, b);

            if (!rc)
                rc = division(a_list, b_list, &c_list);

            if (!rc)
                list_print(c_list);
        }
        else
            rc = ERR_IO;

        if (a_list)
            list_free(a_list);
        if (b_list)
            list_free(b_list);
        if (c_list)
            list_free(c_list);
    }

    return rc;
}