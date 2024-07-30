#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -I ./../inc/ -c main.c -lm
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -I ./../inc/ -c ./../src/arr_funcs.c -lm
gcc --coverage -o ./app.exe main.o arr_funcs.o -lm

./app.exe
rm *.exe *.o *.gcno
