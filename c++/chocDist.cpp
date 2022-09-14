#include <bits/stdc++.h>
typedef long long ll;
#define MAX 10000001
using namespace std;

ll A[MAX];
int main(){
    int T;
    ll N, M;
    cin>>T;
    while (T--)
    {
        cin>>N;
        for (ll i = 0; i < N; i++)
        {
            cin>>A[i];
        }
        cin>>M;
        sort(A, A+N);
        ll minDiff = LLONG_MAX;
        ll i = 0;
        while (i+M-1<N)
        {
            if(A[i+M-1] - A[i]<minDiff){
                minDiff = A[i+M-1] - A[i];
            }
            i++;
        }
        cout<<minDiff<<endl;
    }
    
}