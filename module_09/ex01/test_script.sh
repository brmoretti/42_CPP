#!/bin/bash

file="./tests.txt"

set -f  # disable globbing

# Variable to keep track of whether the current line is a command or an expected result
is_command=true

# Read each line from the file
while IFS= read -r line; do
	if $is_command; then
		echo $line
		echo -n 'Result:   '
		eval "$line"
		is_command=false
	else
		echo 'Expected:' $line
		echo
		is_command=true
	fi
done < "$file"

set +f  # enable globbing
