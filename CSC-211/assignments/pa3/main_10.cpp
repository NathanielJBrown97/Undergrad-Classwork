#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    // value to store string, and for input of url
    std::string url;
    std::getline(std::cin, url);

    // Remove protocol (http/https)
    url.erase(0, url.find("://") + 3);

    // Remove subpages
    std::size_t found = url.find("/");
    if (found != std::string::npos)
    {
        url.erase(found);
    }

    // Remove port number
    found = url.find(":");
    if (found != std::string::npos)
    {
        url.erase(found);
    }

    // Convert to lowercase
    std::transform(url.begin(), url.end(), url.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    // Output
    std::cout << url << std::endl;

    return 0;
}
