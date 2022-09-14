#include <bits/stdc++.h>

using namespace std;

int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool checkMove(int x, int y, int m, int n)
{
    if (x >= 0 && y >= 0 && x < m && y < n)
    {
        return true;
    }
    return false;
}
bool backTrack(int **sol, int x, int y, int visited, int totalVertices, int M, int N)
{
    if (checkMove(x, y, M, N))
    {
        return false;
    }
    sol[x][y] = visited;
    visited++;
    if (visited == totalVertices)
    {
        return true;
    }
    for (int i = 0; i < 8; i++)
    {
        if (backTrack(sol, x + xMove[i], y + yMove[i], visited, totalVertices, M, N))
        {
            return true;
        }
    }
    sol[x][y] = -1;
    return false;
}

void printSoln(int **sol, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int N = 8, M = 8;
    int **sol = new int *[M];

    for (int x = 0; x < M; x++)
    {
        sol[x] = new int[N];

        for (int y = 0; y < N; y++)
        {
            sol[x][y] = -1;
        }
    }

    sol[0][0] = 0;
    int totalVertices = M * N;
    int visited = 1;
    if (backTrack(sol, 0, 0, visited, totalVertices, M, N))
    {
        printSoln(sol, M, N);
    }
    else
    {
        cout << "Not possible" << endl;
    }
}