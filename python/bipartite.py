#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<int> *adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isBipartite()
    {
        vector<int> status(this->V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!status[i])
            {
                status[i] = 1;
                queue<int> Q;
                Q.push(i);
                while (!Q.empty())
                {
                    int curr = Q.front();
                    Q.pop();
                    for (auto it = adj[curr].begin(); it != adj[curr].end(); it++)
                    {
                        if (!status[*it])
                        {
                            status[*it] = status[curr] & 1 ? 2 : 1;
                            Q.push(*it);
                        }
                        else
                        {
                            if (status[*it] == status[curr])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
    Graph g = Graph(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    cout << g.isBipartite() << endl;
    g = Graph(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    cout << g.isBipartite() << endl;
    g = Graph(5);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << g.isBipartite() << endl;
    return 0;
}