#!/bin/bash

arr1=()
arr2=()

IFS=' '
digit="^[+-]?[0-9]+([.][0-9]+)?$"

while read -r -a arr; do
  for i in "${arr[@]}"; do
    if [[ $i =~ $digit ]]; then
      arr1+=("$i")
    fi
  done
done < "$1"

while read -r -a arr; do
  for i in "${arr[@]}"; do
    if [[ $i =~ $digit ]]; then
      arr2+=("$i")
    fi
  done
done <"$2"

if [[ "${arr1[*]}" == "${arr2[*]}" ]]; then
  exit 0
else
  exit 1
fi
