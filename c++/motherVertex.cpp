#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    vector<int> *adj;
    public:
    Graph(int v){
        this->V = v;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void DFSUtil(int v, vector<bool> &visited){
        visited[v]=true;
        for(auto it = adj[v].begin(); it!=adj[v].end(); ++it){
            if(!visited[*it]){
                DFSUtil(*it, visited);
            }
        }
    }
    int findMother() {
        int mother;
        vector<bool> visited(this->V, false);

        for(int i =0;i<V; i++) {
            if(!visited[i]) {
                DFSUtil(i, visited);
                mother = i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        DFSUtil(mother, visited);

        for(int i = 0;i<V; i++) {
            if(!visited[i]){
                return -1;
            }
        }
        return mother;
    }
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother(); 
  
    return 0; 
} 