#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c main.c
clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c arr_func.c
clang -fsanitize=address -fno-omit-frame-pointer -g -o app.exe main.o arr_func.o

