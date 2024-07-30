#!/bin/bash

args=$(cat "$1")
app="$args"
$app > "res.txt"

exit $?
