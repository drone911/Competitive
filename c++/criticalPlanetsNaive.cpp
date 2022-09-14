#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

class Graph
{
    int N;
    vector<int> *adj;

public:
    Graph(int N)
    {
        this->N = N;
        adj = new vector<int>[N];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int i, bool visited[], int ignore)
    {
        if (i == ignore)
        {
            return;
        }
        visited[i] = true;
        auto end = adj[i].end();
        for (auto it = adj[i].begin(); it != end; it++)
        {
            if (!visited[*it])
            {
                dfs(*it, visited, ignore);
            }
        }
    }
    void critical()
    {
        bool visited[N];
        bool flag;
        for (int j = 0; j < N; j++)
        {
            flag = true;
            for (int i = 0; i < N; i++)
            {
                visited[i] = false;
            }
            if (j == 0)
            {
                dfs(1, visited, j);
            }
            else
            {
                dfs(0, visited, j);
            }
            for (int i = 0; i < N; i++)
            {
                if (!visited[i] && j != i)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag || adj[j].size() < 2)
            {
                cout << j << endl;
            }
        }
    }
};
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int M, N, u, v;
    cin >> M >> N;
    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.critical();

    return 0;
}
