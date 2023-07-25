#include <iostream>
int main()
{
    int grade ;
    std::cin >> grade ;

    if(grade > 96)
        {std::cout << "A+" ; }
    else if(grade > 92 && grade < 97)
        {std::cout << "A" ; }
    else if(grade > 89 && grade < 93)
        {std::cout << "A-" ; }
    else if(grade > 86 && grade < 89)
        {std::cout << "B+" ; }
    else if(grade > 82 && grade < 86)
        {std::cout << "B" ; }
    else if(grade > 79 && grade < 82)
        {std::cout << "B-" ; }
    else if(grade > 76 && grade < 79)
        {std::cout << "C+" ; }
    else if(grade > 72 && grade < 76)
        {std::cout << "C" ; }
    else if(grade > 69 && grade < 72)
        {std::cout << "C-" ; }
    else if(grade > 67 && grade < 69)
        {std::cout << "D+" ; }
    else if(grade > 64 && grade < 67)
        {std::cout << "D" ; }
    else
        {std::cout << "E/F" ; }

}