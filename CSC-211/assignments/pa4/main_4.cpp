#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct Point
{
    double x, y;
    char color;
};

int main()
{
    // var for n and k and their input as per erquest.
    int n, k;
    std::cin >> n >> k;

    // vector for pair points
    std::vector<Point> points(n);
    // loop n times.
    for (int i = 0; i < n; i++)
    {
        // take input of points x, y, and color.
        std::cin >> points[i].x >> points[i].y >> points[i].color;
    }

    double px, py;
    std::cin >> px >> py;

    // vector for pair points distances
    std::vector<std::pair<double, char>> distances(n);
    for (int i = 0; i < n; i++)
    {
        double distance = std::sqrt(std::pow(points[i].x - px, 2) + std::pow(points[i].y - py, 2));
        distances[i] = std::make_pair(distance, points[i].color);
    }

    // sort the distances in ascending order
    std::sort(distances.begin(), distances.end());

    // red and blue count
    int r_count = 0, b_count = 0;
    // loop k times
    for (int i = 0; i < k; i++)
    {
        if (distances[i].second == 'R')
        {
            // count if red point
            r_count++;
        }
        else
        {
            // otherwise count blue
            b_count++;
        }
    }

    // output red or blue as per requireemnts.
    if (r_count > b_count)
    {
        std::cout << 'R' << std::endl;
    }
    else
    {
        std::cout << 'B' << std::endl;
    }

    return 0;
}
