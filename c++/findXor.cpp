#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
uint arr[1000001];
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N;
    cin>>T;
    while (T--)
    {
        cin>>N;
        for (uint i = 0; i < N; i++)
        {
            cin>>arr[i];
        }
        int i = 0;
        int toXor = 4294967294;
        while (i<20)
        {
            
            toXor = toXor<<1;
            i++;
        }
        
    }
    
    return 0;
}
