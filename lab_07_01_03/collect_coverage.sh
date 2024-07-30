#!/bin/bash

cd out/ || exit
./../func_tests/scripts/func_tests.sh
echo
echo "Checking coverage of tests..."
gcov -o ./ ./../src/main.c
gcov -o ./ ./../src/arr_func.c
gcov -o ./ ./../src/file_funcs.c
cd ../ || exit