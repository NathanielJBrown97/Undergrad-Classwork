#include <iostream>
#include <string>

int main()
{
    // input string variable
    std::string input_string;
    // store input into variable
    std::getline(std::cin, input_string);

    // variable for output string
    std::string output_string;

    // for each character in the input
    for (char c : input_string)
    {
        // if it is the arrow symbol
        if (c == '<')
        {
            // keep removing characters from the output string until the previous character was not an arrow
            while (!output_string.empty() && output_string.back() == '<')
            {
                output_string.pop_back();
            }
            // remove the last non-arrow character from the output string
            if (!output_string.empty())
            {
                output_string.pop_back();
            }
        }
        // otherwise
        else
        {
            // add current character to the output string.
            output_string += c;
        }
    }

    // output the string
    std::cout << output_string << std::endl;

    return 0;
}
