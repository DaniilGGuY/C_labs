#ifndef CHECK_HEAD_H__
#define CHECK_HEAD_H__

#include "calculation.h"
#include "list.h"
#include "node.h"
#include "err_codes.h"

#include <check.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int check_equal(node_t *a, node_t *b);

node_t *list_by_array(int arr[], size_t size);

Suite* check_mult(void);

Suite* check_square(void);

Suite* check_division(void);

Suite* check_form(void);

#endif
