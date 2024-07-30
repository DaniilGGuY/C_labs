#!/bin/bash

clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c main.c
clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c arr_func.c
clang -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g -o app.exe main.o arr_func.o
