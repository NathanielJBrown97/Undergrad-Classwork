#include <iostream>
// No need to touch the main.cpp file. However - if might be helpfull
// to look at how I'm using your soon-to-be defined Point.cpp class

class Point
{
public:
    int x, y, z;
}

main()
{

    Point myPt(10, 5, 8);
    Point myPt2(3, 10, 15);

    int myX = myPt.getX();

    std::cout << myX << std::endl;

    std::cout << myPt.toCord() << std::endl;

    myPt.setX(3);

    std::cout << myPt.toCord() << std::endl;

    std::cout << myPt.euDistance(myPt2) << std::endl;

    return 0;
}
