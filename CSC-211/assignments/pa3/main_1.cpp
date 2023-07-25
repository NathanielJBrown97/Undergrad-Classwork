#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Declare variables
    int num, firstNum, count = 0;
    std::vector<int> nums;

    // Get input from user
    while (std::cin >> num && nums.size() < 100)
    {
        nums.push_back(num);
        if (nums.size() == 1) // If this is the first number entered, store it as the first number to check for
        {
            firstNum = num;
        }
    }

    // Check if any numbers were entered
    if (nums.empty())
    {
        return 0;
    }

    // Count how many times the first number appears in the vector
    count = std::count(nums.begin(), nums.end(), firstNum);

    // Output the result
    std::cout << count;

    return 0;
}
