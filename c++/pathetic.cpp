#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


class Tree
{
public:
    int N;
    vector<int> *adj;
    Tree(int N)
    {
        this->N = N;
        adj = new vector<int>[N + 1];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
void dfs(int u, Tree &t, vector<int> &bipartite)
{
    auto end = t.adj[u].end();
    for (auto it = t.adj[u].begin(); it != end; it++)
    {
        if(!bipartite[*it]){
            bipartite[*it] = bipartite[u]==1?2:1;
            dfs(*it, t, bipartite);
        }
    }
    
}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    int T;
    int N;
    int temp1, temp2;
    cin >> T;
    int p[] ={ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    ll p1 = 1, p2 = 2;
    for (int i =  sizeof(p)/sizeof(int)-1; i >=0; i--)
    {
        if(p1>p2){
            p2*=p[i];
        }else{
            p1*=p[i];
        }
    }
    
    while (T--)
    {
        cin>>N;
        Tree t = Tree(N);
        for (int i = 1; i < N; i++)
        {
            cin>>temp1>>temp2;
            t.addEdge(temp1, temp2);
        }
        vector<int> bipartite(N+1, 0);
        bipartite[1] = 1;
        dfs(1, t, bipartite);
        for (int i = 1; i <= N; i++)
        {
            if(bipartite[i]&1){
                cout<<p1<<" ";
            }else{
                cout<<p2<<" ";
            }
        }
        cout<<endl;
    }
}