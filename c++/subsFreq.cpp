#include<bits/stdc++.h>
#define MOD 10E9 + 7
#define LIM 500001
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

ll fact[LIM];
ll numInverse[LIM];
ll factInverse[LIM];
void initFact(ll n, ll mod){
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        fact[i] = (i*fact[i-1])%mod;
    }

}
void initNumInverse(ll n, ll mod){
    numInverse[0] = numInverse[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        numInverse[i] = numInverse[mod%i]*(mod - mod/i)%mod;
    }
}
void initFactInverse(ll n, ll mod){
    factInverse[0] = factInverse[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        factInverse[i] = (factInverse[i-1] * numInverse[i])%mod;
    }
}
ll nCr(ll n, ll r, ll mod){
    return (((fact[n]*factInverse[n-r])%mod)*factInverse[r])%mod;
}

uint A[LIM];
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    initFact(LIM, MOD);
    initNumInverse(LIM, MOD);
    initFactInverse(LIM, MOD);
    uint T, N, mx;
    cin>>T;
   
    while (T--)
    {
        unordered_map<uint, uint> freq;
        mx = 0;
        cin>>N;
        for (uint i = 0; i < N; i++)
        {
            cin>>A[i];
            freq[A[i]]++;
        }
        
        for (uint i = 1; i <= mx; i++)
        {
            
        }
        
    }
    
    return 0;
}
