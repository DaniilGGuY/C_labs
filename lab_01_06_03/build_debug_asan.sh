#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -o app.exe main.c
