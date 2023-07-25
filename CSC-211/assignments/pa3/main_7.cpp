#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
    int x, y;
};

int main()
{
    std::vector<Point> points;
    int x, y;
    while (std::cin >> x >> y)
    {
        points.push_back({x, y});
    }

    int n = points.size();
    int max_dist = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = static_cast<int>(sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2)));
            max_dist = std::max(max_dist, dist);
        }
    }

    std::cout << floor(max_dist) << std::endl;

    return 0;
}