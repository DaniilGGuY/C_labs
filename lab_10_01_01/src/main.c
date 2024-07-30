#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "node.h"
#include "list.h"
#include "list_node.h"
#include "err_codes.h"

int main(int argc, char **argv)
{
    FILE *in, *out;
    node_t *head = NULL, *data_head = NULL;
    int rc = OK;
    if (argc == 3)
    {
        in = fopen(argv[1], "r");
        if (in)
        {
            rc = list_read_from_file(in, &head);
            fclose(in);
        }
        else
            rc = ERR_FILE;
        
        if (!rc)
        {
            rc = create_duplicate_list(head, &data_head);
            if (!rc)
            {
                head = sort(head, comp);
                remove_duplicates(&head, comp);
                out = fopen(argv[2], "w");
                if (out)
                {
                    list_print(out, head);
                    fclose(out);
                }
                else
                    rc = ERR_FILE;
            }
        }

        if (head)
            list_free(head);
        if (data_head)
            list_free_data(data_head);
    }
    else
        rc = ERR_ARGS;

    return rc;
}