#include <iostream>
#include <string>

int main()
{
    std::string inputString;
    getline(std::cin, inputString);

    std::string outputString = "";

    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] != inputString[i + 1])
        {
            outputString += inputString[i];
        }
    }

    std::cout << outputString << std::endl;

    return 0;
}
