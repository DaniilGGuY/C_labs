#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c file_funcs.c
clang -fsanitize=address -fno-omit-frame-pointer -g -o app.exe main.o file_funcs.o

