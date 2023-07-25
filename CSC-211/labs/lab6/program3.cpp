#include <iostream>

bool palindrome(char the_string[])
{
    bool is_it_palindrome = false;
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
    if (reversed_string == the_string)
    {
        std::cout << "Is a palindrome.";
        is_it_palindrome = true;
    }
    else
    {
        std::cout << "Is not a palindrome.";
    }
    return is_it_palindrome;
}

int main()
{
    char the_string[] = "Another String";
    palindrome(the_string);
}