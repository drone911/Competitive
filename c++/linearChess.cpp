#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    int N;
    ll K;
    ll P;
    double div;
    ll lowestDiv;
    cin>>T;
    while (T--)
    {
        cin>>N>>K;
        lowestDiv = LLONG_MAX;
        for (int i = 0; i < N; i++)
        {
            cin>>P;
            if(K>=P){
                div = K/(double)P;
                if(div == floor(div)){
                    lowestDiv = min(lowestDiv, (ll)div);
                }
            }
        }
        if(lowestDiv == LLONG_MAX){
            cout<<-1<<endl;
        }else{
            cout<<K/lowestDiv<<endl;
        }
    }
        
    return 0;
}
