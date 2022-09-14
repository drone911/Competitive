#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> *adj, vector<int> &visited){
    auto endItr = adj[s].end();
    for (auto it = adj[s].begin(); it !=endItr ; it++)
    {
        if(!visited[*it]){
            visited[*it] = visited[s]&1? 2: 1;
            dfs(*it, adj, visited);
        }
    }
}
int findMaxEdges(vector<int> *adj, int N){
    int cntEdges = 0;
    for (int i = 0; i < N; i++)
    {
        cntEdges+=adj[i].size();
    }
    cout<<cntEdges<<endl;
    vector<int> visited(N, 0);
    visited[0] = 1;
    dfs(1, adj, visited);
    for (int i = 0; i < N; i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<endl;
    int cnt1 = 0, cnt2= 0;
    for (int i = 0; i < N; i++)
    {
        if(visited[i]&1){
            cnt1++;
        }else{
            cnt2++;
        }
    }
    cout<<cnt1<<" "<<cnt2<<endl;
    return cnt1*cnt2 - cntEdges;
}
int main() 
{ 
    int n = 5; 
    vector<int> adj[n + 1]; 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(4); 
    adj[3].push_back(5); 
    cout << findMaxEdges(adj, n); 
    return 0; 
} 