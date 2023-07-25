#include <iostream>
#include <cstring>

bool palindrome(char the_string[])
{
    bool is_it_palindrome = false;

    // Remove non-alphanumeric characters from the input string
    int j = 0;
    for (int i = 0; the_string[i] != '\0'; i++)
    {
        if (isalnum(the_string[i]))
        {
            the_string[j] = toupper(the_string[i]);
            j++;
        }
    }
    the_string[j] = '\0';

    // Compare the original string with its reversed version
    int length = strlen(the_string);
    char reversed_string[length];

    int reversed_iterator = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        reversed_string[reversed_iterator] = toupper(the_string[i]);
        reversed_iterator++;
    }
    reversed_string[length] = '\0';

    if (strcmp(reversed_string, the_string) == 0)
    {
        is_it_palindrome = true;
    }
    return is_it_palindrome;
}

int main()
{
    char the_string[100];
    std::cin.getline(the_string, 100);
    if (palindrome(the_string))
    {
        std::cout << "True";
    }
    else
    {
        std::cout << "False";
    }
    return 0;
}
