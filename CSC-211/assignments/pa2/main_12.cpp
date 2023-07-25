#include <iostream>
#include <iomanip>

int main()
{
    int r, g, b;
    std::cin >> r >> g >> b;
    if (r > 255 || r < 0)
    {
        std::cin >> r;
    }
    if (g > 255 || g < 0)
    {
        std::cin >> g;
    }
    if (b > 255 || b < 0)
    {
        std::cin >> b;
    }

    // using iomanip 'hex' and 'setfill' I can turn a headache, into 5 points on a minor assignment.
    std::cout << "#" << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << r << std::setw(2) << std::uppercase << g << std::setw(2) << std::uppercase << b << std::endl;
}