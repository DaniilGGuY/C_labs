#!/bin/bash

cd out/ || exit
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c ./../src/main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c ./../src/file_funcs.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c ./../src/arr_funcs.c
gcc -g -o ./../app.exe main.o file_funcs.o arr_funcs.o
cd ../ || exit
