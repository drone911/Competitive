#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, t;
        long sum = 0;
        bool flag = false;
        cin>>N;
        long M = N;
        for(int i = 0; i<N; i++){
            cin>>t;
            if(t==0){
                M--;
            }
            sum+=t;
        }
        N=M;
        if(flag || sum<100 || sum>100+N-1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}