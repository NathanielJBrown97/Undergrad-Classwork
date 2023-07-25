#include <iostream>
#include <cmath>

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isCircularPrime(int number)
{
    // if not a prime number; return false.
    if (!isPrime(number))
    {
        return false;
    }
    // math stuff I had to google
    int digits = log10(number);
    int divisor = pow(10, digits);
    int rotation = number;

    // loop through the possible rotations of the digits
    for (int i = 0; i < digits; i++)
    {
        rotation = (rotation % 10) * divisor + rotation / 10;
        // checks each rotation to see if its prime, if not return false.
        if (!isPrime(rotation))
        {
            return false;
        }
    }
    // provided we make it to this point without returning false; number is circular prime i.e. true.
    return true;
}

int main()
{
    int number;
    std::cin >> number;
    std::cout << (isCircularPrime(number) ? "True" : "False") << std::endl;
    return 0;
}
