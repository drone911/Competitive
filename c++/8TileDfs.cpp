#include <bits/stdc++.h>
#define printSpace cout << "=========================" << endl
using namespace std;

void printMat(int mat[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int moveX[] = {0, 1, -1, 0};
int moveY[] = {1, 0, 0, -1};
int goalMat[][3] = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
bool reachedGoalState(int mat[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (mat[i][k] != goalMat[i][k])
            {
                return false;
            }
        }
    }
    return true;
}
bool isLegal(int mat[][3], int i, int j, int move, int prevMove)
{
    return (i >= 0 && i < 3 & j >= 0 && j < 3 && move != 3 - prevMove);
}
bool isWithinBounds(int mat[][3], int i, int j)
{
    return (i >= 0 && i < 3 & j >= 0 && j < 3);
}
void swapVal(int mat[][3], int x, int y, int nextX, int nextY)
{
    int temp = mat[x][y];
    mat[x][y] = mat[nextX][nextY];
    mat[nextX][nextY] = temp;
}
bool dfsUtil(int mat[][3], int x, int y, int prevMove, int count, int depth)
{
    cout<<depth<<endl;
    printMat(mat);
    if (reachedGoalState(mat))
    {
        return true;
    }
    count++;
    if (count > 1000)
    {
        throw count;
    }
    int nextX, nextY;
    for (int i = 0; i < 3; i++)
    {
        nextX = x + moveX[i];
        nextY = y + moveY[i];
        if (isLegal(mat, nextX, nextY, i, prevMove))
        {
            swapVal(mat, x, y, nextX, nextY);
            if (dfsUtil(mat, nextX, nextY, i, count, depth+1))
            {
                return true;
            }else{
                swapVal(mat, x, y, nextX, nextY);
            }
            
        }
    }
    printSpace;
    return false;
}

bool dfs(int mat[][3], int x, int y)
{
    printMat(mat);
    printSpace;
    if (reachedGoalState(mat))
    {
        return true;
    }
    int nextX, nextY;
    for (int i = 0; i < 3; i++)
    {
        nextX = x + moveX[i];
        nextY = y + moveY[i];
        if (isWithinBounds(mat, nextX, nextY))
        {
            swapVal(mat, x, y, nextX, nextY);
            if (dfsUtil(mat, nextX, nextY, i, 0, 0))
            {
                cout << "solution Found" << endl;
                return true;
            }else{
                swapVal(mat, x, y, nextX, nextY);
            }
            
        }
    }
    printSpace;
    return false;
}
int main()
{
    int mat[][3] = {
        {-1, 8, 2}, {1, 4, 3}, {7, 6, 5}};
    try
    {
        dfs(mat, 1, 0);
    }
    catch (...)
    {
        cout << "dfs went into infinite loop" << endl;
    }

    return 0;
}