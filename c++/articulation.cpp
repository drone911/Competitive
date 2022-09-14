#include <bits/stdc++.h>
using namespace std;

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
    void APUtil(int i, int parent[], bool visited[], bool arti[], int disc[], int low[], int &time){
        visited[i] = true;
        disc[i] = time;
        low[i] = time;
        time++;
        int children = 0;
        for (vector<int>::const_iterator it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if(!visited[*it]){
                children++;
                parent[*it] = i;
                APUtil(*it, parent, visited, arti, disc, low, time);
                low[i] = min(low[i], low[*it]);
                if(parent[i]==-1 && children>1){
                    arti[i] = true;
                }
                if(parent[i]!=-1 && low[*it]>=disc[i]){
                    arti[i] = true;
                }
            }else if(parent[i] != *it){
                low[i] = min(low[i], disc[*it]);
            }
        }
        
    }
    void AP(){
        int parent[N];
        bool arti[N];
        bool visited[N];
        int disc[N];
        int low[N];
        for (int i = 0; i < N; i++)
        {
            parent[i] = -1;
            arti[i] = false;
            visited[i] = false;
        }
        int time = 0;
        for (int i = 0; i < N; i++)
        {
            if(!visited[i]){
                APUtil(i, parent, visited, arti, disc, low, time);
            }
        }
        for (int i = 0; i < N; i++)
        {
            if(arti[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
};
int main()
{
    // Create graphs given in above diagrams
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();

    return 0;
}