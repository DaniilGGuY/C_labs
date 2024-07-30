#!/bin/bash

count=0

for file in ./func_tests/data/*_in_a.txt; do
  if [[ "$file" =~ pos_[0-9][0-9]_in_a\.txt ]]; then
    echo Checking "$file"...
    num=$(echo "$file" | grep -o "[0-9][0-9]")
    output=$(find ./func_tests/data/ -name "pos_$num\_out\.txt")
    args=$(find ./func_tests/data/ -name "pos_$num\_args\.txt")
    if ./func_tests/scripts/pos_case.sh "$output" "$args"; then
      echo Test pos_"$num" is incorrect
      count=$((count+1))
    else
      echo All is OK
    fi
  elif [[ "$file" =~ neg_[0-9][0-9]_in_a\.txt ]]; then
    echo Checking "$file"...
    num=$(echo "$file" | grep -o "[0-9][0-9]")
    args=$(find ./func_tests/data/ -name "neg_$num\_args\.txt")
    if ./func_tests/scripts/neg_case.sh "$args"; then
      echo Test neg_"$num" incorrect
      count=$((count+1))
    else
      echo All is OK
    fi
  fi
done

echo Fails: "$count"
exit $count
