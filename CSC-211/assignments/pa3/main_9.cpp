#include <iostream>
#include <string>
#include <algorithm>

// function to impliment the rules of a proper email; passed an email address
std::string normalizeGmail(const std::string &address)
{
    // variable for return of normalized gmail
    std::string result;
    // ignore flag starts at false
    bool ignore = false;
    // for character's in the address
    for (char c : address)
    {
        // if @ symbol, append the rest of address
        if (c == '@')
        {
            result += address.substr(address.find('@'));
            break;
        }
        // if + symbol, ignore flag until reaching @
        else if (c == '+')
        {
            ignore = true;
        }
        // if . symbol && not currently ignoring, append
        else if (!ignore && c != '.')
        {
            result += std::tolower(c);
        }
    }
    return result;
}

int main()
{
    // define two emails
    std::string email1, email2;
    // collect two emails.
    std::cin >> email1 >> email2;

    // bool var = calling the normalize function passed each of the emails. Value depends on if they are equal to one another.
    bool sameGmail = normalizeGmail(email1) == normalizeGmail(email2);
    // output as per request
    std::cout << (sameGmail ? "True" : "False") << std::endl;

    return 0;
}

// EARLY DEAD VERSION BELOW
//  #include <iostream>
//  #include <string>
//  #include <algorithm>

// std::string normalize_address(std::string address)
// {
//     // conditional symbols
//     char plus_symbol = '+';
//     char at_symbol = '@';
//     char dot_symbol = '.';

//     // bool to track if they exist.
//     bool is_there_plus = false;
//     bool is_there_at = false;
//     bool is_there_dot = false;

//     // positions of conditional symbols
//     int position_of_plus = -1;
//     int position_of_at = -1;

//     // loop to search for plus symbol - if so: update bool / position.
//     for (int i = 0; i < address.length(); i++)
//     {
//         if (address[i] == plus_symbol)
//         {
//             is_there_plus = true;
//             position_of_plus = i;
//         }
//     }

//     // loop to search for @ symbol - if so: update bool and position.
//     for (int i = 0; i < address.length(); i++)
//     {
//         if (address[i] == at_symbol)
//         {
//             is_there_at = true;
//             position_of_at = i;
//             break; // exit loop once @ symbol is found
//         }
//     }

//     // delete all . within string.
//     address.erase(std::remove(address.begin(), address.end(), dot_symbol), address.end());

//     // remove the ignored section of email
//     if (is_there_plus && is_there_at)
//     {
//         address.erase(position_of_plus, position_of_at - position_of_plus + 1);
//     }

//     // convert remainder to lowercase for final bool round
//     for (char &c : address)
//     {
//         c = std::tolower(c);
//     }

//     return address;
// }

// bool are_they_the_same(std::string address1, std::string address2)
// {
//     if (address1 == address2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {
//     std::string address_input, compare_address;
//     std::cin >> address_input;
//     std::cin >> compare_address;

//     std::cout << "Address 1: " << address_input << std::endl;
//     std::cout << "Address 2: " << compare_address << std::endl;

//     std::cout << "Normalized address 1: " << normalize_address(address_input) << std::endl;
//     std::cout << "Normalized address 2: " << normalize_address(compare_address) << std::endl;

//     std::cout << "Verdict: " << std::boolalpha << are_they_the_same(normalize_address(address_input), normalize_address(compare_address)) << std::endl;

//     return 0;
// }
