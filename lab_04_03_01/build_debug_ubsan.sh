#!/bin/bash

clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c str_funcs.c
clang -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe main.o str_funcs.o