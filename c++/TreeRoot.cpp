#include<bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int sum = 0;
        int temp1, temp2;
        for(int i=0;i<N;i++){
            cin>>temp1>>temp2;
            sum+=temp1-temp2;
        }
        cout<<sum<<endl;
    }

    return 0;
}