#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int countBits(long N){
    int count = 0;
    while(N>0){
        count+=N&1;
        N/=2;
    }
    return count;
}

int main(){
    fast;
    int T;
    cin>>T;
    while(T--){
        long N, Q, P;
        cin>>N>>Q;
        long a[N+1];
        long evenCount=0, oddCount=0;
        for(long i = 0; i<N; i++){
            cin>>a[i];
            if(countBits(a[i])%2){
                oddCount++;
            }
            else{
                evenCount++;
            }
        }
        while(Q--){
            cin>>P;
            if(countBits(P)%2){
                cout<<oddCount<<" "<<evenCount<<"\n";
            }else{
                cout<<evenCount<<" "<<oddCount<<"\n";
            }
        }
    }

}
