#include <iostream>
#include <vector>

void find_highest(int *highestIndex, int number_of_values)
{
    int i = 0;
    std::vector<int> temporary_vector;
    while (i < number_of_values)
    {
        int current_val;
        std::cout << "Enter current iteration val: ";
        std::cin >> current_val;
        std::cout << std::endl;
        temporary_vector.push_back(current_val);
        i++;
    }
    int j = 0;
    while (j < number_of_values)
    {
        if (temporary_vector[j] > *highestIndex)
        {
            *highestIndex = temporary_vector[j];
        }
    }
}
int main()
{
    int highestIndex = 0;
    int number_of_values;
    std::cout << "Enter number of values to fill the array with" << std::endl;
    std::cin >> number_of_values;
    std::cout << std::endl;
    std::cout << "Okay; the array will be filled with " << number_of_values << " integers." << std::endl;
    find_highest(&highestIndex, number_of_values);
    std::cout << "The highest value in the array was " << highestIndex << std::endl;
}