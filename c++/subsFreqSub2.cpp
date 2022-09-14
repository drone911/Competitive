#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

ll power(ll x, ll y, ll mod){
    if(y==0){
        return 1;
    }
    ll p = power(x, y/2, mod) % mod;
    p= (p*p)%mod;
    return (y&1? (p*x)%mod: p);
}
uint A[500001];
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N, mx;
    cin>>T;
    while (T--)
    {
        mx = 0;
        cin>>N;
        for (uint i = 0; i < N; i++)
        {
            cin>>A[i];
            mx = max(mx, A[i]);
        }
        
        for (uint i = 1; i <= N; i++)
        {
            cout<<power(2, N-i, MOD)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
