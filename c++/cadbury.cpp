#include <bits/stdc++.h>
#define MAX 1502
using namespace std;

int chocs[MAX][MAX] = {-1};

int count(int i, int j)
{
    if (i == 1)
    {
        return j;
    }
    else if (j == 1)
    {
        return i;
    }
    else if (i == j)
    {
        return 1;
    }
    else if (chocs[i][j] != -1)
    {
        if (i > j)
        {
            chocs[i][j] = 1 + count(i - j, j);
        }
        else
        {
            chocs[i][j] = 1 + count(i, j - i);
        }
        return chocs[i][j];
    }else{
        return chocs[i][j];
    }
}
int main()
{
    int P, Q, R, S;
    cin >> P >> Q >> R >> S;
    int bachhas = 0;
    for (int i = P; i <= Q; i++)
    {
        for (int j = R; j <= S; j++)
        {
            bachhas += count(i, j);
        }
    }
    cout << bachhas << endl;
    return 0;
}