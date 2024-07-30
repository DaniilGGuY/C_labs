#!/bin/bash

if cmp -s "$1" "$2" ; then
  exit 0
fi
exit 1

