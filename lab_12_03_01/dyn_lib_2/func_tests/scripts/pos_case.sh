#!/bin/bash

output="$1"
args=$(cat "$2")
app="./app.exe $args"
param="$(echo "$args" | awk '{print $3}')"
$app
if ./func_tests/scripts/comparator.sh "$output" "$param"; then
  exit 1
else
  exit 0
fi
