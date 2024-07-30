#!/bin/bash

clang -std=c99 -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe main.c
