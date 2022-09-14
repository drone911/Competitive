#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll T, P, H;
    cin>>T;
    
    while (T--)
    {
        cin>>H>>P;
        while (P>0 && H>0)
        {
            H-=P;
            P = floor(P/2.0);
        }
        if(H<=0){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        
    }
        
    return 0;
}
