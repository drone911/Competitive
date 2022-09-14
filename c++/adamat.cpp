#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
int mat[64][64];

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
            for (uint j = 0; j < N; j++)
            {
                cin>>mat[i][j];
            }
        }
        uint count = 0;
        bool lastCmp = mat[0][N-1]==N;
        if(!lastCmp){
            count++;
        }
        bool cmp;
        for (uint i = N-2; i > 0; i--)
        {
            cmp = mat[0][i]==i+1;
            if(cmp != lastCmp){
                count++;
            }
            lastCmp = cmp;
        }
        cout<<count<<endl;
    }
    
    return 0;
}
