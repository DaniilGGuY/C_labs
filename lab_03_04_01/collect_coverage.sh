#!/bin/bash

cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
echo "Checking coverage of tests"
gcov main.c
gcov arr_func.c
./clean.sh
