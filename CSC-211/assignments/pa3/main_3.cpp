#include <iostream>
#include <cstring>

std::string reverse_string(char the_string[])
{
    // store length of original string
    int length = strlen(the_string);
    // new character array to store the reversed version of our string set to the length value +1 for the null terminator.
    char reversed_string[length + 1];

    // self explanatory
    int reversed_iterator = 0;
    // iterates through the_string from back to front.
    for (int i = length - 1; i >= 0; i--)
    {
        // moves the current iterations character of the original string; into the reversed string
        reversed_string[reversed_iterator] = the_string[i];
        // increment reversed iterator
        reversed_iterator++;
    }
    // add null term
    reversed_string[length] = '\0';

    // return reversed string for output
    return reversed_string;
}

int main()
{
    char the_string[100];
    // collect string to reverse
    std::cin.getline(the_string, 100);
    // calls function of reverse string passed the collected string to reverse
    std::cout << reverse_string(the_string);
}
