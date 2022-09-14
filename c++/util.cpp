#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

// power
ll power(ll x, ll y, ll mod){
    if(y==0){
        return 1;
    }
    ll p = power(x, y/2, mod) % mod;
    p= (p*p)%mod;
    return (y&1? (p*x)%mod: p);
}
// Undirected Graph
class UnDirGraph
{
    vector<uint> *adj;
    uint V;

public:
    Graph(uint V)
    {
        this->V = V;
        adj = new vector<uint>[V];
    }
    void addEdge(uint u, uint v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
// directed Graph
class DirGraph
{
    vector<uint> *adj;
    uint V;

public:
    Graph(uint V)
    {
        this->V = V;
        adj = new vector<uint>[V];
    }
    void addEdge(uint u, uint v)
    {
        adj[u].push_back(v);
    }
};

// Combinatronics 
// Note: don't forget to initialize dp
ll dp[1][1];
ll nCr(ll n, ll k, ll mod){
    if(n<k){
        return 0;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    if(n==k){
        dp[n][k] = 1;
        return 1;
    }
    if(n==0){
        dp[n][k]=1;
        return 1;
    }
    return dp[n][k] = (nCr(n-1, k-1, mod)%mod + nCr(n-1, k, mod)%mod)%mod;
}
ll nCr(ll n, ll k){
    if(n<k){
        return 0;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    if(n==k){
        dp[n][k] = 1;
        return 1;
    }
    if(n==0){
        dp[n][k]=1;
        return 1;
    }
    return dp[n][k] = nCr(n-1, k-1) + nCr(n-1, k);
}

double I(double arr[], int N){
    double sum=0;
    for(int i = 0; i<N; i++){
        sum+=arr[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        double temp = arr[i]/sum;
        temp *= log2(temp);
        ans-=temp;
    }
    return ans;
}
int main(){
    double arr[] = {84, 42};
    cout<<I(arr, sizeof(arr)/sizeof(double));
}