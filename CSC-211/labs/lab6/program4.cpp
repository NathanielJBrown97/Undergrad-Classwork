#include <iostream>

void palindrome(char the_string[])
{
    std::cout << "The original string was: " << the_string << std::endl;

    int length = 0;
    while (the_string[length] != '\0')
    {
        length++;
    }
    char reversed_string[length];

    int reversed_iterator = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        reversed_string[reversed_iterator] = the_string[i];
        reversed_iterator++;
    }

    std::cout << "The reversed string was: " << reversed_string << std::endl;
}

int main()
{
    char the_string[] = "Another String";
    palindrome(the_string);
}