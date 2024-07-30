#!/bin/bash

output="$1"
args=$(cat "$2")
$args
param="$(echo "$args" | awk '{print $2}')"
if [ "$param" == "o" ]; then
  file="$(echo "$args" | awk '{print $4}')"
  if ./func_tests/scripts/comparator.sh "$output" "$file"; then
    exit 1
  else
    exit 0
  fi
else
  file="$(echo "$args" | awk '{print $5}')"
  if ./func_tests/scripts/comparator.sh "$output" "$file"; then
    exit 1
  else
    exit 0
  fi
fi