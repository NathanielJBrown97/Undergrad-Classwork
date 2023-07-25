#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int numDays, i, leastDebris, todaysDebris;

    std::vector<int> debrisVector;

//    std::cout << "Num of Days Left" ;
    std::cin >> numDays ; //updates count to users input.
    
//    std::cout << "Enter " << numDays << " debris values..." ; //updates day count till end

// while i < days, add 1 to i... collected todays debrit input, pushback into debrisVector
   
    
    for ( i = 0 ; i < numDays ; i++ )   
    { 
        std::cin >> todaysDebris;
        debrisVector.push_back(todaysDebris);
    }

//variable, for distance from start of debrisVector, to the min_element of said vector.
    int waitDays = distance( debrisVector.begin() , min_element( debrisVector.begin() , debrisVector.end())); 

//    leastDebris = *min_element( debrisVector.begin() , debrisVector.end() );
    std::cout /*<< "Least Debris Value is " */ << waitDays;
//    std::cout << "You should wait" , waitDays , "days until launching."; //output how many days until the day of leastDebris


}