#!/bin/bash

input="$1"
args=$(cat "$2")
app="../../app.exe"
res="res.txt"
"$app" "$args" < "$input" > "$res"

exit $?
