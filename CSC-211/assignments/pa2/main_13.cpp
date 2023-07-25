#include <iostream>

int individual_digit_power(int current_digit, int digit_counter_exponent)
{
    int individual_value = 1;
    for (int current_exponent = 0; current_exponent < digit_counter_exponent; current_exponent++)
    {
        individual_value *= current_digit;
    }
    return individual_value;
}

int main()
{
    int is_it_armstrong;
    std::cin >> is_it_armstrong;

    if (is_it_armstrong < 0 || is_it_armstrong > 1000000000)
    {
        std::cin >> is_it_armstrong;
    }

    int digit_counter_exponent = 0;
    int goober_logic = is_it_armstrong;
    int double_goober_solution = is_it_armstrong;

    while (goober_logic != 0)
    {
        goober_logic /= 10;
        digit_counter_exponent++;
    }

    int sum = 0;
    while (is_it_armstrong != 0)
    {
        int current_digit = is_it_armstrong % 10;
        sum += individual_digit_power(current_digit, digit_counter_exponent);
        is_it_armstrong /= 10;
    }

    if (sum == double_goober_solution)
    {
        std::cout << "True";
    }
    else
    {
        std::cout << "False";
    }
}