// Signed can be negative --- unsigned cannot be negative.

#include <iostream>

int main()
{
    char the_string[] = "Hello, World!";
    unsigned int string_len(char the_string[]);

    int length = 0;
    while (the_string[length] != '\0')
    {
        length++;
    }
    std::cout << "The length of the string is ..." << length;
}