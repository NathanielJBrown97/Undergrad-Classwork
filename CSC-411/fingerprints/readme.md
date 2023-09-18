In this problem you are to write a program fgroups (short for “fingerprint
groups”), which when given a set of names with fingerprints will identify groups
of names that share a fingerprint. The real object of the exercise is to familiarize
you with some parts of the standard library.
Your input is always on standard input. Input is a sequence of lines where each
line has the following format:
• The line begins with one or more non-whitespace characters. This sequence
of characters is the fingerprint.
• The fingerprint is followed by one or more whitespace characters, not
including newline.
• The name begins with the next non-whitespace character and continues
through the next newline. A name may contain whitespace, but a name
never contains a newline.
– As an example of this, if a line of input is fingerprint this is my
name, then the resulting fingerprint would be fingerprint and the
resulting name would be this is my name.
For this part of the assignment, you may not use any external crates,
but can use anything in the standard library (std::)
Finally, you may also assume that each name appears at most once.
You may assume that a fingerprint is at most 512 characters long (2048 bits
represented in hexadecimal notation), but there is no a priori upper bound on
the length of a name. So, it’s easiest to allow fingerprints of arbitrary length.
