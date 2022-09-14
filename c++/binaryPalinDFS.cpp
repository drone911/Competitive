#include<bits/stdc++.h>

using namespace std;

void dfs(int s, vector<int> &ans,set<int> *adj){
    ans[s] = 1;
    for(auto i = adj[s].begin(); i!=adj[s].end(); i++) {
        if(!ans[*i]){
            dfs(*i, ans, adj);
        }
    }
}
void printBinaryPalindrome(int n, int k) {
    vector<int> v;
    set<int> adj[k];
    vector<int> ans(k, 0);
    for(int i = 0; i< n; i++) {
        v.push_back(i%k);
    }
    for(int i = 0; i<n/2 ; i++) {
        adj[v[i]].insert(v[n-1-i]);
        adj[v[n-1-i]].insert(v[i]);
    }
    dfs(0, ans, adj);
    
    for (int i = 0; i < n; i++)
    {
        cout<<ans[v[i]];
    }
    cout<<endl;
}
int main() {
    int n = 10, k = 4; 
    printBinaryPalindrome(n, k); 
    return 0; 
}