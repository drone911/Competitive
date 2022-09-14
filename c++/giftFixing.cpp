#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull A[51];
ull B[51];
inline ull checkAndReturn(ull A, ull B){
    return A>B? A-B:0;
}
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    int N;
    cin>>T;
    while (T--)
    {
        cin>>N;
        ull minA = ULLONG_MAX, minB = ULLONG_MAX;
        ull moves = 0;
        for (int i = 0; i < N; i++)
        {
            cin>>A[i];
            minA = min(minA, A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            cin>>B[i];
            minB = min(minB, B[i]);
        }
        for (int i = 0; i < N; i++)
        {
            moves += checkAndReturn(A[i],minA) + checkAndReturn(B[i], minB) - min(checkAndReturn(A[i],minA) ,checkAndReturn(B[i], minB));
        }
        cout<<moves<<endl;
    }
    
    return 0;
}
