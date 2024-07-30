#!/bin/bash

echo "BUILDING DEBUG WITH ASAN..."
./build_debug_asan.sh
./func_tests/scripts/func_tests.sh
echo
./clean.sh

echo "BUILDING DEBUG WITH MSAN..."
./build_debug_msan.sh
./func_tests/scripts/func_tests.sh
echo
./clean.sh

echo "BUILDING DEBUG WITH UBSAN..."
./build_debug_ubsan.sh
./func_tests/scripts/func_tests.sh
echo
./clean.sh

echo "BUILDING DEBUG..."
./build_debug.sh
./func_tests/scripts/func_tests.sh
echo
./clean.sh

echo "BUILDING RELEASE..."
./build_release.sh
./func_tests/scripts/func_tests.sh
echo
./clean.sh