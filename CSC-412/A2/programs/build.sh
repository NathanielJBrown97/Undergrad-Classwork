#! /usr/bin/env bash

### compile all c code in the current directory

### Hints:
### how do you get the current directory in bash?
### how do you store the output of variables in bash?


# store the current working directory through -print working directory
current_dir="$(pwd)"

# Check if there are any C files in the current directory
c_files=$(find "$current_dir" -maxdepth 1 -type f -name '*.c')

if [[ -z "$c_files" ]]; then
  # No C files found, print an error message to stderr
  echo "Oops, we found no C code in the directory: $current_dir" >&2
  exit 1
fi

# for each c_file in the current directory, with .c extension (* is wildcard character - matches any file)
for c_file in *.c; do
  # store a base_name variable which will remove hte .c from the files name
  base_name="${c_file%.c}"
  
  # store results:in library
  # find current directory variable, (searches for hte files in this directory) 
  # - name '*.h' restricts the search to header files
  # - grep searches lines in the file {} is placeholder for hte current_file.
  # - exec runs the grep command found and filled by find...
  libraries="$(find "$current_dir" -name '*.h' -exec grep -q "#include \"$base_name.h\"" {} \; -print)"
  
  #if the libraries are not empty
  if [[ -n "$libraries" ]]; then
    # compile with base name as executable, c_file as the program and appropriate libraries.
    gcc -o "$base_name" "$c_file" $libraries
  else
    ## compile just using base name and c file
    gcc -o "$base_name" "$c_file"
  fi
done
