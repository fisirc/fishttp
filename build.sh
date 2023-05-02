#!/bin/bash

bin_name="fishttp"

gcc -Wall -Wextra -pedantic ./src/main.c ./src/fishttp.c -o $bin_name

if [ $1 == "run" ]; then
    ./$bin_name
fi
