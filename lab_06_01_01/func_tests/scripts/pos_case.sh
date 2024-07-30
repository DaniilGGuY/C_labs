#!/bin/bash

output="$1"
args=$(cat "$2")
app="./app.exe $args"
$app > "res.txt"
if ./func_tests/scripts/comparator.sh "$output" "res.txt"; then
  exit 1
else
  exit 0
fi
