#include <bits/stdc++.h>
using namespace std;

void minSpacePreferLarge(int wall, int m, int n)
{
    int minWall = INT_MAX;
    int minM, minN;
    int p = 0;
    while (wall >= n)
    {
        int quot = wall / m;
        int rem = wall % m;
        if (rem <= minWall)
        {
            minM = quot;
            minN = p;
            minWall = rem;
        }
        p++;
        wall -= n;
    }
    cout<<minWall<<" "<<minM<<" "<<minN<<endl;
}
int main()
{
    int wall = 24, m = 3, n = 5;
    minSpacePreferLarge(wall, m, n);

    wall = 24, m = 4, n = 7;
    minSpacePreferLarge(wall, m, n);
    return 0;
}