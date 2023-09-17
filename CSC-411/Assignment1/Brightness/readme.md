Part A of the A1 Assignment. 

Please write a Rust program brightness, which should print the average brightness of a grayscale image. Every pixel in a grayscale image has a brightness
between 0 and 1, where 0 is black and 1 is as bright as possible. Print the average
brightness using decimal notation with exactly one digit before the decimal point
and three digits after the decimal point. Print only the brightness.
The program takes at most one argument:
• If an argument is given, it should be the name of a portable graymap file
(in pgm format). You will want to use the csc411_image crate just like we
did in the pnmdata lab.
• If no argument is given, brightness reads from standard input, which
should contain a portable graymap.
• If more than one argument is given, brightness halts with an error message
(you can achieve this by using assert()).
• If a portable graymap is promised but not delivered, brightness should
halt with some sort of error message on stderr. (Any message will do,
but do print a message on standard error, and don’t produce anything on
standard output—especially not a senseless answer.)
For this part of the assignment, you are allowed (and expected) to
use the csc411_image crate.
This means that you’ll need to edit your Cargo.toml file to indicate the dependency on that crate:
[dependencies]
csc411_image = "0.3.1"
