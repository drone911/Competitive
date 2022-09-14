#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T;
    uint C, R;
    uint dC, dR;
    cin>>T;
    while (T--)
    {
        cin>>C>>R;
        dC = ceil(C/9.0f);
        dR = ceil(R/9.0f);
        if(dC<dR){
            cout<<0<<" "<<dC<<endl;
        }else{
            cout<<1<<" "<<dR<<endl;
        }
    }
    
    return 0;
}
