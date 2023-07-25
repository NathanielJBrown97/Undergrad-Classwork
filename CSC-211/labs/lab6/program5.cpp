#include <iostream>

void remove(char the_string[], char a)
{

    std::cout << "The original string is : " << the_string << std::endl;

    int length = 0;
    while (the_string[length] != '\0')
    {
        length++;
    }

    char new_string[length - 1];

    for (int i = 0; i < length; i++)
    {
        }
    std::cout << "The replaced string is: " << new_string << std::endl;
}

int main()
{
    char the_string[] = "Another String";
    char a = 'n';

    remove(the_string, a);
}