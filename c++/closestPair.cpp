#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
};
bool compareX(Point p1, Point p2)
{
    return p1.x <= p2.x;
}
bool compareY(Point p1, Point p2)
{
    return p1.y <= p2.y;
}
float dist(Point p1, Point p2)
{
    return sqrtf(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
float findMinDist(Point p[], int l, int r)
{
    float minDist = FLT_MAX;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            if (minDist > dist(p[i], p[j]))
            {
                minDist = dist(p[i], p[j]);
            }
        }
    }
    return minDist;
}
float _closest(Point p[], int l, int r)
{
    if (r - l <= 2)
    {
        return findMinDist(p, l, r);
    }
    else
    {
        int mid = l + (r - l) / 2;
        Point midPoint = p[mid];
        float distLeft = _closest(p, l, mid);
        float distRight = _closest(p, mid+1, r);
        float minDist = min(distLeft, distRight);

        vector<Point> fromMid;
        for (int i = l; i <= r; i++)
        {
            if (dist(midPoint, p[i]) < minDist)
            {
                fromMid.push_back(p[i]);
            }
        }
        sort(fromMid.begin(), fromMid.end(), compareY);
        float minFromMid = FLT_MAX;

        for (int i = 0; i < fromMid.size(); i++)
        {
            for (int j = i + 1; j < fromMid.size() && (p[j].y - p[i].y)<minFromMid; i++)
            {
                if (dist(p[i], p[j]) < minFromMid)
                {
                    minFromMid = dist(p[i], p[j]);
                }
            }
        }
        return min(minFromMid, minDist);
    }
}
float closest(Point p[], int n)
{
    sort(p, p + n, compareX);
    return _closest(p, 0, n - 1);
}
int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}
