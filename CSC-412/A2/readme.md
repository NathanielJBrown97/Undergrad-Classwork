This is the repository for assignment 2; the purpose of this lab is to recreate the UNIX Demo. I wrote 7 individual C files that accomplish small tasks such as reading input and posting to standard output, breaking lines, converting to lowercase, checking for mismatched words, and identifying unique words. As well as scripts that compiled and ran these C files seperately. 

A build.sh bash script was used to compile all files at once and utilize a custom library located within a different working directory. The Unix Demo utilizes piping to properly run the C files in order passing their output along and ultimately dumping the manipulated data into a text output file.