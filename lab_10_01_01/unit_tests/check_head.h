#ifndef CHECK_HEAD_H__
#define CHECK_HEAD_H__

#include <check.h>

#include "list.h"
#include "list_node.h"
#include "node.h"
#include "err_codes.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define N           10

int comp_lists(node_t *l, node_t *r);

node_t *list_by_array(char *arr[], size_t size);

Suite* check_find(void);

Suite* check_fb_split(void);

Suite* check_insert(void);

Suite* check_sort(void);

Suite* check_rm_dups(void);

#endif