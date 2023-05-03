#!/bin/bash

bin_name="fishttp"
compiler="gcc"
c_flags="-std=gnu99 -Wall -Wextra -pedantic"

$compiler $c_flags ./src/main.c ./src/fishttp.c -o $bin_name

if [ $1 == "run" ]; then
    ./$bin_name
fi
