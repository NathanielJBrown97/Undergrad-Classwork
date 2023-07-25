#include <iostream>
#include <string>

bool palindrome(const std::string &our_string, int first_half, int second_half)
{
    // base - if the string is 0-1 length, it would automatically be a palindrome.
    if (first_half >= second_half)
    {
        return true;
    }
    // if the firsth half doesnt equal the second half return false
    else if (our_string[first_half] != our_string[second_half])
    {
        return false;
    }
    else
    {
        // otherwise - recall palindrome with positions incremented and decremented by 1
        return palindrome(our_string, first_half + 1, second_half - 1);
    }
}
// wrapper function to call pali with the full string as input
bool palindrome(std::string our_string)
{
    // index set to 0, and end of string index set to length of our string
    return palindrome(our_string, 0, our_string.length() - 1);
}

int main()
{
    std::string our_string;
    std::cout << "Enter word to check: ";
    std::getline(std::cin, our_string);
    if (palindrome(our_string))
    {
        std::cout << our_string << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << our_string << " is not a palindrome." << std::endl;
    }
    return 0;
}
