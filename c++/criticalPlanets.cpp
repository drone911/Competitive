#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

class Graph
{
    int N;
    vector<int> *adj;

public:
    Graph(int N)
    {
        this->N = N;
        adj = new vector<int>[N];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void APUtil(int i,int visited[]){
        visited[*it]++;
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if(visited[*it]==0){
                APUtil(*it, visited);
            }else{
                visited[*it]++;
            }
        }
        
    }
    void AP(){
        int parent[N];
        int visited[N];
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
        }
        APUtil(0, visited);    
        
        for (int i = 0; i < N; i++)
        {
            if(visited[i]<2){
                cout<<i<<endl;
            }
        }
        
    }
};
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int M, N, u, v;
    cin>>M>>N;
    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        cin>>u>>v;
        g.addEdge(u, v);
    }
    g.AP();
    
    return 0;
}
