#!/bin/bash

input="$1"
"./convert.exe" "t" "$input" "./../data/test.bin"
args=$(cat "$2")
app="../../app.exe $args"
$app

exit $?
