#!/bin/bash

clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c arr_films.c
clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -c film.c
clang -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe main.o arr_films.o film.o 
