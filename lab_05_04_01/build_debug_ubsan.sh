#!/bin/bash

clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c bin_file_funcs.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c txt_file_funcs.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c student.c
clang -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe main.o bin_file_funcs.o txt_file_funcs.o student.o
