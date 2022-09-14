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
    bool DFSUtil(int v, vector<bool> &visited, vector<int> &vDegree, int k)
    {
        visited[v] = true;
        for (auto it = adj[v].begin(); it < adj[v].end(); ++it)
        {
            if (vDegree[v] < k)
            {
                vDegree[*it]--;
            }
            if (!visited[*it])
            {
                if (DFSUtil(*it, visited, vDegree, k))
                {
                    vDegree[v]--;
                }
            }
        }
        return (vDegree[v] < k);
    }
    void printKCores(int k)
    {
        vector<int> vDegree(V);
        int mindeg = INT_MIN;
        int startvertex;
        for (int i = 0; i < this->V; i++)
        {
            vDegree[i] = adj[i].size();

            if (vDegree[i] < mindeg)
            {
                mindeg = vDegree[i];
                startvertex = i;
            }
        }
        vector<bool> processed(V, false);
        
        for (int i = 0; i < this->V; i++)
        {
            if(!processed[i]&&vDegree[i]<k){
                vector<bool> visited(V, false);    
                DFSUtil(i, visited, processed,vDegree, k);
            }
            
        }
        for (int i = 0; i < this->V; i++)
        {
            if (vDegree[i] >= k)
            {
                cout << i << "-> ";
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    if (vDegree[*it] >= k)
                    {
                        cout << *it << " ";
                    }
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);

    cout << endl
         << endl;

    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);
    g2.printKCores(k);

    return 0;
}