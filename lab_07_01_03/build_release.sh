#!/bin/bash

cd out/ || exit
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -c ./../src/main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -c ./../src/file_funcs.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -c ./../src/arr_funcs.c
gcc --coverage -o ./../app.exe main.o file_funcs.o arr_funcs.o
cd ../ || exit
