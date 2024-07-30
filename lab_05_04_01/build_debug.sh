#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c bin_file_funcs.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c txt_file_funcs.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c student.c
gcc -g -o app.exe main.o bin_file_funcs.o txt_file_funcs.o student.o
