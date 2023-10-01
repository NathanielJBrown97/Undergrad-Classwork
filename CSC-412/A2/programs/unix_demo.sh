#! /usr/bin/env bash

### unix demo: watch 5:00 to 10:55
# https://www.youtube.com/watch?v=tc4ROCJYbm0&t=297s&ab_channel=AT%26TTechChannel

### recreate unix demo from video

# Update unix_dict_new_words.text with new words
#./mismatch >> unix_dict_new_words.text
# Run C programs and redirect output to unix_c_output.text
./sentence | ./makewords | ./lowercase | ./sort | ./unique | ./mismatch > unix_c_output.text

# Run Bash scripts and redirect output to unix_bash_output.text
./sentence.sh | ./makewords.sh | ./lowercase.sh | ./sort.sh | ./unique.sh | ./mismatch.sh > unix_bash_output.text

# Remove lines 2 and 4 from unix_c_output.text and overwrite the file
sed '2d;4d' unix_c_output.text > temp_unix_c_output.text
mv temp_unix_c_output.text unix_c_output.text

# Remove lines 2 and 4 from unix_bash_output.text and overwrite the file
sed '2d;4d' unix_bash_output.text > temp_unix_bash_output.text
mv temp_unix_bash_output.text unix_bash_output.text