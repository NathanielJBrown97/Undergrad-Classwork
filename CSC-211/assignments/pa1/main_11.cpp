#include <iostream>
#include <string>
int main() 
{
    int month , day , year ;
    std::string spelledMonth ;
    std::cin >> month ;
    if (month < 1 || month > 12)
        { std::cout << "Imaginary month"; }
    std::cin >> day ;
    std::cin >> year ;

    switch (month) {
        case 1:
            spelledMonth = "January" ;
            break;
        case 2:
            spelledMonth = "February" ;
            break;
        case 3: 
            spelledMonth = "March" ;
            break;
        case 4:
            spelledMonth = "April" ;
            break; 
        case 5:
            spelledMonth = "May" ;
            break;
        case 6:
            spelledMonth = "June" ;
            break;
        case 7:
            spelledMonth = "July" ;
            break;
        case 8:
            spelledMonth = "August" ;
            break;
        case 9:
            spelledMonth = "September" ;
            break;
        case 10:
            spelledMonth = "October" ;
            break;
        case 11:
            spelledMonth = "November" ;
            break;
        case 12:
            spelledMonth = "December" ;
            break;
    }

    std::cout << spelledMonth << " " << day << ", " << year ;

}