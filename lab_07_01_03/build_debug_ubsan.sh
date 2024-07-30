#!/bin/bash

cd out/ || exit
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c ./../src/main.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c ./../src/file_funcs.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c ./../src/arr_funcs.c
clang -fsanitize=undefined -fno-omit-frame-pointer -g -o ./../app.exe main.o file_funcs.o arr_funcs.o
cd ../ || exit
