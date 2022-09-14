#include <bits/stdc++.h>
using namespace std;

int nxt[] = {0, 1, -1};
int nextX, nextY;

void dfs(int **mat, int m, int n, int sX, int sY, int eX, int eY)
{
                    
    if (mat[sX][sY])
    {
        return;
    }
    mat[sX][sY] = 1;
    if (sX == eX && sY == eY)
    {
        return;
    }
    int i = 0, j ;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            nextX = sX + nxt[i];
            nextY = sY + nxt[j];
                
            if (nextX > 0 && nextX <= m && nextY > 0 && nextY <= n)
            {
                if (!mat[nextX][nextY])
                {
                    dfs(mat, m, n, nextX, nextY, eX, eY);
                }
            }
            j++;
        }
        i++;
    }
}
bool isPossible(int m, int n, int k, int r, vector<int> x, vector<int> y)
{
    int **mat = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        mat[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mat[i][j] = 0;
            for (int p = 0; p < k; p++)
            {
                if (sqrt(pow(x[p] - i, 2) + pow(y[p] - j, 2)) <= r || i == 0 || j == 0)
                {
                    mat[i][j] = 1;
                }
            }
        }
    }
    
    dfs(mat, m, n, 1, 1, m, n);
    if (mat[m][n] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    // Test case 1
    int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
    vector<int> X1 = {1, 3};
    vector<int> Y1 = {3, 3};
    if (isPossible(m1, n1, k1, r1, X1, Y1))
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;

    // Test case 2
    int m2 = 5, n2 = 5, k2 = 2, r2 = 1;
    vector<int> X2 = {1, 1};
    vector<int> Y2 = {2, 3};
    if (isPossible(m2, n2, k2, r2, X2, Y2))
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;

    return 0;
}