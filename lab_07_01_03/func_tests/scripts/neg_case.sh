#!/bin/bash

args=$(cat "$1")
app="./app.exe $args"
$app

exit $?
