#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        long N;
        cin>>N;
        long W[N+1];
        long pos[N+1];
        int count = 0;
        long max = 0;
        long k = 0;
        int res = 0;
        for(long i = 0; i<N; i++){
            cin>>W[i];
            if(W[i]>max){
                count = 1;
                max = W[i];
                pos[k] = i;
                continue;
            }
            if(W[i]==max){
                pos[k] = i;
                k++;
                count++;
            }
        }
        for(long i = 0; i<N; i++){
            cout<<pos[i]<<endl;
        }
        
        long start = k-count;
        long end = k;
        for(long i=start; i<end; i++){
            cout<<pos[i]<<endl;
        }
    }
}