#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N, temp;
    cin>>T;
    while (T--)
    {
        cin>>N;
        set<uint> heights;
        for (uint i = 0; i < N; i++)
        {
            cin>>temp;
            if(temp!=0){
                heights.insert(temp);
            }
        }
        cout<<heights.size()<<endl;
    }
    
    return 0;
}
