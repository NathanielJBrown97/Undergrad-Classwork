#include <iostream>
void replace(char the_string[], char a, char b)
{
    std::cout << "The original string is : " << the_string << std::endl;

    int length = 0;
    while (the_string[length] != '\0')
    {
        length++;
    }

    for (int i = 0; i < length; i++)
    {
        if (the_string[i] == a)
        {
            the_string[i] = b;
        }
    }
    std::cout << "The replaced string is: " << the_string << std::endl;
}

int main()
{
    char a = 'n';
    char b = 'b';
    char the_string[] = "Another String";
    replace(the_string, a, b);
}