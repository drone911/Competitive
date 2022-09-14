#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int v)
    {
        this->V = v;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void DFSUtil(int start, int end, bool **tc)
    {   
        tc[start][end] = true;
        for (auto it = adj[end].begin(); it != adj[end].end(); ++it)
        {
            if (!tc[start][*it])
            {
                DFSUtil(start, *it, tc);
            }
        }
    }
    void transitiveClosure() {
        bool **tc = new bool*[V];
        for (int i = 0; i < this->V; i++)
        {
            tc[i] = new bool[V];
            memset(tc[i], false, sizeof(tc[i]));
        }
        for (int i = 0; i < this->V; i++)
        {
            DFSUtil(i, i, tc);
        }
        
        for (int i = 0; i < this->V; i++)
        {
            for (int j = 0; j < this->V; j++)
            {
                cout<<tc[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}