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
    }
    void dfs(int i, vector<bool> &visited, stack<int> &sort)
    {
        visited[i] = true;
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if(!visited[*it]){
                dfs(*it, visited, sort);
            }
        }
        sort.push(i);
    }
    void printTopology()
    {
        vector<bool> visited(this->V, false);
        stack<int> sort;
        for (int i = 0; i < this->V; i++)
        {
            if (!visited[i])
                dfs(i, visited, sort);
        }
        while (!sort.empty())
        {
            cout << sort.top();
            sort.pop();
        }
        cout<<endl;
    }
};
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.printTopology();
    return 0;
}