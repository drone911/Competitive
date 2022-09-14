#include <bits/stdc++.h>
using namespace std;

int sheeps[100][100];
int M, N;
void dfs(bool vis[100][100], int i, int j, int &cnt)
{
    vis[i][j] = true;
    if (sheeps[i][j])
    {
        cnt++;
        if (i + 1 < M && j + 1 < N)
        {
            if(!vis[i+1][j+1]){
                dfs(vis, i + 1, j + 1, cnt);         
            }
        }
        if (i + 1 < M)
        {
            if(!vis[i+1][j]){
                dfs(vis, i + 1, j , cnt);
            }
        }
        if (j + 1 < N)
        {
            if(!vis[i][j+1]){
                dfs(vis, i, j + 1, cnt);
            }
        }
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            if(!vis[i-1][j-1]){
                dfs(vis, i - 1, j - 1, cnt);
            }
        }
        
        if (i - 1 >= 0)
        {
            if(!vis[i-1][j]){
                dfs(vis, i - 1, j, cnt);
            }
        }
        if (j - 1 >= 0)
        {
           if(!vis[i][j-1]){
                dfs(vis, i , j -1, cnt);
            }
        }
        if (i - 1 >= 0 && j + 1 < N)
        {
           if(!vis[i-1][j+1]){
                dfs(vis, i - 1, j + 1, cnt);
            }
        }
        if (i + 1 < M && j - 1 >= 0)
        {
         if(!vis[i+1][j-1]){
                dfs(vis, i + 1, j - 1, cnt);
            }
        }
    }
}
int countSafeSheeps()
{
    int maxCnt = 0;
    bool vis[100][100];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vis[i][j] = false;
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cnt = 0;        
            if (sheeps[i][j] == 1)
            {
                if (!vis[i][j])
                {
                    dfs(vis, i, j, cnt);
                }
                maxCnt = max(cnt, maxCnt);
            }
        }
    }
    return maxCnt/2;
}
int main()
{
    cin >> M >> N;
    char temp;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            if (temp == 'S')
            {
                sheeps[i][j] = 1;
            }
            else
            {
                sheeps[i][j] = 0;
            }
        }
    }
    cout << countSafeSheeps() << endl;
}