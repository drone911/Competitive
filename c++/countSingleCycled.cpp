#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<int> *adj;
    int N;
    vector<int> deg;
    public:
    Graph(int N){
        this->N = N;
        this->adj = new vector<int>[N+1];
        this->deg.reserve(N+1);
        for (int i = 0; i <= N; i++)
        {
            deg[i] = 0;
        }
        
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    void isSingleCycled(int u, vector<bool> &visited, bool &flag){
        if(deg[u] != 2){
            flag = true;
        }
        visited[u] = true;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if(!visited[*it]){
                isSingleCycled(*it, visited, flag);
            }
        }
    }
    int countSingleCycles(){
        int count = 0;
        vector<bool> visited(N+1, false);
        bool flag;
        for (int i = 1; i <= N; i++)
        {
            if(!visited[i]){
                flag = false;
                isSingleCycled(i, visited, flag);
                if(!flag){
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    Graph g(15);
    g.addEdge( 1, 10);  
    g.addEdge( 1, 5);  
    g.addEdge( 5, 10);  
    g.addEdge( 2, 9);  
    g.addEdge( 9, 15);  
    g.addEdge( 2, 15);  
    g.addEdge( 2, 12);  
    g.addEdge( 12, 15);  
    g.addEdge( 13, 8);  
    g.addEdge( 6, 14);  
    g.addEdge( 14, 3);  
    g.addEdge( 3, 7);  
    g.addEdge( 7, 11);  
    g.addEdge( 11, 6);  
    cout<<g.countSingleCycles();
}