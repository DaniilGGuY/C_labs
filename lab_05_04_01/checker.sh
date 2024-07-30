#!/bin/bash

echo "BUILDING RELEASE..."
./build_release.sh
cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
./clean.sh

echo "BUILDING DEBUG WITH ASAN..."
./build_debug_asan.sh
cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
./clean.sh

echo "BUILDING DEBUG WITH MSAN..."
./build_debug_msan.sh
cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
./clean.sh

echo "BUILDING DEBUG WITH UBSAN..."
./build_debug_ubsan.sh
cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
./clean.sh

echo "BUILDING DEBUG..."
./build_debug.sh
cd func_tests/scripts || exit
./func_tests.sh
cd ../..
echo
./clean.sh

