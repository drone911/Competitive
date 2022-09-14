#include <bits/stdc++.h>
#define MAXN 300
using namespace std;

vector<int> tree[MAXN];
vector<int> centroidTree[MAXN];

void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}
void dfs(int start, vector<bool> &visited, vector<int> &count)
{
    visited[start] = true;
    int cnt = 0;
    for (auto it = tree[start].begin(); it != tree[start].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(*it, visited, count);
            cnt += count[*it];
        }
    }
    count[start] += cnt;
}
int getCentroid(int start, vector<int> count, int n)
{
    //visited[start] = true;
    int maxCnt = n - count[start];
    int nextNode;
    for (auto it = tree[start].begin(); it != tree[start].end(); it++)
    {
        
    }
    return 0;
}
void decomposeTree(int start, int n)
{
    int N = n + 1;
    vector<bool> visited(N, false);
    vector<int> count(N, 1);
    dfs(start, visited, count);
    // find first centroid
    for (int i = 1; i < count.size(); i++)
    {
        cout<<i<<": "<<count[i]<<endl;
    }
    
    fill(visited.begin(), visited.end(), false);
    //int centroid = getCentroid(start, visited, count, n);
}
int main()
{
    int n = 16;

    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(7, 9);
    addEdge(6, 10);
    addEdge(10, 11);
    addEdge(11, 12);
    addEdge(11, 13);
    addEdge(12, 14);
    addEdge(13, 15);
    addEdge(13, 16);

    decomposeTree(1, n);

    return 0;
}