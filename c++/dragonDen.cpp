#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N, Q;
    cin>>N>>Q;
    ll height[N];
    ll spice[N];
    for (ll i = 0; i < N; i++)
    {
        cin>>height[i];
    }
    for (ll i = 0; i < N; i++)
    {
        cin>>spice[i];
    }
    int type;
    ll start, end;
    ll pos, newSpice;
    for (ll i = 0; i < Q; i++)
    {
        cin>>type;
        if(type==1){
            cin>>pos>>newSpice;
            spice[pos-1] = newSpice;
        }else{
            cin>>start>>end;
            start--;
            end--;
            
        }
    }
    
    
    return 0;
}
