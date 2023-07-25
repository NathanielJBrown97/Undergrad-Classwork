#include <iostream>
#include <string>

int main()
{
    std::string input_string;
    std::getline(std::cin, input_string);

    int hash_value = 0;
    for (char c : input_string)
    {
        hash_value += static_cast<int>(c);
    }

    std::cout << hash_value << std::endl;
    return 0;
}
