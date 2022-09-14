#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
char dress[2001][2001];
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int N, M;
    ll count = 0;
    cin>>M>>N;
    count+=M*N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>dress[i][j];
        }
    }
    
    return 0;
}
