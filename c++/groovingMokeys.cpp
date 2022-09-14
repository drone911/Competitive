#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int N;
    vector<int> *adj;
    Graph(int N)
    {
        this->N = N;
        adj = new vector<int>[N];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void printGraph(vector<int> adj[], int V)
    {
        for (int v = 0; v < V; ++v)
        {
            cout << "\n Adjacency list of vertex "
                 << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            printf("\n");
        }
    }
};

int dfs(int i, int cnt, Graph &g, vector<bool> &visited)
{
    if (visited[i])
    {
        return cnt;
    }
    visited[i] = true;
    return dfs(g.adj[i][0], cnt + 1, g, visited);
}
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
int lcm(vector<int> &toLcm, int N)
{
    if (N < 1)
    {
        return toLcm[0];
    }
    else
    {
        int lcm = (toLcm[0] * toLcm[1]) / gcd(toLcm[0], toLcm[1]);
        for (int i = 2; i < N; i++)
        {
            lcm = (toLcm[i] * lcm) / gcd(toLcm[i], lcm);
        }
        return lcm;
    }
}
int main()
{
    int N;
    cin >> N;
    Graph g = Graph(N);
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        temp--;
        g.addEdge(i, temp);
    }
    g.printGraph(g.adj, g.N);
    vector<bool> visited(N, false);
    int cnt;
    vector<int> toLcm;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {

            cnt = 0;
            cnt = dfs(i, cnt, g, visited);
            toLcm.push_back(cnt);
        }
    }
    cout << lcm(toLcm, toLcm.size()) << endl;
}