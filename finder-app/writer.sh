#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Both arguments must be specified"
    exit 1
fi

writefile="$1"
writestr="$2"

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Failed to create file $writefile"
    exit 1
fi
