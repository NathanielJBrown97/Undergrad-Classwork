#!/bin/bash

# check if the correct number of arugments are provided; if not echo out error accordingly.
if [ $# -lt 2 ]; then
    echo "Usage: $0 <source> <num> [NUMS]"
    exit 1
fi

# Get the filename
filename=$1

# if the filename doesn't exist, echo error accordingly.
if [ ! -f "$filename" ]; then
    echo "Error: File \"$filename\" does not exist."
    exit 1
fi

# compile the c program as prog01
gcc -Wall -o prog01 "$filename"


# Function to check if a number is an integer between 0 and 20
is_valid_integer() {
    local num=$1
    if [[ "$num" =~ ^[0-9]+$ ]] && [ "$num" -ge 0 ] && [ "$num" -le 20 ]; then
        return 0
    else
        return 1
    fi
}

# Loop through the arguments and validate them
for ((i=2; i<=$#; i++)); do
    arg="${!i}"  # Get the argument at index i

    # Check if the argument is not a valid integer between 0 and 20
    if ! is_valid_integer "$arg"; then
        #if argument is 4 or larger, use the standard error output message.
        if [ "$i" -ge 4 ]; then
            echo "[bash] Error: Argument #$i is not an integer between 0 and 20." >&2
        #if it's special case #1, print second
        elif [ "$i" -eq 2 ]; then
            echo "[bash] Error: The second argument is not an integer between 0 and 20." >&2
        #else if its #2, print third
        elif [ "$i" -eq 3 ]; then
            echo "[bash] Error: The third argument is not an integer between 0 and 20." >&2
        fi
        exit 1
    fi
done

# Run the C program with the captured arguments
./prog01 "${@:2}"
