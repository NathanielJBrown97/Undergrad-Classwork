#include <iostream>
#include <string>

int main()
{
    std::string our_input;
    int count = 0;

    std::getline(std::cin, our_input);

    bool unique_character[256] = {false};

    for (int i = 0; i < our_input.length(); i++)
    {
        if (!unique_character[(unsigned char)our_input[i]])
        {
            unique_character[(unsigned char)our_input[i]] = true;
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
