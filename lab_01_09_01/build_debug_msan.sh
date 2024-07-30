#!/bin/bash

clang -std=c99 -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g -o app.exe main.c -lm
