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
    int BFS(int s, int level) {
        vector<bool> visited(this->V, false);
        queue<int> Q;
        Q.push(s);
        int levelAt[V];
        levelAt[s] = 0;
        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();
            visited[curr] = true;
            for (auto it = adj[curr].begin(); it < adj[curr].end(); it++)
            {
                if(!visited[*it]) {
                    Q.push(*it);
                    levelAt[*it] = levelAt[curr]+1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < this->V; i++)
        {
            if(levelAt[i]==level){
                count++;
            }
        }
        
        return count;
    }
};

int main()
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 1; 
  
    cout << g.BFS(0, level); 
  
    return 0; 
}