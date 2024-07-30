#ifndef CHECK_HEAD_H__
#define CHECK_HEAD_H__

#include "arr_funcs.h"
#include "error_codes.h"
#include <check.h>

#define EXIT_SUCSESS 0
#define EXIT_FAILURE 1

Suite* filt_arr(void);

Suite* sort_arr(void);

#endif