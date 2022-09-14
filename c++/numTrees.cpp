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
    void DFSUtil(int s, vector<bool> &visited){
        visited[s]=true;
        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if(!visited[*it]){
                DFSUtil(*it, visited);
            }
        }
    }
    int numTrees() {
        int count = 0;
        vector<bool> visited(this->V, false);
        for (int i = 0; i < this->V; i++)
        {
            if(!visited[i]){
                count++;
                DFSUtil(i, visited);
            }
        }
        return count;
    }
    
};
int main() 
{ 
  
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1);
    g.addEdge(2, 3);  
    cout << g.numTrees(); 
  
    return 0; 
}