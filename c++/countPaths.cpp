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
    void DFSUtil(int s, int d, int &count, vector<bool> &visited){
        visited[s]=true;
        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if(d==*it){
                count++;
            }
            else if(!visited[*it]){
                DFSUtil(*it, d, count, visited);
            }
        }
        
    }
    int countPaths(int s, int d) {
        if(s==d) {
            return 1;
        }
        int count = 0;
        vector<bool> visited(this->V, false);
        DFSUtil(s, d, count, visited);
        return count;
    }
};
int main() 
{ 
  
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
  
    int s = 0, d = 3; 
    cout << g.countPaths(s, d); 
  
    return 0; 
}