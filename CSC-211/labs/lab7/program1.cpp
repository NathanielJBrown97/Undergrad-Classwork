#include <iostream>

void square(int *num_to_be_squared)
{
    (*num_to_be_squared) *= (*num_to_be_squared);
}

int main()
{
    int num_to_be_squared = 4;

    square(&num_to_be_squared);
    std::cout << num_to_be_squared << std::endl;
}