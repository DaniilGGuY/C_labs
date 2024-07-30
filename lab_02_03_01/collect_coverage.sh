#!/bin/bash

cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
echo "Checking coverage of tests"
gcov app-main.c
./clean.sh
