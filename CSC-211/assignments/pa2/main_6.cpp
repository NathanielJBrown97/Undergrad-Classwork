#include <iostream>
int suffix_sum()
{
    int number, how_many_elements_from_number, sum = 0;
    std::cin >> number >> how_many_elements_from_number;
    for (int i = number; i > number - how_many_elements_from_number; i--)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    std::cout << suffix_sum();
}