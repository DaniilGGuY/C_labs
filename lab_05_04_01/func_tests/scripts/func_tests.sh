#!/bin/bash

count=0

gcc -std=c99 -o convert.exe converter.c
for file in ./../data/*_in.txt; do
  if [[ "$file" =~ pos_[0-9][0-9]_in\.txt ]]; then
    echo Checking "$file"...
    num=$(echo "$file" | grep -o "[0-9][0-9]")
    output=$(find ./../data/ -name "pos_$num\_out\.txt")
    args=$(find ./../data/ -name "pos_$num\_args\.txt")
    if ./pos_case.sh "$file" "$output" "$args"; then
      echo Test pos_"$num" is incorrect
      count=$((count+1))
    else
      echo All is OK
    fi
  elif [[ "$file" =~ neg_[0-9][0-9]_in\.txt ]]; then
    echo Checking "$file"...
    num=$(echo "$file" | grep -o "[0-9][0-9]")
    args=$(find ./../data/ -name "neg_$num\_args\.txt")
    if ./neg_case.sh "$file" "$args"; then
      echo Test neg_"$num" incorrect
      count=$((count+1))
    else
      echo All is OK
    fi
  fi
done

echo Fails: "$count"
exit $count
