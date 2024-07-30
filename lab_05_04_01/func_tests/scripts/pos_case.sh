#!/bin/bash

input="$1"
"./convert.exe" "t" "$input" "./../data/test.bin"
output="$2"
args=$(cat "$3")
app="../../app.exe $args"
param=$(echo "$args" | awk '{print $1}')
if [ "$param" == "sb" ]; then
  $app > "res.txt"
  if ./comparator.sh "$output" "res.txt"; then
    exit 1
  else
    exit 0
  fi
elif [ "$param" == "ft" ]; then
  $app > "res.txt"
  if  ./comparator.sh "./../data/test.txt" "$output"; then
    exit 1
  else
    exit 0
  fi
else
  echo "ERROR COMPARE RES"
fi
